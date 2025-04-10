#include<iostream>
using namespace std;
bool sorted(int a[],int n)
{
	if (n == 0)
	{
		return true;
	}
	if (a[n] < a[n - 1])
	{
		
		return false;
	}
	sorted(a, n - 1);
}
int main()
{
	int a[6] = {1,1,3,4,5,6};
	if (sorted(a,5))
	{
		cout << "SORTED";
	}
	else
	{
		cout << "NO SORTED";
	}

}