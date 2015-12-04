#include <stdio.h>
#include <stdlib.h>

/*编译初始化时候的定义声明*/
typedef struct StackRecord *Stack;
typedef int ElementType;//test data is integer
struct StackRecord;
#define EmptyStack -1
#define MaxArrayNumber 100
/*functions*/
int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void MakeEmpty(Stack S);
void Push(ElementType X,Stack S); 
void Pop(Stack S);
ElementType PopTop(Stack S);
void GetData(Stack S); 
void DisposeStack(Stack S);
int Calculate(char Symbol,int a,int b);

struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};

/*static variable*/
char Array[MaxArrayNumber];
int n=0;

int main()
{
	int number=0;
	Stack S;
//	printf("please input the number of the stack member:");
//	scanf("%d",&number);
	S=CreateStack(MaxArrayNumber);
	printf("the %d members of Stack is be created\n",MaxArrayNumber);
	GetData(S);
	printf("the result is %d.\n",PopTop(S));
	if(!IsEmpty(S))
	{
		printf("Error 2:Stack is not empty!.The postfix is wrong!\n");
		return -1;
	}
	DisposeStack(S);
	S=NULL;
	if(S==NULL)
	{
		printf("the Stack is be disposed!\n");
	}
	return 0;
}

void GetData(Stack S)
{
	char data;
	int data_int,a,b,c;
	FILE *fp=fopen("PostfixCalculate.txt","r");
 	if(!fp)
 	{
  		printf("can't open file\n");
 	}
 	while(fscanf(fp,"%c",&data)!=EOF)
 	{
		if((data>='a')&&(data<='z'))
  		{
			printf("please input the %c is:",data);
			scanf("%d",&data_int);
			Push(data_int,S);
		}
		else if(data=='+'||data=='*')
		{
			printf("start to calculate the %c\n",data);			
			if(IsEmpty(S))
			{
				printf("Error 1.1:Stack is empty!.The postfix is wrong!\n");
				break;
			}			
			a=PopTop(S);
			if(IsEmpty(S))
			{
				printf("Error 1.2:Stack is empty!.The postfix is wrong!\n");
				break;
			}
			b=PopTop(S);
			c=Calculate(data,a,b);
			Push(c,S);
		}
		else
		{
			printf("Error 1.3:Find a wrong symbol!The wrong symbol is %d\n",data);
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

void DisposeStack(Stack S)
{
	if(S!=NULL)
	{
		free(S->Array);
		free(S);
	}
}

int Calculate(char Symbol,int a,int b)
{
	if(Symbol=='+')
	{
		return a+b;
	}
	else if(Symbol=='*')
	{
		return a*b;
	}
	else
	{
		return 0;
	}
}
