#include "stdafx.h"
#include "LFSR.h"


LFSR::LFSR()
{
}



LFSR::~LFSR()
{
}

void LFSR::echo()
{
	for (int i = 0; i < this->length; i++) {
		std::cout << bits[i];
	}
	std::cout << std::endl;
}
