///2014.6.3

//��дһ������ʵ��ֱ�Ӳ����������
 

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

//�ú���������ʾ��������������е����ݱ仯
void showdetail(int date[], int n, int i) {
	cout << "�� " << i << " ��:" << endl;
	cout << "��������:";
	for (int j = 0; j < i; j++)
		cout << " " << date[j];
	cout << endl;
	cout << "��������:";
	for (int j = i; j < n; j++)
		cout << " " << date[j];
	cout << endl << endl;
}
//�ú���������ʾ����������
void showresult(int date[], int n) {
	cout << "���ս���ǣ�" << endl;
	for (int i = 0; i < n; i++) {
		cout << date[i] << " ";
	}
	cout << endl;
}

//ֱ�Ӳ���������
//date������Ҫ��������飬n�������Ԫ�ظ���
void insertsort(int date[], int n) {
	for (int i = 1; i < n; i++) {
		showdetail(date, n, i);
		int temp = date[i];
		for (int j = 0; j < i; j++) {
			if (date[j] > date[i]) {
				for (int p = i; p > j; p--)
					date[p] = date[p - 1];
				date[j] = temp;
			}
		}
	}
	showresult(date, n);
}

int main() {
	int date[] = { 265,301,751,129,937,863,742,694,76,438 };

	cout << "ֱ�Ӳ�������:" << endl << endl;
	insertsort(date, 10);

	return 0;
}