#pragma once
#include "Network.h"

class Neuron
{
protected:
	double activation;
	Network* m_n;

public:
	virtual double getActivation() = 0;
};