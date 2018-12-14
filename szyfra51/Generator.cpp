#include "stdafx.h"
#include "Generator.h"


Generator::Generator(bool* sessionKey, bool* frame)
{
	this->sessionKey = sessionKey;
	this->frame = frame;

}


Generator::~Generator()
{
}

void Generator::loadSessionKey()
{
	for (int i = 0; i<64; i++) {
		r1.clock(&sessionKey[i]);
		r2.clock(&sessionKey[i]);
		r3.clock(&sessionKey[i]);
	}
}

void Generator::loadFrame()
{
	for (int i = 0; i<22; i++) {
		r1.clock(&frame[i]);
		r2.clock(&frame[i]);
		r3.clock(&frame[i]);
	}
}

void Generator::irregularClocking()
{
	for (int i = 0; i < 100; i++) {
		if(r1.ostatniTakt->clockingBit==0 && r2.ostatniTakt->clockingBit == 0 && r3.ostatniTakt->clockingBit == 0){
			r1.clock();
			r2.clock();
			r3.clock();
		}
		else if (r1.ostatniTakt->clockingBit == 0 && r2.ostatniTakt->clockingBit == 0 && r3.ostatniTakt->clockingBit == 1) {
			r1.clock();
			r2.clock();
		}
		else if (r1.ostatniTakt->clockingBit == 0 && r2.ostatniTakt->clockingBit == 1 && r3.ostatniTakt->clockingBit == 0) {
			r1.clock();
			r3.clock();
		}
		else if (r1.ostatniTakt->clockingBit == 0 && r2.ostatniTakt->clockingBit == 1 && r3.ostatniTakt->clockingBit == 1) {
			r2.clock();
			r3.clock();
		}
		else if (r1.ostatniTakt->clockingBit == 1 && r2.ostatniTakt->clockingBit == 0 && r3.ostatniTakt->clockingBit == 0) {
			r2.clock();
			r3.clock();
		}
		else if (r1.ostatniTakt->clockingBit == 1 && r2.ostatniTakt->clockingBit == 0 && r3.ostatniTakt->clockingBit == 1) {
			r1.clock();
			r3.clock();
		}
		else if (r1.ostatniTakt->clockingBit == 1 && r2.ostatniTakt->clockingBit == 1 && r3.ostatniTakt->clockingBit == 0) {
			r1.clock();
			r2.clock();
		}
		else if (r1.ostatniTakt->clockingBit == 1 && r2.ostatniTakt->clockingBit == 1 && r3.ostatniTakt->clockingBit == 1) {
			r1.clock();
			r2.clock();
			r3.clock();
		}
	}
}

void Generator::generatingKeystream()
{
	for (int i = 0; i < 228; i++) {
		keystream[i] = r1.ostatniTakt->lastBit xor r2.ostatniTakt->lastBit xor r3.ostatniTakt->lastBit;
		if(r1.ostatniTakt->clockingBit==0 && r2.ostatniTakt->clockingBit == 0 && r3.ostatniTakt->clockingBit == 0){
			r1.clock();
			r2.clock();
			r3.clock();
		}
		else if (r1.ostatniTakt->clockingBit == 0 && r2.ostatniTakt->clockingBit == 0 && r3.ostatniTakt->clockingBit == 1) {
			r1.clock();
			r2.clock();
		}
		else if (r1.ostatniTakt->clockingBit == 0 && r2.ostatniTakt->clockingBit == 1 && r3.ostatniTakt->clockingBit == 0) {
			r1.clock();
			r3.clock();
		}
		else if (r1.ostatniTakt->clockingBit == 0 && r2.ostatniTakt->clockingBit == 1 && r3.ostatniTakt->clockingBit == 1) {
			r2.clock();
			r3.clock();
		}
		else if (r1.ostatniTakt->clockingBit == 1 && r2.ostatniTakt->clockingBit == 0 && r3.ostatniTakt->clockingBit == 0) {
			r2.clock();
			r3.clock();
		}
		else if (r1.ostatniTakt->clockingBit == 1 && r2.ostatniTakt->clockingBit == 0 && r3.ostatniTakt->clockingBit == 1) {
			r1.clock();
			r3.clock();
		}
		else if (r1.ostatniTakt->clockingBit == 1 && r2.ostatniTakt->clockingBit == 1 && r3.ostatniTakt->clockingBit == 0) {
			r1.clock();
			r2.clock();
		}
		else if (r1.ostatniTakt->clockingBit == 1 && r2.ostatniTakt->clockingBit == 1 && r3.ostatniTakt->clockingBit == 1) {
			r1.clock();
			r2.clock();
			r3.clock();			
		}
		
	}
}
