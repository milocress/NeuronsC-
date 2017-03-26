#pragma once
#include "Neuron.h"
class InputNeuron : Neuron
{
private:
	
public:
	double getActivation() { return activation; }
	void setActivation(double a) { activation = a; }
};