

#ifndef _ID_CPP
#define _ID_CPP

#include "id.h"
#include <cstring>
#include <iomanip>

ID::ID(): name_(0), age_(0)
{
	SetName(DEFAULT_NAME);
	SetAge(DEFAULT_AGE);
}


ID::ID(const char* name, int age): name_(0), age_(0)
{
	SetName(name);
	SetAge(age);
}


ID::ID(const ID& rhs): name_(0), age_(0)
{
	SetName(rhs.GetName());
	SetAge(rhs.GetAge());
}


const ID& ID::operator=(const ID& rhs)
{
	if(this != &rhs)
	{
		SetName(rhs.GetName());
		SetAge(rhs.GetAge());
	}
	return *this;
}



ID::~ID()
{
	delete[] name_;
}


void ID::SetName(const char* name)
{
	if(name_ != NULL)
		delete [] name_;
	name_ = new char[strlen(name) + 1];
	strcpy(name_, name);
	name_[ strlen(name) ] = '\0';
}


void ID::SetAge(int age)
{
	age_ = age;
}


const char* ID::GetName() const
{
	return name_;
}


int ID::GetAge() const
{
	return age_;
}


std::ostream& operator << (std::ostream& stream, const ID& rhs)
{
	stream << rhs.GetName() << "\t" << rhs.GetAge();
	return stream;
}

std::istream& operator>> ( std::istream& is , ID& id ){
	char* name = new char[121];
	int age;
	cout << "Enter the name: ";
	is >> std::setw(121) >>name;
	id.SetName(name);
	
	cout << "Enter the age: ";
	is >> age;
	id.SetAge(age);
	
	return is;
	
}

bool operator< ( const ID& id1 , const ID& id2 ){
	int d = DictionaryDiff(id1.GetName(), id2.GetName());
	if(d < 0){
		return true;
	}
	else if(d > 0){
		return false;
	}
	else if(d == 0){
		if(id1.GetName() < id2.GetName())
			return true;
	}
	return false;
}

#endif
