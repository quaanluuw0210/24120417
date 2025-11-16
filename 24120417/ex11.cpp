#include<iostream>
using namespace std;
template<typename T>


void Sort(T arr[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}


template<typename T>
void Output(T arr[], int n)
{
	for (int i = 0; i < n ; i++)
	{
		cout << arr[i] <<" ";
	}
	cout << endl;
}


int main()
{
	//Char data type
	char cArray[10] = "ajfielmut";
	Sort(cArray, 10);
	Output(cArray, 10);


	//Int data type
	int iArray[10] = { 4, 5, 6, 2, 1, 3, 4, 7, 8, 88 };
	Sort(iArray, 10);
	Output(iArray, 10);


	//Float data type
	float fArray[10] = { 4.5, 6.99, 4.6, 7.888, 15.0001, 16.456, 0.2222, 78.78, 45.23, 12.01 };
	Sort(fArray, 10);
	Output(fArray, 10);
	
}