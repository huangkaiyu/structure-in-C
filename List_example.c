#include <stdio.h>
#include <stdlib.h>

/*编译初始化时候的定义声明*/
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;//test data is integer
struct Node;
/*functions*/
void CreateList(List L);
void PrintList(List L);
int IsEmpty(List L);
int IsLast(Position P);
Position Find(List L,ElementType X);
Position FindPrevious(List L,ElementType X);
void Delete(List L,ElementType X);
void Insert(Position P,ElementType X);
void DeleteList(List L);

struct Node
{
	ElementType Element;
	Position Next;
};

int main()
{
	List head;
	head=malloc(sizeof(struct Node));
	head->Next=NULL;
	if(IsEmpty(head))
	{
		printf("List is empty，please input integer data for List,and input 0 to finish\n");
		CreateList(head);
		printf("List is be created successfully!\n");
	}
	else
	{
		printf("List has already been finished！");
	}
	/*在这添加一个Find的测试，parameter：需要查询的数据X和对应的链表,response：数据在链表中的位置，如果查	无此项则返回null*/
	Position P_test;
	ElementType X;
	printf("please input data on search:");
	scanf("%d",&X);
	P_test=Find(head,X);
	if(P_test!=NULL)
	{
		printf("find it!position is P_test,and data is :%d\n",P_test->Element);
	}
	else
	{
		printf("can not find data!\n");
	}
	/*在这添加一个Delete的测试，parameter：需要删除的数据X和对应的链表,response：void*/
	ElementType D;
	printf("please input data on delete:");
	scanf("%d",&D);
	Delete(head,D);
	/*在这添加一个Insert的测试（因为是测试，所以添加的位置为上例中find到的位置P_test），
	parameter：需要插入的数据X和在链表插入的位置（插入到后面）,response：void*/
	ElementType I;
	printf("please input data on Insert:");
	scanf("%d",&I);
	Insert(P_test,I);	

	if(!IsEmpty(head))
	{
		printf("List will be printed\n");
		PrintList(head);
		printf("List is be printed successfully!\n");
	}
	else
	{
		printf("List is empty!please create it!\n");
	}
	/*在这添加一个Delete的测试*/
	DeleteList(head);
	if(!IsEmpty(head))
	{
		printf("List will be printed\n");
		PrintList(head);
		printf("List is be printed successfully!\n");
	}
	else
	{
		printf("List is empty!please create it!\n");
	}
	return 0;
}

void CreateList(List L)
{
	ElementType input;
	List temp;
	while(scanf("%d",&input))
	{
		if(input!=0)
		{
			temp=malloc(sizeof(struct Node));
			temp->Element=input;
			L->Next=temp;
			L=temp;
		}
		else
		{
			L->Next=NULL;
			break;
		}
	}
}

void PrintList(List L)
{
	L=L->Next;
	while(L!=NULL)
	{
		printf("%d\n",L->Element);
		L=L->Next;
	}
}			

int IsEmpty(List L)
{
	return L->Next==NULL;
}

int IsLast(Position P)
{
	return P->Next==NULL;
}

Position Find(List L,ElementType X)
{
	Position P;
	P=L->Next;
	while(P!=NULL&&P->Element!=X)
	{
		P=P->Next;
	}
	return P;
}

Position FindPrevious(List L,ElementType X)
{
	Position P;
	P=L;
	while(P->Next!=NULL&&P->Next->Element!=X)
	{
		P=P->Next;
	}
	return P;
}

void Delete(List L,ElementType X)
{
	Position P,temp;
	P=FindPrevious(L,X);
	if(!IsLast(P))
	{
		temp=P->Next;
		P->Next=temp->Next;
		free(temp);
	}
}

void Insert(Position P,ElementType X)
{
	Position temp;
	temp=malloc(sizeof(struct Node));
	if(temp==NULL)
	{
		printf("can not create a node!");
	}
	temp->Element=X;
	temp->Next=P->Next;
	P->Next=temp;
}

void DeleteList(List L)
{
	Position P,temp;
	P=L->Next;
	L->Next=NULL;
	while(P!=NULL)
	{
		temp=P->Next;
		free(P);
		P=temp;
	}   	
}








	
