#pragma once
#include "Tact.h"
#include <iostream>
class LFSR
{
protected:
	int length;
	int clockingBit;
	bool* bits;
	int* characteristicBits;
public:
	Tact * ostatniTakt;
	LFSR();
	~LFSR();

	virtual Tact* clock(bool* entry = nullptr) = 0;
	void echo();
};

