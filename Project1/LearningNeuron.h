#pragma once
#include "Neuron.h"
class LearningNeuron : public Neuron
{
	//The indices of each input 
protected:
	int* m_input;
	double* m_inputWeight;
	static int m_inputCount;
	int m_lowInputIndex;
	int m_highInputIndex;
	float m_learningRate;
public:
	typedef Neuron super;
	//default constructor
	LearningNeuron();
	LearningNeuron(int inputCount, Network* n, float learningRate);
	double getActivation() { return activation; }
	double evaluate();
	void learn();
	~LearningNeuron();
};