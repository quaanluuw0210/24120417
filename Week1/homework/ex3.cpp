#include<iostream>
#include<string>
using namespace std;

void generateBinaryStrings(int n, string str)
{
	if (n == 0)
	{
		cout << str<<"\n";
		return;
	}
	generateBinaryStrings(n - 1, str+'0');		
	generateBinaryStrings(n - 1, str+'1');
}
int main()
{
	string str;
	generateBinaryStrings(3, str);
}