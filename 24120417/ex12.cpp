#include<iostream>
using namespace std;
//Giam dan
bool descend(int num1, int num2)
{
	if (num1 > num2)
	{
		return 1;
	}
	return 0;
}
//Tang dan
bool ascend(int num1, int num2)
{
	if (num1 < num2)
	{
		return 1;
	}
	return 0;
}

void Merge(int arr[], int left,int mid, int right,bool (*p)(int,int))
{
	int* firstArray=new int[mid-left+1];
	int* secondArray=new int[right-mid];
	for (int i = 0; i < mid - left + 1; i++)
	{
		firstArray[i] = arr[left + i];
	}
	for (int i = 0; i < right - mid ; i++)
	{
		secondArray[i] = arr[mid + i+1];
	}
	int i = 0, j = 0, k=left;
	while (i < mid - left + 1 && j < right - mid )
	{
		if (p(firstArray[i],secondArray[j]))
		{
			arr[k] = firstArray[i];
			k++;
			i++;
			
		}
		else
		{
			arr[k] = secondArray[j];
			k++;
			j++;
		}
	}
	while (i < mid - left + 1 )
	{
		arr[k] = firstArray[i];
		k++;
		i++;
	}
	while (j < right - mid )
	{
		arr[k] = secondArray[j];
		j++;
		k++;
	}
	delete []firstArray;
	delete []secondArray;

}


void MergeSort(int arr[], int left, int right, bool (*p)(int, int))
{
	if (left >= right)
	{
		return;
	}
	int mid = left + (right - left) / 2;
	MergeSort(arr, left, mid, p);
	MergeSort(arr, mid + 1, right, p);
	Merge(arr, left, mid, right, p);
}



void Output(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


int main()
{
	cout << "Test 1:\n";
	
	int arr[10] = { 8, 9, 7, 1, 5, 4, 6, 3, 5, 4 };

	//Descending
	
	MergeSort(arr, 0, 9, descend);
	Output(arr, 10);
	
	//Ascending
	MergeSort(arr, 0, 9, ascend);
	Output(arr, 10);
	
	cout << "\nTest2:\n";

	int arr2[10] = { -3, 7, 0, -1, 5, -3, 2, 2, 9, -5 };

	// Descending
	MergeSort(arr2, 0, 9, descend);
	Output(arr2, 10);

	// Ascending
	MergeSort(arr2, 0, 9, ascend);
	Output(arr2, 10);

}