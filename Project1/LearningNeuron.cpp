#include "LearningNeuron.h"
#include <cstdlib>
#include <ctime>

LearningNeuron::LearningNeuron()
{
	m_inputCount = 0;
	m_input = new int[0];
	m_inputWeight = new double[0];
	m_n = nullptr;
	m_learningRate = 0;
}

LearningNeuron::LearningNeuron(int inputCount, Network* n, float learning_rate)
{
	std::srand(std::time(NULL));
	m_inputCount = inputCount;
	m_input = new int[inputCount];
	m_inputWeight = new double[inputCount];
	//Initialize weights to random values b/w -1 and 1.
	for (int i = 0; i < inputCount; i++)
	{
		m_inputWeight[i] = (std::rand() / RAND_MAX) * 2 - 1;
	}
	m_n = n;
	m_input = n->connect(m_lowInputIndex, m_highInputIndex);
	m_learningRate = learning_rate;
}

double LearningNeuron::evaluate()
{
	int sum = 0;
	for (int i = 0; i < m_inputCount; i++)
	{
		sum += (*m_n)[m_input[i]] * m_inputWeight[i];
	}
	// range [0, 1] --> [-1, 1]
	activation = 2 * Network::sigmoid(sum) + 1;
	return activation;
}

void LearningNeuron::learn()
{
	/*
	http://www.nbb.cornell.edu/neurobio/linster/lecture4.pdf
	"If xj is the output of the presynaptic neuron, xi the output
	of the postsynaptic neuron, and wij the strengthof the
	connection between them, and γ learning rate, the one form of
	a learning rule would be:
	∆Wij (t) = γ∗xj*xi"

	However, a reward-modulated model would prove more -- well --
	rewarding (ba-dum-tsh), and so the final function will look
	something more like this:
	∆Wij (t) = γ∗xj*xi*r
	where r is a global reward signal.
	*/

	for (int i = 0; i < m_inputCount; i++)
	{
		m_inputWeight[i] += m_learningRate * (*m_n)[i] * activation * m_n->getPerformance();

	}

}

LearningNeuron::~LearningNeuron() {
	delete[] m_input;
}