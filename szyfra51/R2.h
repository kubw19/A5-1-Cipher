#pragma once
#include "LFSR.h"
class R2:public LFSR
{
public:
	R2();
	~R2();
	virtual Tact* clock(bool* entry = nullptr);
};

