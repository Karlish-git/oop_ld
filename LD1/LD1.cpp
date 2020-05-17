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
		cout << " Animal destroyed!" << endl;
	}

	string GetName() const;
	string GetNickname() const;
	short GetBirthYear() const;

	void SetName(string n);
	void SetNickname(string nick);
	void SetBirthYear(short year);
	friend ostream& operator << (ostream& O, const Animal& animal) {
		O << "Name: " << animal.name << " Nickname: " << animal.nickname << " BirthYear:" << animal.birthYear;
		return O;
	};

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
		cout << "ZooAnimal destroyed!" << endl;
	}

	int get_sector() const
	{
		return sector;
	}
	void set_sector(int sec)
	{
		this->sector = sec;
	}

	friend ostream& operator << (ostream& O, const ZooAnimal& zoo_animal) {
		O << (ZooAnimal&)zoo_animal << ", Sector= " << zoo_animal.sector;
		return O;
	};
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
	}

	Zoo& operator+=(const ZooAnimal& zoo_animal)
	{
		if (Length == MaxLength)
			throw OverflowExc(); // throw and return
		Animals[Length++] = new ZooAnimal(
			zoo_animal.GetName(), zoo_animal.GetNickname(),
			zoo_animal.GetBirthYear(), zoo_animal.get_sector());
		return *this;
	}

	friend ostream& operator << (ostream& O, const Zoo& zoo) {
		O << "Animals:" << endl;
		for (unsigned int i = 0; i < zoo.Length; i++) {
			O << (i + 1) << ". " << *(zoo.Animals[i]) << endl;
		}
		return O;
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

	Zoo* zoo = new Zoo(2);
	ZooAnimal* a_animal = new ZooAnimal("AAA", "A", 100, 5);
	ZooAnimal b_animal("BBB", "B", 10, 6);
	ZooAnimal c_animal("CCC", "C", 5, 4);
	ZooAnimal d_animal("DDD", "D", 54, 3);
	ZooAnimal e_animal("EEE", "E", 20, 2);


	try
	{
		*zoo += *a_animal;
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
		*zoo += b_animal;
		std::cout << "b_animal added" << endl;
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
		*zoo += b_animal;
		std::cout << "b_animal added second time." << endl;
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
