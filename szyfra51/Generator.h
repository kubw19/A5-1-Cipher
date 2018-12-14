#pragma once
#include "R1.h"
#include "R2.h"
#include "R3.h"
class Generator
{
public:
	R1 r1;
	R2 r2;
	R3 r3;
	bool* sessionKey, *frame;
	bool keystream[228];
public:
	Generator(bool* sessionKey, bool* frame);
	~Generator();
	void loadSessionKey(); 
	void loadFrame();
	void irregularClocking();
	void generatingKeystream();

};

