#include<iostream>
using namespace std;
//Hàm tìm kiếm độ dài nhỏ nhất của chuỗi con có tổng lớn hơn hoặc bằng giá trị "target"
//Ý tưởng áp dụng kỹ thuật cửa sổ trượt ở đây là cửa sổ có thay đổi kích thước để tận dụng giá trị tổng của các phần tử phía trước
//Ban đầu ta đặt bên trái của cửa sổ là j,bên phải là i 
//Khi tổng của các phần tử vẫn bé hơn target ta tăng i để mở rộng
//Ngược lại nếu nó lớn hơn hoặc bằng thì ta tăng j để thu hẹp lại
//Cập nhật min mỗi khi tổng lớn hơn hoặc bàng giá trị target
int min_length(int nums[], int n,int target,int &index)
{
	int length = 1,min=n;
	int l = 0, r = 0;
	int sum = nums[l];
	int sentinel = 0;
	while (l<=r&& r < n)
	{
		if (sum < target)
		{
			r++;
			if (r< n) {
				
				length++;
				sum = sum + nums[r];
			}
		}
		else
		{
			sentinel++;
			if (length < min)
			{
				min = length;
				index = l;
			}
			sum = sum-nums[l];
			l++;
			length--;
		}
	}	
	if(sentinel!=0)
	return min;
	return 0;
}

int main()
{
	int n,target,index=-1;
	cin >> n;
	int* nums=new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	cin >> target;
	int m = min_length(nums, n, target,index);
	cout << m<<"\n";
	int i = 0;
	if(index!=-1)
	while (i < m)
	{
		cout << nums[index+i] << " ";
		i++;
	}

}