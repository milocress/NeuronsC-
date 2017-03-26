#include <iostream>
#include "Network.h"

char alphabet[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'l', 'm',
'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '_', '\0' };

typedef struct CharacterRepresentation_t
{
	double isLetter[sizeof(alphabet)];
} brainChar;

int main()
{
	//message length is 20 characters, which is 20*28 (null char and space '_') input and output neurons
	int msglen = 20;
	int insize = sizeof(alphabet) * msglen;
	//just an arbitrary number...
	int hiddensize = 1000;
	int outsize = sizeof(alphabet) * msglen;
	int connectionsperneuron = 100;
	//The nymph who falls in love with Narcissus:
	Network echo = Network(insize, outsize, hiddensize, connectionsperneuron);
	return 0;
}

char toChar(brainChar c)
{
	int maxIndex = 0;
	for (int i = 1; i < sizeof(alphabet); i++)
	{
		if (c.isLetter[i] > c.isLetter[maxIndex])
		{
			maxIndex = i;
		}
	}
	return alphabet[maxIndex];
}

brainChar toBrainChar(char c)
{
	int i;
	for (i = 0; i < sizeof(alphabet); i++)
	{
		if (alphabet[i] == c) 
		{
			break;
		}
	}
	brainChar ret;
	ret.isLetter[i] = 1;
	return ret;
}

brainChar toBrainChar(int i)
{
	brainChar ret;
	ret.isLetter[i] = 1;
	return ret;
}

char * toCharArray(brainChar *c, int len)
{
	char * ret = new char[len + 1]; //Add null char at the end of string
	for (int i = 0; i < len; i++)
	{
		ret[i] = toChar(c[i]);
	}
	ret[len] = '/0';
	return ret;
}

brainChar * toBrainCharArray(char * c, int len)
{
	brainChar * ret = new brainChar[len - 1]; //Null char at end of string needs to be subtracted :)
	for (int i = 0; i < len - 1; i++)
	{
		ret[i] = toBrainChar(c[i]);
	}
	return ret;
}

brainChar * toBrainCharArray(int * c, int len)
{
	brainChar * ret = new brainChar[len]; //no null char at end of string :)
	for (int i = 0; i < len; i++)
	{
		ret[i] = toBrainChar(c[i]);
	}
	return ret;
}

double * toNeuralInput(brainChar* c, int len)
{
	double * ret = new double[sizeof(c[0]) * len];
	int counter = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < sizeof(c[i]); j++)
		{
			ret[counter] = c[i].isLetter[j];
		}
	}
}

double * toNeuralInput(char * c, int len)
{
	brainChar * a = toBrainCharArray(c, len);
	return toNeuralInput(a, len - 1);
}

brainChar * toBraincharArray(double * neuralOutput, int len)
{
	//If the number of output values is not evenly divisible by all the members of the alphabet, stuff may hit the fan.
	if (len % sizeof(alphabet))
	{
		std::cerr << "Error: SHTF";
		return;
	}

	int numChars = len / sizeof(alphabet);

	brainChar * ret = new brainChar[numChars];
	//You have been warned. (Gosh, maybe I should have used python :) )
	int j = 0;
	for (int i = 0; i < numChars + 1; i++)
	{
		//get values of brainchar[i]
		for (int k = j % sizeof(alphabet); j % k; j++)
		{
			ret[i].isLetter[k] = neuralOutput[j];
		}
	}
	return ret;
}