#include<iostream>
using namespace std;

template <typename T>

//Giam dan 
bool Descending(T first, T second)
{
	if (first > second)
	{
		return 1;
	}
	return 0;
}

template<typename T>

//Tang dan
bool Ascending(T first, T second)
{
	if (first < second)
	{
		return 1;
	}
	return 0;
}
template <typename T>

void Sort(T arr[], int n,bool (*p)(T,T))
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (p(arr[j],arr[i]))
			{
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
}


template<typename T>
void Output(T arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


int main()
{
	//Char data type
	cout << "char[]\n";
	char cArray[10] = "ajfielmut";
	Sort(cArray, 10,Ascending);
	Output(cArray, 10);
	Sort(cArray, 10, Descending);
	Output(cArray, 10);


	//Int data type
	cout << "\nint[]\n";
	int iArray[10] = { 4, 5, 6, 2, 1, 3, 4, 7, 8, 88 };
	Sort(iArray, 10, Ascending);
	Output(iArray, 10);
	Sort(iArray, 10, Descending);
	Output(iArray, 10);


	// Float data type
	cout << "\nfloat[]\n";
	float fArray[10] = { 3.14f, -2.71f, 0.0f, 1.618f, -9.99f, 7.77f, 12.34f, -0.5f, 6.66f, 2.22f };
	Sort(fArray, 10, Ascending);
	Output(fArray, 10);
	Sort(fArray, 10, Descending);
	Output(fArray, 10);

}