#include<iostream>
using namespace std;
//Đặt lính canh là phần tử cuối cùng của mảng 
//Duyệt từ đầu đến khi gặp được phần tử có giá trị k
//Điều kiện trả về khi gặp được vị trí có giá trị k trước n-1(vị trí đặt lính canh) hoặc khi chính vị trí cuối cùng chứa lính canh
//Nếu không tìm thấy phần tử có giá trị k thì trả về -1
int linear_search_ws(int nums[], int n, int k)
{
	int last = nums[n - 1];
	nums[n - 1] == k;
	int i = 0;
	while (nums[i] != k)
	{
		i++;
	}
	nums[n - 1] = last;//Gán lại giá trị cũ cho nums[n-1]
	if (i < n - 1 || nums[n - 1] == k)
	{
		return i;
	}
	return -1;
}
int main()
{
	int n, k; cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> k;
	int t = linear_search_ws(a, n, k);
	cout << t;

}