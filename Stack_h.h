#include <stdio.h>
#include <stdlib.h>

/*编译初始化时候的定义声明*/
typedef struct StackRecord *Stack;
typedef char ElementType;
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


