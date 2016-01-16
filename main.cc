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
		int center = (left + right) / 2;//ȡ���е�
										//��ԭ�����з�Ϊ����
		MSort(a, left, center);
		MSort(a, center + 1, right);
		//�ϲ��ղŷֿ������Σ��õ�ԭ�����е���������
		Merge(a, left, center, right, right - left + 1);
	}
}

template <class T>
void MergeSort(T a[], int n)
{
	//���õݹ�鲢������
	MSort(a, 0, n - 1);
}
template <class T>
void Merge(T a[], int left, int center, int right, int n)
{
	T *t = new T[n];//��ű������Ԫ��
	int i = left;
	int j = center + 1;
	int k = 0;
	//�ϲ����飬�ò������������ߴ�Ͳ�����ߵ������ұߵļ������ȴ�������һ����ߵ����Ƚϣ��ұߴ�Ͳ����ұߵ�������ߵļ������ȴ�������һ���ұߵ����Ƚϣ�����ָ�Ĳ����ǲ��뵽������t[]��
	while (i <= center && j <= right)
	{
		if (a[i] <= a[j])
			t[k++] = a[i++];
		else
			t[k++] = a[j++];
	}
	//����Ĳ�����ִ���������ұ߶��п���ʣ�����ɸ�Ԫ�أ�����һ�ߵ�Ԫ�ؿ϶���ȫ�����Ƶ������飬��ʱ��Ҫ����Դ�ʣ�µ�Ԫ��
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
	//��t[]��Ԫ�ظ��ƻ�a[]��left��right��
	for (i = left, k = 0; i <= right; i++, k++)
		a[i] = t[k];
	//�ͷ��ڴ�
	delete[]t;
}
int main()
{
	int intArray[5] = { 5 , 6 , 2 , 5 , 9 };
	MergeSort(intArray, 5);
	for (int i = 0; i < 5; i++)
		cout << intArray[i] << endl;
}


//�ǵݹ�ʵ��
#include <iostream>
using namespace std;

template <class T>
void MergeSort(T a[], int n)
{
	/*�ǵݹ���ʽ��
	�㷨���ܣ��Ƚ�����������beforeLen��afterLen��i�����ã�
	int beforeLen; //�ϲ�ǰ���еĳ���
	int afterLen;//�ϲ������еĳ��ȣ��ϲ������еĳ����Ǻϲ�ǰ������
	int i = 0;//��ʼ�ϲ�ʱ��һ�����е���ʼλ���±꣬ÿ�ζ��Ǵ�0��ʼ
	i��i+beforeLen-1��i+afterLen-1���屻�ϲ����������еı߽硣
	�㷨�Ĺ����������£�
	��ʼʱ��beforeLen����Ϊ1��i����Ϊ0���ⲿforѭ����ѭ����ÿִ��һ�Σ���ʹbeforeLen��afterLen�ӱ����ڲ���whileѭ��ִ�����еĺϲ�����������ѭ����ÿִ��һ�Σ�i����ǰ�ƶ�afterLen��λ�á���n����afterLen�ı���ʱ��������ϲ����е���ʼλ��i�����Ϻϲ������еĳ���afterLen��������������ı߽�n���ͽ����ڲ�ѭ������ʱ������ϲ����е���ʼλ��i�����Ϻϲ�ǰ���еĳ��� beforeLen��С����������ı߽�n������Ҫִ��һ�κϲ�����������󳤶Ȳ���afterLen��������beforeLen�����кϲ�����������������㷨�����Merge(a, i, i+beforeLen-1, n-1, n);��ɡ�*/
	/*  int beforeLen; //�ϲ�ǰ���еĳ���
	int afterLen = 1;//�ϲ������еĳ���

	for (beforeLen=1; afterLen<n; beforeLen=afterLen)
	{
	int i = 0;//��ʼ�ϲ�ʱ��һ�����е���ʼλ���±꣬ÿ�ζ��Ǵ�0��ʼ
	afterLen = 2 * beforeLen; //�ϲ������еĳ����Ǻϲ�ǰ������

	while (i+afterLen < n)
	{
	Merge(a, i, i+beforeLen-1, i+afterLen-1, afterLen);
	i += afterLen;
	}

	if (i+beforeLen < n)
	Merge(a, i, i+beforeLen-1, n-1, n);
	}*/
	//���Լ�д������������
	int lengthTocombine = 1;//���彫Ҫ���ϲ��ĳ��ȣ���ʼʱΪ1��
	int begin;
	for (lengthTocombine = 1; lengthTocombine < n; lengthTocombine *= 2)
	{
		begin = 0;//��ʼ�ϲ�ʱ��һ�����е���ʼλ���±꣬ÿ�ζ��Ǵ�0��ʼ
		while (begin + 2 * lengthTocombine < n)
		{
			Merge(a, begin, (2 * begin + 2 * lengthTocombine - 1) / 2, begin + 2 * lengthTocombine - 1, 2 * lengthTocombine);
			begin += 2 * lengthTocombine;
		}
		//ʣ�³���С��lengthTocombine����
		if (begin + lengthTocombine < n)
			Merge(a, begin, begin + lengthTocombine - 1, n - 1, n);
	}
}
template <class T>
void Merge(T a[], int left, int center, int right, int n)
{
	T *t = new T[n];//��ű������Ԫ��
	int i = left;
	int j = center + 1;
	int k = 0;
	//�ϲ����飬�ò������������ߴ�Ͳ�����ߵ������ұߵļ������ȴ�������һ����ߵ����Ƚϣ��ұߴ�Ͳ����ұߵ�������ߵļ������ȴ�������һ���ұߵ����Ƚϣ�����ָ�Ĳ����ǲ��뵽������t[]��
	while (i <= center && j <= right)
	{
		if (a[i] <= a[j])
			t[k++] = a[i++];
		else
			t[k++] = a[j++];
	}
	//����Ĳ�����ִ���������ұ߶��п���ʣ�����ɸ�Ԫ�أ�����һ�ߵ�Ԫ�ؿ϶���ȫ�����Ƶ������飬��ʱ��Ҫ����Դ�ʣ�µ�Ԫ��
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
	//��t[]��Ԫ�ظ��ƻ�a[]��left��right��
	for (i = left, k = 0; i <= right; i++, k++)
		a[i] = t[k];
	//�ͷ��ڴ�
	delete[]t;
}

int main()
{
	int intArray[5] = { 23 , 8 , 1 , 6 , 10 };
	MergeSort(intArray, 5);//ִ������
	for (int i = 0; i < 5; i++)
		cout << intArray[i] << endl;
}

#endif