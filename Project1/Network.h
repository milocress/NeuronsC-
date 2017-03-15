#pragma once
#include "Neuron.h"

class Network
{
	/**
	@param architecture - a list of integers, the zeroth of
	which defines the number of nodes in the zeroth layer,
	the 1st defines the number of nodes in the first  layer,
	etc. for example, if architecture = [3, 1, 2] the Network
	would look like this:
	( * = node)
	Layer 0		 Layer 1       Layer 2
	*                            *
	*              *
	*                            *
	Feed - forward
	Update: I've decided only to implement the alternate architecture
	(and shelve this for a later date)
	This is mainly because the internal data structures are so different
	that putting them in a single class is a bad idea.
	*/
	/*
	I'm not exactly sure what to call this network
	architecture, but it represents a more biologically
	accurate model of the brain.
	An important aspect of this architecture is that,
	a neuron could be connected to any other node in the
	network, except for itself.

	@param number_of_neurons - specifies the total neuron count
	of the network; a value of 6 means the method will
	create 6 neurons.
	@param connections_per_neuron - defines the number of nodes that
	send data to any neuron(this number limits inbound
	connections, and has no effect on outbound ones).
	If the value of this parameter is 3, a neuron's
	inputs could look like this:
	( * = node)
	Input          Node          Output
	*                            *
	*              *             *
	*
	The output connections are not dependent on the
	number_of_neurons parameter because of the random
	selection each neuron performs. A neuron can have
	any number of outbound connections, ranging from
	0 to number_of_neurons - 1.
	*/
private:
	Neuron * nodeArray;
public:
	Network(int size);
	~Network();
};