///2020.5.18

/*编写一个程序实现快速排序算法，
  并输出{94，28，57，66，35，84，63，42，71，10}的排序过程*/

#include <iostream>
using namespace std;

//该函数用于显示每次调用Qsort()后的排序结果
//其中用()括起来的该次排序的枢纽元素
void show(int date[], int n, int p) {
	static int num = 0;
	num++;
	cout << "下面是第" << num << "次调用Qsort()处理的情况:" << endl;
	for (int i = 0; i < p; i++)
		cout << date[i] << " ";
	cout << "(" << date[p] << ") ";
	for (int i = p + 1; i < n; i++)
		cout << date[i] << " ";
	cout << endl;
}
//快速排序函数,date是要排序数组，n是数组元素个数
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

	cout << "快速排序:" << endl;
	Qsort(date, 10);

	cout << "最终结果:" << endl;
	for (int i = 0; i < 10; i++) {
		cout << date[i] << " ";
	}
	cout << endl;
	return 0;
}