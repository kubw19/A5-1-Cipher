#pragma once
#include "LFSR.h"
class R3:public LFSR
{
public:
	R3();
	~R3();
	virtual Tact* clock(bool* entry = nullptr);
};

