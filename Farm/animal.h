#include <iostream>
#include <time.h> 
#include <windows.h>
#include<string>
#include<vector>
using namespace std;
int Random(int min, int max);
class Farm
{
public:
	class Animal;
	Farm(int NumberAnimal);
	int GetTotalMilk();
	int GetTotalChild();
	void addAnimal(Animal*);
	void Talk();
private:
	vector<Animal*> listAnimal;
};
class Farm::Animal
{
protected:
	int milkAmount;
	int childAmount;
public:
	Animal();
	virtual void Sound() = 0;
	virtual int MakeChild()=0;
	virtual int GetMilk()=0;
	virtual string TypeAnimal() = 0;
};

class Cow:public Farm::Animal// Milk can get 0-20
{
public:
	void Sound() override;
	int MakeChild() override;
	int GetMilk() override;
	string TypeAnimal() override;
};

class Goat :public Farm::Animal//Milk can get 0-10
{
public:
	void Sound() override;
	int MakeChild() override;
	int GetMilk() override;
	string TypeAnimal() override;
};

class Sheep :public Farm::Animal// Milk can get 0-5
{
public:
	void Sound() override;
	int MakeChild() override;
	int GetMilk() override;
	string TypeAnimal() override;
};