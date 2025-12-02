#include"animal.h"
#include<iostream>
#include<string>

using namespace std;


int main()
{
	Farm newFarm(10);
	newFarm.Talk();
	int milk = newFarm.GetTotalChild();
	cout << "Total milk of Farm: " << milk << endl;
	int child = newFarm.GetTotalChild();
	cout << "Total milk of Farm: " << child << endl;
}