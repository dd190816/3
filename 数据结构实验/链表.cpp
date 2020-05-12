#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
void travser(node *&L)
{
 node * p;p = L->next;
	printf("\n");
	while (p != NULL) 
	{ printf("%d ", p->data);
	p = p->next; 
	}
}
void create_List(node*&L, int n)
{ int i; node*p,*r;
L=(node*)malloc(sizeof(node));
L->next= NULL;
r = L;
for (i = n; i > 0; i--) 
{p=(node*)malloc(sizeof(node));
scanf_s("%d", &(p->data));
r->next = p;r = p; }
r->next = NULL; }
void insert(node*& L, int i, int x)
{
	node* S, * P = L;
	int k = 0;
	while (k != i - 1 && P != NULL)
	{
		P = P->next; k++;
	}
	if (P == NULL)
		printf("序号出错");
	else {
		S = (node*)malloc(sizeof(node));
		S->data = x;
		S->next = P->next; P->next = S;
	}
}
void deleteset(node *& L, int i) 
{
    node* p, * s;
	int j = 0;
	int e;
	p = L;
	while (p->next && j < i - 1) 
	{ p = p->next;j++; }
	if (!p->next|| j > i - 1)
		printf("位置错误");
	s = p->next; //s 为待删除接点
	p->next=s->next;
   e=s->data;
	free(s);
	printf("删除的数据为%d",e);
}
void main( )
{
    node* L;
	int i, x, n;
	printf("请输入要创建的链表的长度");
	scanf_s("%d", &n);
	printf("请输入数据");
	create_List(L, n);//创建长度为n的链表     
	printf("您创建的链表为");
	travser(L);//对链表进行遍历
	printf("\n请输入要在链表中插入的数据及其位置");
	scanf_s("%d%d", &x, &i);
	insert(L, i, x);//在链表指定位置插入数据     
	travser(L);
	printf("请输入要删除数据的位置");
	scanf_s("%d", &i);
	deleteset(L, i);//链表删除函数  
	travser(L);
}