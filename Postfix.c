#include <stdio.h>
#include <stdlib.h>

/*编译初始化时候的定义声明*/
typedef struct StackRecord *Stack;
typedef char ElementType;//test data is char
struct StackRecord;
#define EmptyStack -1
/*functions*/
int ChangeSymbol(char Symbol);
int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void MakeEmpty(Stack S);
void Push(ElementType X,Stack S); 
void Pop(Stack S);
ElementType PopTop(Stack S);
ElementType Top(Stack S);
void GetData(Stack S); 
void DisposeStack(Stack S);


struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};

int main()
{
	int number=0;
	Stack S;
	printf("please input the number of the stack member:");
	scanf("%d",&number);
	S=CreateStack(number);
	printf("the %d members of Stack is be created\n",number);
	GetData(S);
	DisposeStack(S);
	S=NULL;
	if(S==NULL)
	{
		printf("the Stack is be disposed!\n");
	}
	return 0;
}

int ChangeSymbol(char Symbol)
{
	if(Symbol=='+')
	{
		return 1;
	}
	else if(Symbol=='*')
	{
		return 2;
	}
	else if(Symbol=='(')
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

void GetData(Stack S)
{
	char data,top,poptop;
	int data_int,top_int;
	FILE *fp=fopen("Postfix.txt","r");
 	if(!fp)
 	{
  		printf("can't open file\n");
 	}
 	while(fscanf(fp,"%c",&data)!=EOF)
 	{
		if((data>='a')&&(data<='z'))
  		{
			printf("%c",data);
		}
		else
		{
			data_int=ChangeSymbol(data);
			if(IsEmpty(S)&&(data_int!=-1))
			{
				Push(data,S);
			}
			else if(data_int==0)
			{
				Push(data,S);
			}
			else if(data_int!=-1)
			{
				top=Top(S);
				top_int=ChangeSymbol(top);
				if(data_int>top_int)
				{
					Push(data,S);
				}
				else
				{
					do
					{
						poptop=PopTop(S);
						printf("%c",poptop);
						top_int=ChangeSymbol(Top(S));
					}while(!(IsEmpty(S)||(data_int>top_int)));
					Push(data,S);
				}
			}
			else if(data==')')
			{
				do
				{
					poptop=PopTop(S);
					if(poptop!='(')
					{
						printf("%c",poptop);
					}
					if(IsEmpty(S))
					{
						printf("\nError 2.1:the front matching Symbol isn't be found!\n");
						break;
					}
				}while(poptop!='(');
			}
			else if(data!='\n')
			{
				printf("\nError 1:Find a wrong Symbol!the Symbol is %c!\n",data);
			}
		}
 	}
	while(!IsEmpty(S))
	{	
		poptop=PopTop(S);
		printf("%c",poptop);
		if(poptop=='(')
		{
			printf("\nError2.2:the last matching Symbol isn't be found!\n");
		}
	}
 	printf("\n");
 	fclose(fp);
}

Stack CreateStack(int MaxElements)
{
	Stack S;
	S=malloc(sizeof(struct StackRecord));
	if(S==NULL)
	{
		printf("Stack is out of Space!\n");
	}
	S->Array=malloc((sizeof(ElementType)* MaxElements));
	if(S->Array==NULL)
	{
		printf("Array is out of Space!\n");
	}
	S->Capacity=MaxElements;
	MakeEmpty(S);
	return S;
}

void MakeEmpty(Stack S)
{
	S->TopOfStack=EmptyStack;
}

void Push(ElementType X,Stack S)
{
	if(IsFull(S))
	{
		printf("Stack is full!\n");
	}
	else
	{
		S->Array[++S->TopOfStack]=X;
	}
}

int IsFull(Stack S)
{
	return S->TopOfStack>=(S->Capacity-1);
}

int IsEmpty(Stack S)
{
	return S->TopOfStack==EmptyStack;
}

void Pop(Stack S)
{
	if(IsEmpty(S))
	{
		printf("stack is empty!\n");
	}
	else
	{
		S->TopOfStack--;
	}
}

ElementType PopTop(Stack S)
{
	if(IsEmpty(S))
	{
//		printf("stack is empty!\n");
		return 0;
	}
	else
	{
		return S->Array[S->TopOfStack--];
	}
}

ElementType Top(Stack S)
{
	if(IsEmpty(S))
	{
//		printf("stack is empty!\n");
		return '0';
	}
	else
	{
		return S->Array[S->TopOfStack];
	}
}

void DisposeStack(Stack S)
{
	if(S!=NULL)
	{
		free(S->Array);
		free(S);
	}
}
