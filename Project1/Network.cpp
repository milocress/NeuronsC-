#include "Network.h"

Network::Network(int size)
{
	nodeArray = new Neuron[size + 1];
	for (int i = 0; i < size; i++)
	{
		nodeArray[i] = Neuron();
	}
}

Network::~Network()
{
	delete[] nodeArray;
}