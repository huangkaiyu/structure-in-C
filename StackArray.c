#include <stdio.h>
#include <stdlib.h>

/*编译初始化时候的定义声明*/
typedef struct StackRecord *Stack;
typedef int ElementType;//test data is integer
struct StackRecord;
#define EmptyStack -1
/*functions*/
int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void MakeEmpty(Stack S);
void Push(ElementType X,Stack S);
void GetData(Stack S);  
void Pop(Stack S);
ElementType PopTop(Stack S);
void PrintStack(Stack S);
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
	PrintStack(S);
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
	int data;
	FILE *fp=fopen("filetest.txt","r");
 	if(!fp)
 	{
  		printf("can't open file\n");
 	}
 	while(fscanf(fp,"%d",&data)!=EOF)
 	{
  		Push(data,S);
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
		printf("stack is empty!\n");
		return 0;
	}
	else
	{
		return S->Array[S->TopOfStack--];
	}
}

void PrintStack(Stack S)
{
	ElementType temp=0;
	temp=PopTop(S);
	while(temp)
	{
		printf("%d ",temp);
		temp=PopTop(S);		
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
