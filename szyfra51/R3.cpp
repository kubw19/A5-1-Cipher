#include "stdafx.h"
#include "R3.h"


R3::R3()
{
	this->length = 23;
	this->clockingBit = 10;
	this->characteristicBits = new int[4];
	this->characteristicBits[0] = 7;
	this->characteristicBits[1] = 20;
	this->characteristicBits[2] = 21;
	this->characteristicBits[3] = 22;
	bits = new bool[this->length];
	for (int i = 0; i < this->length; i++) {
		bits[i] = false;
	}
}


R3::~R3()
{
}

Tact * R3::clock(bool * entry)
{
	Tact* t = new Tact;
	bool wynik = bits[22] ^ bits[21];
	wynik = wynik ^ bits[20];
	wynik = wynik ^ bits[7];
	if (entry != nullptr)wynik = wynik ^ *entry;
	for (int i = 23; i >= 0; i--) { //przesuniêcie
		bits[i + 1] = bits[i];
	}
	bits[0] = wynik;
	t->clockingBit = bits[this->clockingBit];
	t->firstBit = bits[0];
	t->lastBit = bits[this->length - 1];
	this->ostatniTakt = t;
	return t;
}

