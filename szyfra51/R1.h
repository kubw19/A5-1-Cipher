#pragma once
#include "LFSR.h"
class R1:public LFSR
{
public:
	R1();
	~R1();
	virtual Tact* clock(bool* entry = nullptr);

};

