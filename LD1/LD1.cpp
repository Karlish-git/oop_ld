#include "pch.h"
#include <string>
#include <iostream>


using namespace std;

class OverflowExc { // var jau sseit pabeigt ar };
};

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
		Animal::Print();
		cout << " destroyed!" << endl;
	}
	virtual void Print() const;
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
		ZooAnimal::Print();
		cout << " destroyed!" << endl;
	}

	virtual void Print() const
	{
		Animal::Print();
		cout << " Sector = " << sector;
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

class Zoo
{
private:
	typedef ZooAnimal* ZAnimal;
	ZAnimal* Animals;
	static const unsigned int DEFAULT_MAX_LENGTH = 5;
	unsigned int MaxLength;
	unsigned int Length;
public:
	Zoo() : MaxLength(DEFAULT_MAX_LENGTH), Length(0) {
		Animals = new ZAnimal[MaxLength];
	}
	Zoo(unsigned int MaxLength) : MaxLength(MaxLength), Length(0) {
		Animals = new ZAnimal[MaxLength];
	}
	~Zoo() {
		for (unsigned int i = 0; i < Length; i++)
			delete Animals[i];
		delete[] Animals;
	};
	static unsigned int GetDefaultMaxLength() {
		return DEFAULT_MAX_LENGTH;
	}
	int GetMaxLength() const {
		return MaxLength;
	}
	int GetLength() const {
		return Length;
	}

	void Add(const ZooAnimal& animal)
	{
		if (Length == MaxLength)
			throw OverflowExc(); // throw and return
		Animals[Length++] = new ZooAnimal(
			animal.GetName(), animal.GetNickname(), animal.GetBirthYear(), animal.get_sector());
	};

	void  Print() const {
		cout << endl << "Line's nodes:" << endl;
		for (unsigned int i = 0; i < Length; i++) {
			cout << (i + 1) << ". ";
			Animals[i]->Print();
			cout << "." << endl;
		}
	};

	short GetMinBirth() const
	{
		short min = Animals[0]->GetBirthYear();
		for (unsigned int i = 1; i < Length; i++) {
			if (Animals[i]->GetBirthYear() < min)
			{
				min = Animals[i]->GetBirthYear();
			}
		}
		return min;
	};
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

inline void Animal::Print() const
{
	cout << "Name: " << name << " Nickname: " << nickname << " Birth Year: " << birthYear;
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

	cout << "\n\nDefault maximal length (from CLASS): " <<
		Zoo::GetDefaultMaxLength() << "." << endl;
	
	Zoo *zoo = new Zoo(2);
	ZooAnimal *a_animal = new ZooAnimal("AAA", "A", 100, 5);
	ZooAnimal b_animal("BBB", "B", 10, 6);
	ZooAnimal c_animal("CCC", "C", 5, 4);
	ZooAnimal d_animal("DDD", "D", 54, 3);
	ZooAnimal e_animal("EEE", "E", 20, 2);


	try
	{
		zoo->Add(*a_animal);
		std::cout << "a_animal added" << endl;
	}
	catch (const OverflowExc)
	{
		cout << "*** Error: maximal length exceeded ! ***" << endl;
	}
	catch (...) {
		cout << "Unknown Error !" << endl;
	}
	
	delete a_animal;


	cout << "Maximal length: " << zoo->GetMaxLength() << "." << endl;
	cout << "Current length: " << zoo->GetLength() << "." << endl;


	try
	{
		zoo->Add(b_animal);
		std::cout << "a_animal added" << endl;
	}
	catch (const OverflowExc)
	{
		cout << "*** Error: maximal length exceeded ! ***" << endl;
	}
	catch (...) {
		cout << "Unknown Error !" << endl;
	}
	cout << "Current length: " << zoo->GetLength() << "." << endl;

	try
	{
		zoo->Add(b_animal);
		std::cout << "a_animal added" << endl;
	}
	catch (const OverflowExc)
	{
		cout << "*** Error: maximal length exceeded ! ***" << endl;
	}
	catch (...) {
		cout << "Unknown Error !" << endl;
	}
	cout << "Current length: " << zoo->GetLength() << "." << endl;

	cout << "Min birth year:" << zoo->GetMinBirth();
	
	cout << "\n\n";
	return 0;
}
