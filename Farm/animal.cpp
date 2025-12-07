#include"Animal.h"
#include<time.h>
#include<windows.h>
#include<string>
using namespace std;

int Random(int min, int max)
{
	static bool first = true;
	if (first)
	{
		srand(time(NULL));
		first = false;
	}
	return min + rand() % (max - min + 1);
}
Farm::Animal::Animal()
{
	this->childAmount = 0;
	this->milkAmount = 0;
}
void Farm::addAnimal(Animal*newAnimal)
{
	this->listAnimal.push_back(newAnimal);
}
int Farm::GetTotalMilk() 
{
	int total = 0;
	for (int i = 0; i < this->listAnimal.size(); i++)
	{
		total += this->listAnimal[i]->GetMilk();
	}
	return total;
}
int Farm::GetTotalChild()
{
	int total = 0;
	int oldSize = this->listAnimal.size();
	for (int i = 0; i <oldSize ; i++)
	{
		int NumberOfNewAnimal= this->listAnimal[i]->MakeChild();
		total += NumberOfNewAnimal;
		while (NumberOfNewAnimal >= 0)
		{
			if (this->listAnimal[i]->TypeAnimal() == "Cow")
			{
				Cow* newCow = new Cow();
				this->addAnimal(newCow);
			}
			else if (this->listAnimal[i]->TypeAnimal() == "Goat")
			{
				Goat* newGoat = new Goat();
				this->addAnimal(newGoat);
			}
			else
			{
				Sheep* newSheep = new Sheep();
				this->addAnimal(newSheep);
			}
			NumberOfNewAnimal--;
		}
		
	}
	return total;
}
void Farm::Talk()
{
	for (int i = 0; i < this->listAnimal.size(); i++)
	{
		this->listAnimal[i]->Sound();
	}
}
Farm::Farm(int NumberAnimal)
{
	for (int i = 0; i < NumberAnimal; i++)
	{
		int randomTypeAnimal = Random(1, 3);
		if (randomTypeAnimal == 1)
		{
			Cow* newCow = new Cow();
			this->addAnimal(newCow);
		}
		else if (randomTypeAnimal == 2)
		{
			Goat* newGoat = new Goat();
			this->addAnimal(newGoat);
		}
		else
		{
			Sheep* newSheep = new Sheep();
			this->addAnimal(newSheep);
		}
	}
}

// Cow Implement
void Cow::Sound()
{
	cout << "A COW IS TALKING:\n";
	PlaySound(TEXT("COW.wav"), NULL, SND_FILENAME | SND_SYNC);
}
string Cow::TypeAnimal()
{
	return "Cow";
}
int Cow::MakeChild()
{
	this->childAmount = Random(1, 5);
	return this->childAmount;
}
int Cow::GetMilk()
{
	this->milkAmount = Random(0, 20);
	return this->milkAmount;
}
// Goat Implement
void Goat::Sound()
{
	cout << "A GOAT IS TALKING:\n";
	PlaySound(TEXT("GOAT.wav"), NULL, SND_FILENAME | SND_SYNC);
}
string Goat::TypeAnimal()
{
	return "Goat";
}
int Goat::MakeChild()
{
	this->childAmount = Random(1, 5);
	return this->childAmount;
}
int Goat::GetMilk()
{
	this->milkAmount = Random(0, 20);
	return this->milkAmount;
}
// Sheep Implement
void Sheep::Sound()
{
	cout << "A SHEEP IS TALKING:\n";
	PlaySound(TEXT("SHEEP.wav"), NULL, SND_FILENAME | SND_SYNC);
}
string Sheep::TypeAnimal()
{
	return "Sheep";
}
int Sheep::MakeChild()
{
	this->childAmount = Random(1, 5);
	return this->childAmount;
}
int Sheep::GetMilk()
{
	this->milkAmount = Random(0, 20);
	return this->milkAmount;
}

