// ConsoleApplication1.cpp: �������̨Ӧ�ó������ڵ㡣
//


#include<iostream>
using namespace std;
typedef char Telemtype;
typedef struct  binode
{
	Telemtype data;

	binode* lchild, * rchild;

}tbinode, * bitree;


//�ǵݹ鷽������
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


//�ݹ鴴��һ����
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


//�������
void preorder(bitree bt)
{
	if (bt)
	{
		cout << bt->data;
		preorder(bt->lchild);
		preorder(bt->rchild);

	}

}


//�������
void inorder(bitree bt)
{

	if (bt)
	{
		inorder(bt->lchild);
		cout << bt->data;
		inorder(bt->rchild);

	}
}

//�������
void postorder(bitree bt)
{
	if (bt)
	{
		postorder(bt->lchild);
		postorder(bt->rchild);
		cout << bt->data;

	}

}

//�����������Ҷ�ӽӵ����

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

//��������������ȵ����ֵ����
int max(int x, int y)
{
	if (x >= y)
		return x;
	else
		return y;

}

//��������������
int  dept_bitree(bitree bt)
{

	int d = 0, deptl, deptr;//deptl,deptr�ֱ��ʾ�������������
	if (bt == NULL)
		return 0;
	deptl = dept_bitree(bt->lchild);
	deptr = dept_bitree(bt->rchild);
	d = max(deptl, deptr);
	return d + 1;

}
//��������Ľ������

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

//����������
int  main()
{
	bitree bt;
	int i, j, t, flag = 1;
	cout << "1���ݹ鷨����������\n2:ѭ��������������\n3:���������������\n4:���������������\n5:�������ĺ������\n6:���������Ҷ�ӽ������\n7:��������Ľ������\n8:������������\n" << endl;
	cout << "��������Ҫִ�в�����Ӧ�����:" << endl;
	while (flag)
	{
		int n;
		cin >> n;
		switch (n)
		{
		case 1:

			char str[200];
			cout << "�������ַ���:" << endl;
			cin >> str;
			creatdgui_bitree(bt, str);   //�ݹ鷨ʵ�ֶ������Ĵ���
			break;
		case 2:
			creat_bitree(bt);
			break;
		case 3:
			cout << "��������Ľ��:" << endl;
			preorder(bt);//�������
			cout << endl;
			break;
		case 4:
			cout << "��������Ľ��:" << endl;
			inorder(bt);//�������
			cout << endl;
			break;
		case 5:
			cout << "��������Ľ��:" << endl;
			postorder(bt);  //�������
			cout << endl;
			break;
		case 6:

			i = ynode_bitree(bt);//���������Ҷ�ӽ������
			cout << "Ҷ�ӽ�������Ϊ:" << i << endl;
			break;
		case 7:
			j = dept_bitree(bt);    //������������
			cout << "�������Ľ������:" << j << endl;
			break;
		case 8:
			t = total_bitree(bt);   //��������Ľ������
			cout << "�������������:" << t << endl;
			break;

		}

	}
	system("pause");
	return 0;


}
