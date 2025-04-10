#include<iostream>
int find_min(int nums[], int n, int i)
{
	int min = i;
	for (int t = i; t < n; t++)
	{
		if (nums[t] < nums[min])
		{
			min = t;
		}
	}
	return min;
} 
int find_max(int nums[], int n, int i)
{
	int max = nums[i];
	for (int t =i ; t < n; t++)
	{
		if (max < nums[t])
		{
			max = nums[t];
		}
	}
	return max;
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void selection_sort(int nums[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int m = find_min(nums, n, i);
		swap(nums[i], nums[m]);
	}
}
void insertion_sort(int nums[], int n)
{
	int i = 1;
	while (i < n)
	{
		int key = nums[i];
		int j = i - 1;
		while (j >= 0 && key < nums[j])
		{
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j+1] = key;
		i++;
	}
}
void bubble_sort(int nums[], int n)
{
	for (int i = 0; i < n; i++)
	{
		
		for (int j = i; j < n; j++)
		{
			
			if (nums[i] > nums[j])
			{
				swap(nums[i], nums[j]);
			}
		}
	}
}
void heapify(int nums[], int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (right<n && nums[right]>nums[largest])
	{
		largest = right;
	}
	if (left<n && nums[left]>nums[largest])
	{
		largest = left;
	}
	
	if (largest != i)
	{
		swap(nums[largest], nums[i]);
		heapify(nums, n, largest);
	}
}
//Ham heap_sort bien count dung de dem so lan so sanh
void heap_sort(int nums[], int n)
{
	for (int i = (n / 2) - 1; i >= 0; i--)
	{
		
		heapify(nums, n, i);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		
		swap(nums[i], nums[0]);
		heapify(nums, i, 0);
	}
}
void shaker_sort(int nums[], int n)
{
	int s = 0,e=n-1;
	bool swapped=1;
	while (swapped)
	{
		swapped = false;
		for (int i = s; i < e; i++)
		{
			
			if (nums[i] > nums[i + 1])
			{
				swap(nums[i], nums[i + 1]);
				swapped = true;
			}
		}
		if (swapped==false)
		{
			break;
		}
		e--;
		swapped = false;
		for (int i = e ; i > s; i--)
		{
			if (nums[i] <nums[i - 1])
			{
				swap(nums[i], nums[i - 1]);
				swapped = true;
			}
		}
		s++;
	}
}
//Thuật toán shell sort
void shell_sort(int nums[], int n)
{
	
	int gap = (n) / 2;
	while (gap >= 1)
	{
		
		for (int i = gap; i<n; i++)
		{
			
			int key = nums[i];
			int j = i;
			while (j-gap >= 0 && nums[j-gap] > key)
			{
				nums[j] = nums[j-gap];
				j=j-gap;
			}
			nums[j] = key;
			
		}
		gap = gap / 2;
	}
}
void merge(int nums[], int left, int mid, int right)
{
	int i = mid - left+1;
	int j = right - mid;
	int* a = new int[i];
	int* b = new int[j];
	for (int t = 0; t < i; t++)
	{
		a[t] = nums[left + t];
	}
	for (int t = 0; t <j;t++)
	{
		b[t] = nums[mid + 1 + t];
	}
	int x = 0, y = 0, z = 0;
	while (x < i && y < j)
	{
		if (a[x] <= b[y])
		{
			nums[left + z] = a[x];
			x++; z++;
		}
		else
		{
			nums[left + z] = b[y];
			y++; z++;
		}
	}
	while (x < i)
	{
		nums[left+z] = a[x];
		x++; z++;
	}
	while (y < j)
	{
		nums[left + z] = b[y];
		y++; z++;
	}
	delete []a;
	delete []b;
}
void merge_sort(int nums[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		merge_sort(nums, left, mid);
		merge_sort(nums, mid + 1, right);
		merge(nums, left, mid, right);
	}
}
int  phanhoach(int* a, int l, int r)
{
	int i = l - 1;
	int j = r + 1;
	int pivot = a[l];
	while (1)
	{
		do
		{
			i++;
		} while (a[i] < pivot);
		do
		{
			j--;
		} while (a[j] > pivot);
		if (i < j)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		else return j;
	}
}

void quicksort(int a[], int l, int r)
{
	if (l >= r) return;
	int m = phanhoach(a, l, r);
	quicksort(a, l, m);
	quicksort(a, m + 1, r);
}
void counting_sort(int nums[], int n)
{
	int m=find_max(nums,n,0);
	int* sort = new int[m + 1];
	for (int i = 0; i < m + 1; i++)
	{
		sort[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		sort[nums[i]]++;
	}
	for (int i = 0; i < m+1; i++)
	{
		if (sort[i] != 0)
		{
			int t = sort[i]; 
			while (t > 0)
			{
				std::cout << i << " ";
				t--;
			}
		}
	}
	delete[]sort;
}
void counting(int nums[], int n, int expx)
{
	int count[10] = { 0 };
	for (int i = 0; i < n; i++) {
		count[(nums[i] / expx) % 10]++;
	}

	std::cout << "\n";
	for (int i = 1; i < 10; i++)
	{
		count[i] = count[i - 1] + count[i];
	}
	int* output = new int[n];
	for (int i = n - 1; i >= 0; i--)
	{
		int digit = ((nums[i] / expx) % 10);
		output[count[digit] - 1] = nums[i];
		count[digit]--;
	}
	for (int i = 0; i < n; i++)
	{
		nums[i] = output[i];
	}

}
void radix_sort(int nums[], int n)
{
	int m = find_max(nums, n, 0);
	for (int expx = 1; m / expx > 0; expx = expx * 10)
	{
		counting(nums, n, expx);
	}
}
void flashsort(int a[], int n)
{

	int m = floor(0.45 * n);
	int* l = new int[m];
	for (int i = 0; i < m; i++)
	{
		l[i] = 0;
	}
	int max = a[0]; int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max) max = a[i];
		if (a[i] < min) min = a[i];
	}
	if (max == min) {
		delete[] l;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		int  k = floor((double)(m - 1) * (a[i] - min) / (max - min));
		l[k]++;
	}
	for (int i = 1; i < m; i++)
	{
		l[i] += l[i - 1];
	}
	int hold = a[0];
	int move = 0;
	int flash = 0;
	int t = 0;
	int j = 0;
	int k = 0;
	while (move < n - 1)
	{
		while (j > (l[k] - 1))
		{
			j++;
			k = floor((double)(m - 1) * (a[j] - min) / (max - min));
		}
		flash = a[j];
		while (j != l[k])
		{
			k = floor((double)(m - 1) * (a[j] - min) / (max - min));
			hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			move++;
		}
		j++;
		if (j >= n) break;
	}
	for (int i = 1; i < n; i++)
	{
		int hold = a[i];
		int j = i - 1;;
		while (j >= 0 && a[j] > hold)
		{
			a[j + 1] = a[j--];

		}
		a[j + 1] = hold;
	}
	delete[] l;
}