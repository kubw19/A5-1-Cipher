#include "stdafx.h"
#include "R2.h"


R2::R2()
{
	this->length = 22;
	this->clockingBit = 10;
	this->characteristicBits = new int[2];
	this->characteristicBits[0] = 20;
	this->characteristicBits[1] = 21;
	bits = new bool[this->length];
	for (int i = 0; i < this->length; i++) {
		bits[i] = false;
	}
}


R2::~R2()
{
}

Tact * R2::clock(bool * entry)
{
	Tact* t = new Tact;
	bool wynik = bits[20] ^ bits[21];
	if (entry != nullptr)wynik = wynik ^ *entry;
	for (int i = 22; i >= 0; i--) { //przesuniêcie
		bits[i + 1] = bits[i];
	}
	bits[0] = wynik;
	t->clockingBit = bits[this->clockingBit];
	t->firstBit = bits[0];
	t->lastBit = bits[this->length - 1];
	this->ostatniTakt = t;
	return t;
}

