#pragma once
#include "Neuron.h"
#include "LearningNeuron.h"
class OutputNeuron : public LearningNeuron
{
public:
	typedef LearningNeuron super;
	//default constructor
	OutputNeuron() :super() {}
	OutputNeuron(int inputCount, Network* n, float learningRate) :super(inputCount, n, learningRate)
	{
		m_lowInputIndex = n->getInSize();
		m_highInputIndex = n->getInSize() + n->getHiddenSize();
	}
};
