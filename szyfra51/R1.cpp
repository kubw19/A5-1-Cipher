#include "stdafx.h"
#include "R1.h"


R1::R1()
{
	this->length = 19;
	this->clockingBit = 8;
	this->characteristicBits = new int[4];
	this->characteristicBits[0] = 13;
	this->characteristicBits[1] = 16;
	this->characteristicBits[2] = 17;
	this->characteristicBits[3] = 18;
	bits = new bool[this->length];
	for (int i = 0; i < this->length; i++) {
		bits[i] = false;
	}
}


R1::~R1()
{
}

Tact * R1::clock(bool * entry)
{
	Tact* t = new Tact;
	bool wynik = bits[18] ^ bits[17];
	wynik = wynik ^ bits[16];
	wynik = wynik ^ bits[13];
	if (entry != nullptr)wynik = wynik ^ *entry;
	for (int i = 19; i >= 0; i--) { //przesuniêcie
		bits[i + 1] = bits[i];
	}
	bits[0] = wynik;
	t->clockingBit = bits[this->clockingBit];
	t->firstBit = bits[0];
	t->lastBit = bits[this->length - 1];
	this->ostatniTakt = t;
	return t;
}
