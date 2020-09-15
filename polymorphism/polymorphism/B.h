#pragma once
#include "A.h"
class B :
    public A
{
public:
	int val = 6;

	B();
	void print() const;
};

