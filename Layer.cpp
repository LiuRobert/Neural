#include "Layer.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

float randomFloat()
{
	const float lowest = -100.0f;
	const float highest = 100.0f;
	return lowest + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (highest - lowest)));
}

Layer::Layer()
{
	srand(time(NULL));
	_neuronCount = -1;
	_intputCount = -1;
}

Layer::~Layer()
{
	delete[] _weights;
	delete[] _biases;
}

void Layer::load(float * weights, float * biases, int inputCount, int neuronCount)
{
	_weights = weights;
	_biases = biases;
	_intputCount = inputCount;
	_neuronCount = neuronCount;
	_neurons = new float[_neuronCount];
}


void Layer::init()
{
	if (_neuronCount < 1)
		throw "Number of neurons not set or below one when initalizing layer";

	if (_intputCount < 1)
		throw "Number of inputs not set or below one when initalizing layer";

	int nWeights = _intputCount * _neuronCount;
	_weights = new float[nWeights];
	_biases = new float[_intputCount];
	_neurons = new float[_neuronCount];

	for (int i = 0; i < nWeights; i++)
	{
		_weights[i] = randomFloat();
	}
	for (int i = 0; i < _intputCount; i++)
	{
		_biases[i] = randomFloat();
	}
}


float sigmoid(const float value)
{
	return 1 / (1 + pow(2.71828182846f, -value));
}

float * Layer::think(const float * input)
{
	for (int i = 0; i < _neuronCount; i++)
	{
		float sum = 0;
		for (int j = 0; j < _intputCount; j++)
		{
			sum += input[j] * _weights[_intputCount * i + j];
		}
		sum -= _biases[i];
		_neurons[i] = sigmoid(sum);
	}
	return _neurons;
}

void Layer::setInputCount(int numberOfInputs)
{
	_intputCount = numberOfInputs;
}

void Layer::setNeuronCount(int numberOfNeurons)
{
	_neuronCount = numberOfNeurons;
}

int Layer::getNeuronCount()
{
	return _neuronCount;
}

int Layer::getInputCount()
{
	return _intputCount;
}

float * Layer::getWeights()
{
	return _weights;
}

float * Layer::getBiases()
{
	return _biases;
}
