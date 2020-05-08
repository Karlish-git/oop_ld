#include "pch.h"
#include <string>
#include <iostream>

#include <vector>


using namespace std;

class OverflowExc { // var jau sseit pabeigt ar };
};

template <class	T>
class Animal {
protected:
	string name, nickname;
	T birthYear;

public:
	Animal();
	Animal(string n, string nick, T birth_year);
	virtual ~Animal()
	{
		cout << "Object with values: ";
		Animal::Print();
		cout << " destroyed!" << endl;
	}

	string GetName() const;
	string GetNickname() const;
	T GetBirthYear() const;

	void SetName(string n);
	void SetNickname(string nick);
	void SetBirthYear(short year);

	virtual void Print() const;
};

template <class T>
class ZooAnimal : public Animal<T>
{
private:
	int sector;

public:
	ZooAnimal() :Animal<T>(), sector() {}
	ZooAnimal(const string name, const string nick,
		const short year, const int sector) : Animal<T>(name, nick, year)
	{
		this->sector = sector;
	}

	virtual ~ZooAnimal()
	{
		cout << "Object with values: ";
		ZooAnimal::Print();
		cout << " destroyed!" << endl;
	}

	void Print() const
	{
		Animal<T>::Print();
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


template <class T>
class Zoo
{
private:
	typedef ZooAnimal<T>* ZAnimal;
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

	void Add(const ZooAnimal<T>& animal)
	{
		if (Length == MaxLength)
			throw OverflowExc(); // throw and return
		Animals[Length++] = new ZooAnimal<T>(
			animal.GetName(), animal.GetNickname(), animal.GetBirthYear(), animal.get_sector());
	};

	void  Print() const {
		cout << endl << "Zoo nodes:" << endl;
		for (unsigned int i = 0; i < Length; i++) {
			cout << (i + 1) << ". ";
			Animals[i]->Print();
			cout << "." << endl;
		}
	};

	short GetMinBirth() const
	{
		unsigned short min = Animals[0]->GetBirthYear();
		for (unsigned int i = 1; i < Length; i++) {
			if (Animals[i]->GetBirthYear() < min)
			{
				min = Animals[i]->GetBirthYear();
			}
		}
		return min;
	};
};

template <class T>
Animal<T>::Animal() : name("name"), nickname("Nickname"), birthYear(2020)
{}

template <class T>
Animal<T>::Animal(string n, string nick, T year)
{
	name = n;
	nickname = nick;
	birthYear = year;
}

template <class T>
inline T Animal<T>::GetBirthYear() const
{
	return  birthYear;
}

template <class T>
inline string Animal<T>::GetName() const
{
	return name;
}

template <class T>
inline string Animal<T>::GetNickname() const
{
	return nickname;
}

template <class T>
inline void Animal<T>::Print() const
{
	cout << "Name: " << name << " Nickname: " << nickname << " Birth Year: " << birthYear;
}

template <class T>
inline void Animal<T>::SetName(std::string n)
{
	name = n;
}


template <class T>
inline void Animal<T>::SetBirthYear(short year)
{
	birthYear = year;
}

template <class T>
inline void Animal<T>::SetNickname(string nick)
{
	nickname = nick;
}




int main(void)
{

	// cout << "\n\nDefault maximal length (from CLASS): " <<
	// 	Zoo::GetDefaultMaxLength() << "." << endl;

	Zoo<unsigned short>* zoo_short = new Zoo<unsigned short>(2);
	Zoo<unsigned int>* zoo_int = new Zoo<unsigned int>(2);

	ZooAnimal<unsigned short>* a_animal = new ZooAnimal<unsigned short>("AAA", "A", 100, 5);
	ZooAnimal<unsigned short> b_animal("BBB", "B", 10, 6);
	ZooAnimal<unsigned int> c_animal("CCC", "C", 5, 4);
	ZooAnimal<unsigned int> d_animal("DDD", "D", 54, 3);
	ZooAnimal<unsigned int> e_animal("EEE", "E", 20, 2);




	cout << "\tSHORT ZOO" << endl;

	try
	{
		zoo_short->Add(*a_animal);
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


	cout << "Maximal length: " << zoo_short->GetMaxLength() << "." << endl;
	cout << "Current length: " << zoo_short->GetLength() << "." << endl;


	try
	{
		zoo_short->Add(b_animal);
		std::cout << "b_animal added" << endl;
	}
	catch (const OverflowExc)
	{
		cout << "*** Error: maximal length exceeded ! ***" << endl;
	}
	catch (...) {
		cout << "Unknown Error !" << endl;
	}

	cout << "Current length: " << zoo_short->GetLength() << "." << endl;

	try
	{
		zoo_short->Add(b_animal);
		std::cout << "a_animal added" << endl;
	}
	catch (const OverflowExc)
	{
		cout << "*** Error: maximal length exceeded ! ***" << endl;
	}
	catch (...) {
		cout << "Unknown Error !" << endl;
	}

	cout << "Current length: " << zoo_short->GetLength() << "." << endl;
	cout << "Min birth year:" << zoo_short->GetMinBirth();
	zoo_short->Print();


	//----------Int---------
	cout << "\tINT ZOO" << endl;

	try
	{
		zoo_int->Add(c_animal);
		std::cout << "b_animal added" << endl;
	}
	catch (const OverflowExc)
	{
		cout << "*** Error: maximal length exceeded ! ***" << endl;
	}
	catch (...) {
		cout << "Unknown Error !" << endl;
	}
	cout << "Current length: " << zoo_int->GetLength() << "." << endl;

	try
	{
		zoo_int->Add(d_animal);
		cout << "a_animal added" << endl;
	}
	catch (const OverflowExc)
	{
		cout << "*** Error: maximal length exceeded ! ***" << endl;
	}
	catch (...) {
		cout << "Unknown Error !" << endl;
	}

	cout << "Current length: " << zoo_int->GetLength() << "." << endl;
	cout << "Min birth year:" << zoo_int->GetMinBirth();
	cout << "\n\n";

	return 0;
}

