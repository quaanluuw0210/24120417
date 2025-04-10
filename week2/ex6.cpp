#include<iostream>
using namespace std;
//Hàm sử dụng kỹ thuật hai con trỏ để tìm tổng của hai phần tử sao cho có tổng bàng "target" 
//Vì mảng đã sắp xếp nên phần tử cuối cùng có giá trị lớn nhất và phần tử đầu tiên có giá trị nhỏ nhất 
//Nếu tổng của hai phần tử đầu tiên và cuối cùng lơn hơn target thì ta giảm giá trị tổng bằng cách lấy giá trị của phần tử trước phần tử r
//Ngược lại ta tăng tổng bằng cách lấy giá trị của phần tử sau l
bool compare_sum(int nums[], int n,int target)
{
	int l = 0, r = n - 1;
	int t = nums[l] + nums[r];
	while (l < r)
	{
		t = nums[l] + nums[r];
		if (t == target)
		{
			return true;
		}
		if (t < target)
		{
			l++;
		}
		else
		{
			r--;
		}

	}
	return false;
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
	if (compare_sum(a, n, k))
	{
		cout << "CO";
	}
	else
	{
		cout << "KHONG";
	}
	
}