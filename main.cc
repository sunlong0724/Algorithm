#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

void print(const vector<int>& vec) {
	for each (auto val in vec) {
		cout << val << ", ";
	}
	cout << endl;
}
void insert_sort(vector<int>& vec) {
	int key;
	for (int i = 1; i < vec.size(); ++i) {
		key = vec[i];
		int j = i - 1;
		while (j >= 0 && vec[j] > key) {
			vec[j + 1] = vec[j];
			--j;
		}
		vec[j + 1] = key;
	}
}


int main()
{
	vector<int> vec{ 1,2,4,3,6,5 };
	int arr[10] = {1,3,2,4,6,5,8,7,0,9};

	print(vec);
	insert_sort(vec);
	print(vec);

	//merge_sort(arr, 0, sizeof(arr)-1);

    return 0;
}
#if 0

#include <iostream>
using namespace std;
template <class T>
void MSort(T a[], int left, int right)
{
	if (left < right)
	{
		int center = (left + right) / 2;//取得中点
										//将原来序列分为两段
		MSort(a, left, center);
		MSort(a, center + 1, right);
		//合并刚才分开的两段，得到原来序列的有序序列
		Merge(a, left, center, right, right - left + 1);
	}
}

template <class T>
void MergeSort(T a[], int n)
{
	//调用递归归并排序函数
	MSort(a, 0, n - 1);
}
template <class T>
void Merge(T a[], int left, int center, int right, int n)
{
	T *t = new T[n];//存放被排序的元素
	int i = left;
	int j = center + 1;
	int k = 0;
	//合并数组，用插入排序，如果左边大就插入左边的数，右边的计数器等待，与下一个左边的数比较；右边大就插入右边的数，左边的计数器等待，与下一个右边的数比较（这里指的插入是插入到新数组t[]）
	while (i <= center && j <= right)
	{
		if (a[i] <= a[j])
			t[k++] = a[i++];
		else
			t[k++] = a[j++];
	}
	//上面的步骤在执行完后，左或右边都有可能剩余若干个元素，而另一边的元素肯定已全部复制到新数组，这时需要特殊对待剩下的元素
	if (i == center + 1)
	{
		while (j <= right)
			t[k++] = a[j++];
	}
	else
	{
		while (i <= center)
			t[k++] = a[i++];
	}
	//把t[]的元素复制回a[]中left到right段
	for (i = left, k = 0; i <= right; i++, k++)
		a[i] = t[k];
	//释放内存
	delete[]t;
}
int main()
{
	int intArray[5] = { 5 , 6 , 2 , 5 , 9 };
	MergeSort(intArray, 5);
	for (int i = 0; i < 5; i++)
		cout << intArray[i] << endl;
}


//非递归实现
#include <iostream>
using namespace std;

template <class T>
void MergeSort(T a[], int n)
{
	/*非递归形式：
	算法介绍：先介绍三个变量beforeLen，afterLen和i的作用：
	int beforeLen; //合并前序列的长度
	int afterLen;//合并后序列的长度，合并后序列的长度是合并前的两倍
	int i = 0;//开始合并时第一个序列的起始位置下标，每次都是从0开始
	i，i+beforeLen-1，i+afterLen-1定义被合并的两个序列的边界。
	算法的工作过程如下：
	开始时，beforeLen被置为1，i被置为0。外部for循环的循环体每执行一次，都使beforeLen和afterLen加倍。内部的while循环执行序列的合并工作，他的循环体每执行一次，i都向前移动afterLen个位置。当n不是afterLen的倍数时，如果被合并序列的起始位置i，加上合并后序列的长度afterLen，超过输入数组的边界n，就结束内部循环；此时如果被合并序列的起始位置i，加上合并前序列的长度 beforeLen，小于输入数组的边界n，还需要执行一次合并工作，把最后长度不足afterLen，但超过beforeLen的序列合并起来。这个工作由算法的语句Merge(a, i, i+beforeLen-1, n-1, n);完成。*/
	/*  int beforeLen; //合并前序列的长度
	int afterLen = 1;//合并后序列的长度

	for (beforeLen=1; afterLen<n; beforeLen=afterLen)
	{
	int i = 0;//开始合并时第一个序列的起始位置下标，每次都是从0开始
	afterLen = 2 * beforeLen; //合并后序列的长度是合并前的两倍

	while (i+afterLen < n)
	{
	Merge(a, i, i+beforeLen-1, i+afterLen-1, afterLen);
	i += afterLen;
	}

	if (i+beforeLen < n)
	Merge(a, i, i+beforeLen-1, n-1, n);
	}*/
	//我自己写的主函数代码
	int lengthTocombine = 1;//定义将要被合并的长度，开始时为1；
	int begin;
	for (lengthTocombine = 1; lengthTocombine < n; lengthTocombine *= 2)
	{
		begin = 0;//开始合并时第一个序列的起始位置下标，每次都是从0开始
		while (begin + 2 * lengthTocombine < n)
		{
			Merge(a, begin, (2 * begin + 2 * lengthTocombine - 1) / 2, begin + 2 * lengthTocombine - 1, 2 * lengthTocombine);
			begin += 2 * lengthTocombine;
		}
		//剩下长度小于lengthTocombine序列
		if (begin + lengthTocombine < n)
			Merge(a, begin, begin + lengthTocombine - 1, n - 1, n);
	}
}
template <class T>
void Merge(T a[], int left, int center, int right, int n)
{
	T *t = new T[n];//存放被排序的元素
	int i = left;
	int j = center + 1;
	int k = 0;
	//合并数组，用插入排序，如果左边大就插入左边的数，右边的计数器等待，与下一个左边的数比较；右边大就插入右边的数，左边的计数器等待，与下一个右边的数比较（这里指的插入是插入到新数组t[]）
	while (i <= center && j <= right)
	{
		if (a[i] <= a[j])
			t[k++] = a[i++];
		else
			t[k++] = a[j++];
	}
	//上面的步骤在执行完后，左或右边都有可能剩余若干个元素，而另一边的元素肯定已全部复制到新数组，这时需要特殊对待剩下的元素
	if (i == center + 1)
	{
		while (j <= right)
			t[k++] = a[j++];
	}
	else
	{
		while (i <= center)
			t[k++] = a[i++];
	}
	//把t[]的元素复制回a[]中left到right段
	for (i = left, k = 0; i <= right; i++, k++)
		a[i] = t[k];
	//释放内存
	delete[]t;
}

int main()
{
	int intArray[5] = { 23 , 8 , 1 , 6 , 10 };
	MergeSort(intArray, 5);//执行排序
	for (int i = 0; i < 5; i++)
		cout << intArray[i] << endl;
}

#endif