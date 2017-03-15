#include "Network.h"

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
	outNodeArray = new OutputNeuron[outSize];
	hiddenNodeArray = new HiddenNeuron[inSize];
}

Neuron& Network::operator[](int i)
{
}

Network::~Network()
{
	delete[] inNodeArray;
	delete[] outNodeArray;
	delete[] hiddenNodeArray;
}