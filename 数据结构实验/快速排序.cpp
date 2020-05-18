///2020.5.18

/*��дһ������ʵ�ֿ��������㷨��
  �����{94��28��57��66��35��84��63��42��71��10}���������*/

#include <iostream>
using namespace std;

//�ú���������ʾÿ�ε���Qsort()���������
//������()�������ĸô��������ŦԪ��
void show(int date[], int n, int p) {
	static int num = 0;
	num++;
	cout << "�����ǵ�" << num << "�ε���Qsort()��������:" << endl;
	for (int i = 0; i < p; i++)
		cout << date[i] << " ";
	cout << "(" << date[p] << ") ";
	for (int i = p + 1; i < n; i++)
		cout << date[i] << " ";
	cout << endl;
}
//����������,date��Ҫ�������飬n������Ԫ�ظ���
void Qsort(int date[], int n) {
	if (n <= 1)
		return;
	int p = 0, q = n - 1;
	int k = date[0];
	while (p < q) {
		while (p < q && date[q] >= k)
			q--;
		date[p] = date[q];
		while (p < q && date[p] <= k)
			p++;
		date[q] = date[p];
	}
	date[p] = k;
	show(date, n, p);
	Qsort(date, p);
	Qsort(date + p + 1, n - 1 - p);
}

int main() {
	int date[] = { 265,301,751,129,937,863,742,694,76,438 };

	cout << "��������:" << endl;
	Qsort(date, 10);

	cout << "���ս��:" << endl;
	for (int i = 0; i < 10; i++) {
		cout << date[i] << " ";
	}
	cout << endl;
	return 0;
}