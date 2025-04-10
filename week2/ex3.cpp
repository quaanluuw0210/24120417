#include<iostream>
using namespace std;
//Hàm tìm kiếm nhị phân 
//Vì đây là một mảng đã được sắp xếp (dù thứ tự đã thay đổi) nên ta có thể áp dụng tìm kiếm nhị phân 
//Ý tưởng ở đây là so sánh phần tử ở giũa với phần tử cuối cùng để có thể bỏ đi một nửa mảng 
//Ta so sánh phần tử ở giữa với cuối cùng nếu nó bé hơn tức là mảng con từ mid->right có Min là giá trị mid
//Ngược lại nếu phần tử ở giũa lớn hơn phần tử cuối cùng thì tức là mảng đã bị quay và min nằm trong đoạn từ mid->right
int binary_search(int nums[], int l, int r)
{
	int mid = l + (r - l) / 2;
	int min = nums[mid];
	while (l < r)
	{
		mid = l + (r - l) / 2;
		if (nums[mid] < min)
		{
			min = nums[mid];
		}
		if (nums[mid]>nums[r])
		{
			l = mid + 1;
		}
		else
		{
			r = mid;
		}
		
	}
	return min;
}
int main()
{
	int n, k; cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int t = binary_search(a, 0,n-1);
	cout << t;

}