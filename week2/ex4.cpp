#include<iostream>
using namespace std;
//Hàm tính tổng số các phần tử trong mảng
int find_sum(int ship[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = sum + ship[i];
	}
	return sum;
}
//Hàm kiểm tra xem sức chứa "cap" có thỏa mãn số ngày "day" không
//Hàm bắt đầu bằng cách tổng các gói hàng từ 1 đến n
//Nếu khối lượng các gói hàng lớn hơn sức chứa ta buộc phải tăng thêm 1 ngày
//Khi đến gói hàng cuối cùng nếu số ngày cần nhỏ hơn số ngày lý thuyết thì sức chứa thỏa mãn
bool trong_luong(int day,int cap, int ship[], int n)
{
	int i = 0;
	int t = 1;
	int sum = 0;
	while (i < n)
	{
		sum = sum + ship[i];
		if (sum > cap)
		{
			sum = ship[i];
			t++;
			
		}
		i++;
		
	}
	if (t<= day)
	{
		
		return true;
	}
	return false;
}
//Hàm tìm kiếm sức chứa thoải mãn yêu cầu số ngày vận chuyển 
//Chạy từ i=1 đến t tức là sức chứa con tàu nhỏ nhất là 1 và lớn nhất là vô cùng nhưng ta chỉ xét đến khối lượng toàn bộ số hàng 
//Lý do bởi vì nếu nó có sức chứa là toàn bộ trọng lượng hàng nó sé trở được trong 1 ngày đây cũng là giá trị nhỏ nhất của số ngày yêu cầu
void find_capacity(int ship[], int n, int day, bool *cap)
{
	int t=find_sum(ship, n);
	for (int i = 1; i <t+1;i++)
	{
		cap[i] = trong_luong(day,i, ship, n);
	}
}
//Hàm tìm kiếm áp dụng tìm kiếm nhị phân để tìm phần tử true đầu tiên trong mảng cap[]
//Nếu phần tử ở giữa là true ta thu hẹp mảng lại bằng cách loại bỏ các phần tử phía sau vì nó cũng là true và chác chắn không phải đầu tiên
//Nếu phần tử ở giũa là false thì ta bỏ các phàn tử phía trước đi vì chắc chắn nó cũng là false
int binary_search(bool cap[], int left, int right)
{
	int mid = left + (right - left) / 2;
	int min = right;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (cap[mid] == true && mid < min)
		{
			min = mid;
		}
		if (cap[mid] == true)
		{
			right = mid;
		}
		else
		{
			left = mid+1 ;
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
	cin >> k;
	int t = find_sum(a, n);
	bool* cap = new bool[t+1];
	find_capacity(a, n, k, cap);
	int quam = binary_search(cap, 0, t);
	cout << quam;
}
