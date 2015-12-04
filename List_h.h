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








	
