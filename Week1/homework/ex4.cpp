#include<iostream>
using namespace std;
void hanoi_tower(int n, char s, char t, int a)
{
	if (n == 1)
	{
		cout << "Move dish 1 from " << s << " to " << t << endl;
		return;
	}
	hanoi_tower(n - 1, s, t,a);
	cout << "move " << n - 1 << " dish from " << s << " to " << t << endl;
	hanoi_tower(n - 1, t, a, s);
	cout << "move " << n - 1 << " dish from " << t << " to " << a << endl;
	
}
int main()
{
	int n;
	cin >> n;
	char s='s', t='t', a='a';
	hanoi_tower(n, s, t, a);
}