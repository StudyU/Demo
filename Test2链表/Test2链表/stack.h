#ifndef STACK_H_
#define  STACK_H_
#include "list.h"

template<class STACKTYPE>
class stack : private List<STACKTYPE>
{
public:
	void push(const STACKTYPE &value) {InsertAtFront(value);}
	bool pop(STACKTYPE &value) {return RemoveFromFront(value);}
	bool istackempty() const {return IsEmpty();}
	void printstack() const {print();}

};

#endif