#include <stdio.h>
#include <stdlib.h>
#include "Stack_h.h"

void BlanceSymbol(Stack S);

int main()
{
	Stack S;
	int number;
	printf("please input the number of the stack member:");
	scanf("%d",&number);
	S=CreateStack(number);
	printf("the %d members of Stack is be created\n",number);
	BlanceSymbol(S);
	DisposeStack(S);
	S=NULL;
	if(S==NULL)
	{
		printf("the Stack is be disposed!\n");
	}
	return 0;
}

int IsFull(Stack S)
{
	return S->TopOfStack>=(S->Capacity-1);
}

int IsEmpty(Stack S)
{
	return S->TopOfStack==EmptyStack;
}

void MakeEmpty(Stack S)
{
	S->TopOfStack=EmptyStack;
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

void DisposeStack(Stack S)
{
	if(S!=NULL)
	{
		free(S->Array);
		free(S);
	}
}

void BlanceSymbol(Stack S)
{
	char data,temp;
	FILE *fp=fopen("BlanceSymbol.txt","r");
 	if(!fp)
 	{
  		printf("can't open file\n");
 	}
 	while(fscanf(fp,"%c",&data)!=EOF)
 	{
		if(data=='('||data=='{'||data=='['||data=='<')
  		{
			Push(data,S);
		}
		if(data==')'||data=='}'||data==']'||data=='>')
		{
			if(IsEmpty(S))
			{
				printf("Error 1!the front of symbol is lacking!\n");
			}
			else
			{
				temp=PopTop(S);
				if((temp=='('&&data==')')||(temp=='<'&&data=='>')||(temp=='['&&data==']')||(temp=='{'&&data=='}'))
				{
					printf("matching!\n");
				}
				else
				{
					printf("Error 2!the symbol isn't matching\n");
				}
			}
		}
 	}
	if(!IsEmpty(S))
	{
		printf("Error 3!the last of symbol is lacking!\n");
	}
 	printf("\n");
 	fclose(fp);
}

