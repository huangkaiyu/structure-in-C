#include <stdio.h>
#include <stdlib.h>
/*编译初始化时候的定义声明*/
typedef struct Node *Polynomial;
#define MaxDegree 100
struct Node;
/*functions*/
void CreatePolynomial(Polynomial Poly);
void ZeroPolynomial(Polynomial Poly);
void PrintPolynomial(Polynomial Poly);
int Max(Polynomial Poly1,Polynomial Poly2);
void AddPolynomial(Polynomial PolySum,Polynomial Poly1,Polynomial Poly2);
void MulPolynomial(Polynomial PolyMul,Polynomial Poly1,Polynomial Poly2);

struct Node
{
	int CoeffArray[MaxDegree+1];
	int HighPower;
};

int main()
{
	Polynomial PolySum,PolyMul,Poly1,Poly2;
	PolySum=malloc(sizeof(struct Node));
	PolyMul=malloc(sizeof(struct Node));
	Poly1=malloc(sizeof(struct Node));
	Poly2=malloc(sizeof(struct Node));
	CreatePolynomial(Poly1);
	PrintPolynomial(Poly1);
	CreatePolynomial(Poly2);
	PrintPolynomial(Poly2);
	AddPolynomial(PolySum,Poly1,Poly2);
	MulPolynomial(PolyMul,Poly1,Poly2);
	printf("Poly1 + Poly2 = ");
	PrintPolynomial(PolySum);
	printf("Poly1 * Poly2 = ");
	PrintPolynomial(PolyMul);
	return 0;
}

void ZeroPolynomial(Polynomial Poly)
{
	int i;
	Poly->HighPower=0;
	for(i=0;i<=MaxDegree;i++)
	{
		Poly->CoeffArray[i]=0;
	}
}

void CreatePolynomial(Polynomial Poly)
{
	ZeroPolynomial(Poly);
	int i,high,Coe;
	printf("输入项式最高次幂为:");
	scanf("%d",&high);
	Poly->HighPower=high;
	for(i=high;i>=0;i--)
	{
		printf("%d次幂的系数为:",i);
		scanf("%d",&Coe);
		Poly->CoeffArray[i]=Coe;
 	}
}

void PrintPolynomial(Polynomial Poly)
{
	int i;
	for(i=Poly->HighPower;i>0;i--)
	{
		if(Poly->CoeffArray[i]!=0)
		{			
			printf("%dX^%d+",Poly->CoeffArray[i],i);
		}
	}
	printf("%d\n",Poly->CoeffArray[0]);
}

int Max(Polynomial Poly1,Polynomial Poly2)
{
	if(Poly1->HighPower>=Poly2->HighPower)
	{
		return Poly1->HighPower;
	}
	else
	{
		return Poly2->HighPower;
	}
}

void AddPolynomial(Polynomial PolySum,Polynomial Poly1,Polynomial Poly2)
{
	int i;
	ZeroPolynomial(PolySum);
	PolySum->HighPower=Max(Poly1,Poly2);
	for(i=PolySum->HighPower;i>=0;i--)
	{
		PolySum->CoeffArray[i]=Poly1->CoeffArray[i]+Poly2->CoeffArray[i];
	}	
}

void MulPolynomial(Polynomial PolyMul,Polynomial Poly1,Polynomial Poly2)
{
	int i,j;
	ZeroPolynomial(PolyMul);
	PolyMul->HighPower=Poly1->HighPower+Poly2->HighPower;
	for(i=Poly1->HighPower;i>=0;i--)
		for(j=Poly2->HighPower;j>=0;j--)
		{
			PolyMul->CoeffArray[i+j]+=Poly1->CoeffArray[i]*Poly2->CoeffArray[j];
		}
}













