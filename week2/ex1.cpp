#include<iostream>
using namespace std;
//k là giá trị cần tìm kiếm
//n là kích thước của mảng nums[]
//Hàm hoạt động theo cách duyệt từ đầu đến cuối mảng để tìm phần tử có giá trị k
int linear_search(int nums[], int n, int k)
{
	for (int i = 0; i < n; i++)\
	{
		if (nums[i] == k)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	int n,k; cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> k;
	int t = linear_search(a, n, k);
	cout << t;

}