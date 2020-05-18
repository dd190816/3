///2014.6.3

//编写一个程序实现直接插入排序过程
 

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

//该函数用于显示排序过程中数组中的数据变化
void showdetail(int date[], int n, int i) {
	cout << "第 " << i << " 轮:" << endl;
	cout << "有序序列:";
	for (int j = 0; j < i; j++)
		cout << " " << date[j];
	cout << endl;
	cout << "无序序列:";
	for (int j = i; j < n; j++)
		cout << " " << date[j];
	cout << endl << endl;
}
//该函数用于显示最终排序结果
void showresult(int date[], int n) {
	cout << "最终结果是：" << endl;
	for (int i = 0; i < n; i++) {
		cout << date[i] << " ";
	}
	cout << endl;
}

//直接插入排序函数
//date数组是要排序的数组，n是数组的元素个数
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

	cout << "直接插入排序:" << endl << endl;
	insertsort(date, 10);

	return 0;
}