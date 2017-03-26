#include "Network.h"
#include <cstdlib>
#include <ctime>

Network::Network(\
	int inSize, \
	int outSize, \
	int hiddenSize,
	int connectionsPerNeuron)
{
	m_inSize = inSize;
	m_outSize = outSize;
	m_hiddenSize = hiddenSize;
	m_connectionsPerNeuron = connectionsPerNeuron;
	inNodeArray = new InputNeuron[inSize];
	for (int i = 0; i < inSize; i++)
	{
		inNodeArray[i] = InputNeuron(/*Params*/);
	}
	outNodeArray = new OutputNeuron[outSize];
	for (int i = 0; i < outSize; i++)
	{
		outNodeArray[i] = OutputNeuron(/*Params*/);
	}
	hiddenNodeArray = new HiddenNeuron[hiddenSize];
	for (int i = 0; i < hiddenSize; i++)
	{
		hiddenNodeArray[i] = HiddenNeuron(/*Params*/);
	}
}

int * Network::connect(int low, int high)
{
	std::srand(std::time(NULL));
	//I will overlook the modulo bias here...
	int * permutation = new int[high - low];
	for (int i = low; i < high; i++)
	{
		permutation[i] = i;
	}
	for (int i = 0; i < (high - low); i++)
	{
		swap(&permutation[i], &permutation[std::rand() % m_connectionsPerNeuron]);
	}
	static int *output = new int[m_connectionsPerNeuron];
	for (int i = 0; i < m_connectionsPerNeuron; i++)
	{
		output[i] = permutation[i];
	}
	return output;
}

double Network::operator[](int i)
{
	if (i < m_inSize)
	{
		return inNodeArray[i].getActivation();
	}
	i -= m_inSize;
	if (i < m_hiddenSize)
	{
		return hiddenNodeArray[i].getActivation();
	}
	i -= m_hiddenSize;
	if (i < m_outSize)
	{
		return outNodeArray[i].getActivation();
	}
	// If i is out of bounds:
	return -2; //-2 is not a possible activation value.
}

//All hell will break loose if the length of n != m_inSize.
void Network::setInput(double* in)
{
	for (int i = 0; i < m_inSize; i++)
	{
		inNodeArray[i].setActivation(in[i]);
	}
}

double* Network::getOutput()
{
	double* out = new double[m_outSize];
	for (int i = 0; i < m_outSize; i++)
	{
		out[i] = outNodeArray[i].evaluate();
	}
	return out;
}

Network::~Network()
{
	delete[] inNodeArray;
	delete[] outNodeArray;
	delete[] hiddenNodeArray;
}