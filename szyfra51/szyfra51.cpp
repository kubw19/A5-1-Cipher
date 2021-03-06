// szyfra51.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include "Generator.h"

bool sessionKey[64] =
{
	0, 1, 0, 0,
	1, 1, 1, 0,
	0, 0, 1, 0,
	1, 1, 1, 1,
	0, 1, 0, 0,
	1, 1, 0, 1,
	0, 1, 1, 1,
	1, 1, 0, 0,
	0, 0, 0, 1,
	1, 1, 1, 0,
	1, 0, 1, 1,
	1, 0, 0, 0,
	1, 0, 0, 0,
	1, 0, 1, 1,
	0, 0, 1, 1,
	1, 0, 1, 0
};

bool frame[22] =
{
	1,1,
	1, 0, 1, 0,
	1, 0, 1, 1,
	0, 0, 1, 1,
	1, 1, 0, 0,
	1, 0, 1, 1
};



int main()
{
	Generator generator = Generator(sessionKey, frame);//initialize new generator
	generator.loadSessionKey(); //clocks the registers 64 times in order to load session key to them
	generator.loadFrame(); //clocks the registert 22 times in order to load frame to them
	generator.irregularClocking();// clocks the register 100 times irregulary to "mix" them
	generator.generatingKeystream();// genearte 228 bits long keystream
	
	for (int i = 0; i < 228; i++) {
		std::cout << generator.keystream[i]; //display the output keystream
	}
	std::cout << std::endl;

	/* in order to display register after every tact go to Generator.cpp and place r1.echo(); (same for r2,r3) in the desired place*/

	system("PAUSE");
	return 0;
}

