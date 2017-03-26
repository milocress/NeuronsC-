#pragma once
#include "Neuron.h"
#include "LearningNeuron.h"
class HiddenNeuron: public LearningNeuron
{
public:
	typedef LearningNeuron super;
	//default constructor
	HiddenNeuron() :super() {}
	HiddenNeuron(int inputCount, Network* n, float learningRate) :super(inputCount, n, learningRate)
	{
		m_lowInputIndex = 0;
		m_highInputIndex = n->getInSize() + n->getHiddenSize();
	}
};
