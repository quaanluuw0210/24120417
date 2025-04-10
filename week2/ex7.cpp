#include<iostream>
using namespace std;
//Hàm meger để hợp mảng trong sắp xếp trộn
void meger(int nums[], int l, int r, int mid)
{
	int i = mid - l + 1;
	int j = r - mid;
	int* a = new int[i];
	int* b = new int[j];
	int x = 0, y = 0, z = 0;
	while (x < i)
	{
		a[x] = nums[l+ x];
			x++;
	}
	while (y < j)
	{
		b[y] = nums[mid + 1 + y];
			y++;
	}
	x = 0; y = 0;
	while (x < i && y < j)
	{
		if (a[x] < b[y])
		{
			nums[l + z] = a[x];
			z++; x++;
		}
		else
		{
			nums[l + z] = b[y];
			z++; y++;
		}
	}
	while (x < i)
	{
		nums[l + z] = a[x];
		z++; x++;
	}
	while (y<j)
	{
		nums[l + z] = b[y];
		z++; y++;
	}
}
//Hàm sắp xếp trộn để sắp xếp mảng tăng dần
void meger_sort(int nums[], int l, int r)
{
	if (l >= r)
	{
		return;
	}
	int mid = l + (r - l) / 2;
	meger_sort(nums, l, mid);
	meger_sort(nums, mid+1, r);
	meger(nums, l, r, mid);
}
//Ý tưởng sử kỹ thuật hai con trỏ nhung vì ở đây là tổng của ba số nên ta cố định một số và dùng kỹ thuật hai con trỏ để tìm kiếm phần còn lại
//Phần tử được cố dịnh lần lượt là các vị trí từ 0 đến n-1
//Phần tìm kiếm với 2 con trỏ phụ thuộc vào vị trí cùa phần tử cố định, giả sử là i thì vùng tìm kiếm là từ i+1 đến n-1;
void triplets(int nums[], int n)
{
	int i = 0;
	int t;
	while(i<n)
	{
		int l = i + 1;
		int r = n-1;
		
		while (l < r)
		{
			t = nums[i] + nums[l] + nums[r];
			if (t == 0)
			{
				cout << nums[i] << " " << nums[l] << " "<< nums[r] << "\n";
			}
			if (t < 0)
			{
				l++;
				while (l + 1 < r && nums[l + 1] == nums[l])
				{
					l++;
				}
				
			}
			else
			{
				r--;
				while (r - 1 > l && nums[r] == nums[r - 1])
				{
					r--;
				}
				
			}
		}
		
		while (i + 1 < n && nums[i] == nums[i + 1])
		{
			i++;
		}
		i++;
		

	}
}
int main()
{
	int n; cin >> n;
	int* a = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	meger_sort(a, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout<< a[i]<<" ";
	}
	cout << endl;
	triplets(a, n);
}