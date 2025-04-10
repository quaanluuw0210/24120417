#include<iostream>
using namespace std;
int fibonanci(int n)
{
	if(n==0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	return fibonanci(n - 1) + fibonanci(n - 2);
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t = fibonanci(i);
		cout << t << " ";
	}

}