#include "pch.h"
#include <string>
#include <iostream>

using namespace System;
using namespace std;

class Animal {
protected:
	string name, nickname;
	short birthYear;

public:
	Animal();
	Animal(string n, string nick, short year);
	virtual ~Animal()
	{
		cout << "Object with values: ";
		Animal::print();
		cout << " destroyed!" << endl;
	}
	virtual void print() const;
	string GetName() const;
	string GetNickname() const;
	short GetBirthYear() const;

	void SetName(string n);
	void SetNickname(string nick);
	void SetBirthYear(short year);

};

class ZooAnimal : public Animal
{
private:
	int sector;

public:
	ZooAnimal() :Animal(), sector(0) {}
	ZooAnimal(string name, string nick, short year, int sector) : Animal(name, nick, year)
	{
		this->sector = sector;
	}

	virtual ~ZooAnimal()
	{
		cout << "Object with values: ";
		ZooAnimal::print();
		cout << " destroyed!" << endl;
	}

	virtual void print() const
	{
		Animal::print();
		cout << "Sector = " << sector;
	}

	int get_sector() const
	{
		return sector;
	}
	void set_sector(int sec)
	{
		this->sector = sec;
	}

};

Animal::Animal() : name("name"), nickname("Nickname"), birthYear(2020)
{}

Animal::Animal(string n, string nick, short year)
{
	name = n;
	nickname = nick;
	birthYear = year;
}

inline short Animal::GetBirthYear() const
{
	return  birthYear;
}
inline string Animal::GetName() const
{
	return name;
}

inline string Animal::GetNickname() const
{
	return nickname;
}

inline void Animal::print() const
{
	cout << "Name: " << name << " Nickname: " << nickname << " Birth Year: " << birthYear ;
}

inline void Animal::SetName(std::string n)
{
	name = n;
}

inline void Animal::SetBirthYear(short year)
{
	birthYear = year;
}

inline void Animal::SetNickname(string nick)
{
	nickname = nick;
}

int main(void)
{
	const int N = 3;

	Animal* animals[N ]
	{
		new Animal(),
		new ZooAnimal("Horse","H", 325, 5),
		new ZooAnimal("Volfy","V", 2010, 1)
	};
	
	cout << "Array of animals: " << endl;
	
	for (int i = 0; i < N; i++) {
		cout << (i + 1) << ". ";
		animals[i]->print();
		cout << endl;
	}
	cout << endl << endl;
	for (int i = 0; i < N; i++) {
		delete animals[i];
	}
	
	//
	// Animal* A2;
	//
	//
	// A2 = new Animal("Beep", "bop", 2020);

	// A2->SetName("NewName");
	//
	// (*A2).print();



	cout << "\n\n";

	return 0;
}
