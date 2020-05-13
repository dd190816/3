#define stacksize 100
#include<stdio.h>
#include<stdlib.h>
typedef struct
{
 int num[stacksize];
int top; }seqstack;/*栈定义*/
void initstack(seqstack * s)/*初始化栈*/
{ s->top = -1;}
int push(seqstack * s, int e)/*入栈*/ 
{ if (s->top == stacksize - 1) { printf("Stack is full!n"); return 0; } 
s->top++;s->num[s->top] = e; return 1; 
}
int pop(seqstack * s, int * e)/*出栈*/ 
{ if (s->top == -1)return 0;
*e = s->num[s->top];
s->top--;
return 1; }
void printstack(seqstack * s)/*输出栈中元素，栈底到栈顶*/ 
{ int i;
printf("栈底到栈顶依次为:");
for (i = 0; i <= s->top; i++)
printf("%5d", s->num[i]);
printf("\n"); 
}
void main()
{
	int n, i, x;
	seqstack s;
	printf("初始化栈\n");
	initstack(&s);//初始化栈 
	printf("栈底和栈顶为%d\n", s.top);
	printf("请输入栈中元素的个数");
	scanf_s("%d", &n);
	printf("执行入栈操作\n");
	for (i = 0; i < n; i++)
	{
		push(&s, 2 * i + 1);//入栈 
	}
	printf("栈顶和栈顶元素分别为%d,%d\n", s.top, s.num[s.top]);
	printstack(&s);//遍历栈中元素 //出栈 
	printf("执行出栈操作\n");
	pop(&s, &x);//出栈操作 
	printf("出栈元素为%d\n", s.num[s.top + 1]);
	printstack(&s);
}