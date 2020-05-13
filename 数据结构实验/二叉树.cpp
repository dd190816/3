// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//


#include<iostream>
using namespace std;
typedef char Telemtype;
typedef struct  binode
{
	Telemtype data;

	binode* lchild, * rchild;

}tbinode, * bitree;


//非递归方法创建
void creat_bitree(bitree&bt)
{
	int i, j;
	bitree s, p[100];
	cin >> i;
	while (i != 0)
	{
		s = new tbinode;
		cin >> s->data;
		s->lchild = s->rchild = NULL;
		p[i] = s;
		if (i == 1)
			bt = s;
		else
		{
			j = i / 2;
			if (i % 2 == 0)
				p[j] = s->lchild;
			else
				p[j] = s->rchild;
		}
		cin >> i;
	}
}


//递归创建一棵树
void creatdgui_bitree(bitree& bt, char str[])
{
	static int i = 0;
	char ch;
	ch = str[i++];
	if (ch == '.')
	{
		bt = NULL;
	}
	else
	{
		bt = new tbinode;
		bt->data = ch;
		creatdgui_bitree(bt->lchild, str);
		creatdgui_bitree(bt->rchild, str);

	}

}


//先序输出
void preorder(bitree bt)
{
	if (bt)
	{
		cout << bt->data;
		preorder(bt->lchild);
		preorder(bt->rchild);

	}

}


//中序输出
void inorder(bitree bt)
{

	if (bt)
	{
		inorder(bt->lchild);
		cout << bt->data;
		inorder(bt->rchild);

	}
}

//后序遍历
void postorder(bitree bt)
{
	if (bt)
	{
		postorder(bt->lchild);
		postorder(bt->rchild);
		cout << bt->data;

	}

}

//计算二叉树的叶子接点个数

int ynode_bitree(bitree bt)
{
	if (bt == NULL)
		return 0;

	if (bt->lchild == NULL && bt->rchild == NULL)
	{
		return 1;

	}
	return (ynode_bitree(bt->lchild) + ynode_bitree(bt->rchild));

}

//计算左右子树深度的最大值函数
int max(int x, int y)
{
	if (x >= y)
		return x;
	else
		return y;

}

//计算二叉树的深度
int  dept_bitree(bitree bt)
{

	int d = 0, deptl, deptr;//deptl,deptr分别表示左右子树的深度
	if (bt == NULL)
		return 0;
	deptl = dept_bitree(bt->lchild);
	deptr = dept_bitree(bt->rchild);
	d = max(deptl, deptr);
	return d + 1;

}
//求二叉树的结点总数

int total_bitree(bitree bt)
{
	int i;
	if (bt == NULL)
		return 0;
	else
		return i = 1 + total_bitree(bt->lchild) + total_bitree(bt->rchild);
	/* else
	{
	if(bt->lchid!=NULL)
	i++;
	else
	{
	bt->rchild!=NULL;
	i++;
	}
	}*/

}

//主函数部分
int  main()
{
	bitree bt;
	int i, j, t, flag = 1;
	cout << "1：递归法建立二叉树\n2:循环法建立二叉树\n3:二叉树的先序遍历\n4:二叉树的中序遍历\n5:二叉树的后序遍历\n6:求二叉树的叶子结点总数\n7:求二叉树的结点总数\n8:求二叉树的深度\n" << endl;
	cout << "请输入你要执行操作对应的序号:" << endl;
	while (flag)
	{
		int n;
		cin >> n;
		switch (n)
		{
		case 1:

			char str[200];
			cout << "请输入字符串:" << endl;
			cin >> str;
			creatdgui_bitree(bt, str);   //递归法实现二叉树的创建
			break;
		case 2:
			creat_bitree(bt);
			break;
		case 3:
			cout << "先序遍历的结果:" << endl;
			preorder(bt);//先序遍历
			cout << endl;
			break;
		case 4:
			cout << "中序遍历的结果:" << endl;
			inorder(bt);//中序遍历
			cout << endl;
			break;
		case 5:
			cout << "后序遍历的结果:" << endl;
			postorder(bt);  //后序遍历
			cout << endl;
			break;
		case 6:

			i = ynode_bitree(bt);//求二叉树的叶子结点总数
			cout << "叶子结点的总数为:" << i << endl;
			break;
		case 7:
			j = dept_bitree(bt);    //求二叉树的深度
			cout << "二叉树的结点总数:" << j << endl;
			break;
		case 8:
			t = total_bitree(bt);   //求二叉树的结点总数
			cout << "二叉树的深度是:" << t << endl;
			break;

		}

	}
	system("pause");
	return 0;


}
