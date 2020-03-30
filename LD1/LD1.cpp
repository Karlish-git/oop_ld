#include "pch.h"
#include <string>
#include <iostream>

using namespace System;
using namespace std;

class Animal {
private:
    string name, nickname;
    short birthYear;
	
public:
    Animal();
    Animal(string n, string nick, short year);
	~Animal()
	{
        cout << "Object destroyed !" << endl;
	}
    void print_animal() const ;
    string GetName() const;
    string GetNickname() const;
    short GetBirthYear() const ;

    void SetName(string n) ;
    void SetNickname(string nick) ;
    void SetBirthYear(short year) ;

};

Animal::Animal() : name("name"), nickname("Nickname"), birthYear(2000)
{
	
}

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

inline void Animal::print_animal() const 
{
	cout << "Name: " << name << " Nickname: "<< nickname << " Birth Year: " << birthYear <<"\n";
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

    Animal A1, * A2;

    A2 = new Animal("Beep", "bop", 20200);
    A1.print_animal();

    A1.SetBirthYear(A1.GetBirthYear() + 10);
    A1.print_animal();

    A2->SetName("NewName");
	
    (*A2).print_animal();
	
	
	
    cout << "\n\n";

    return 0;
}
