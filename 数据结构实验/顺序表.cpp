#include<stdio.h>
#include<stdlib.h>
#define maxlen 100
typedef struct
{
	int data[maxlen];
int listlen; 
}seqlist;
seqlist L;
void travser(seqlist L)
{
	int i;
	for (i = 0; i < L.listlen; i++)
		printf("%d"" ",L.data[i]);
	printf("\n长度=%d\n",L.listlen);
}void List_delete(seqlist* L, int i)
{
	int j; if (L->listlen <= 0) { printf("下溢出错"); return; }
	if (i > L->listlen || i < 1) { printf("删除位置出错"); return; }
	else {
		for(j = i; j <= L->listlen - 1; j++)
			L->data[j - 1] = L->data[j];
		L->listlen--;
	}
}
void List_insert( seqlist * L, int x, int i)
{ int j;if(L->listlen==maxlen) 
{ printf("overflow"); return; }
if (i<1 || i>L->listlen + 1) {printf("positionerror");return;}
for (j = L->listlen - 1; j >= i - 1; j--)
L->data[j + 1] = L->data[j];
L->data[i - 1] = x;
L->listlen++; }
void creatlist(seqlist* L,int n) 
{//输入n个数，建立顺序表L  
	int k;
	int *p;
	for(k=0;k<n;k++)
	{p=(int*)malloc(sizeof(int));
	scanf_s("%d",p);
	L->data [k]=*p;
	L->listlen ++;
	}
}
void main()
{
	int i, x, n;
	printf("请输入要创建的顺序表的长度");
	scanf_s("%d", &n);
	printf("\n请输入数据\n");
	creatlist(&L, n);//创建顺序表表
	travser(L);//遍历顺序表
	printf("\n请输入向顺序表中插入的数据及位置\n");
	scanf_s("%d%d", &x, &i);
	List_insert(&L, x, i);//顺序表的插入操作   
	travser(L);
	printf("\n请输入准备删除的数据的位置\n");
	scanf_s("%d", &i);
	List_delete(&L, i);//顺序表的删除操作
	travser(L);
}