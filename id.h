/*
 id.h
 Nick Zelada
 09/21/17
 */

#ifndef _ID_H
#define _ID_H

#include <iostream>  //needed for std::ostream
#include "cstringdiff.h"
const int DEFAULT_AGE = -1;

const char* const DEFAULT_NAME = "#";

class ID
{
	
public:
	ID();
	ID(const char*, int);
	ID(const ID&);
	~ID();
	const ID& operator=(const ID&);
	
	void        SetName( const char* );
	void        SetAge ( int );
	const char* GetName() const;
	int         GetAge () const;
	
private:
	char * name_;
	int age_;
	
};

std::ostream& operator << (std::ostream&, const ID&);
std::istream& operator>> ( std::istream& is , ID& id );
bool operator< ( const ID& id1 , const ID& id2 );

#endif
