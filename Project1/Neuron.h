#pragma once

class Neuron
{
private:
	double activation;
public:
	int test;
	virtual double evaluate() = 0;
	virtual void connect() = 0;
	virtual void learn() = 0;
};