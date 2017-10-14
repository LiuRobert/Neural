#include "Layer.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

float randomFloat()
{
	const float lowest = -100.0f;
	const float highest = 100.0f;
	return lowest + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (highest - lowest)));
}

Layer::Layer()
{
	srand(time(NULL));
	nNeurons = -1;
	nInputs = -1;
}

void Layer::init()
{
	if (nNeurons < 0)
		throw "Number of neurons not set or below zero when initalizing layer";

	if (nInputs < 0)
		throw "Number of inputs not set or below zero when initalizing layer";

	int nWeights = nInputs * nNeurons;
	weights = new float[nWeights];
	biases = new float[nInputs];
	output = new float[nNeurons];

	for (int i = 0; i < nWeights; i++)
	{
		weights[i] = randomFloat();
	}
	for (int i = 0; i < nInputs; i++)
	{
		biases[i] = randomFloat();
	}
}


Layer::~Layer()
{
}

float sigmoid(const float value)
{
	return 1 / (1 + pow(2.71828182846f, -value));
}

float * Layer::think(const float * input)
{
	for (int i = 0; i < nNeurons; i++)
	{
		float sum = 0;
		for (int j = 0; j < nInputs; j++)
		{
			sum += input[j] * weights[nInputs * i + j];
		}
		sum -= biases[i];
		output[i] = sigmoid(sum);
	}
	return output;
}

void Layer::setInputCount(int numberOfInputs)
{
	nInputs = numberOfInputs;
}

void Layer::setNeuronCount(int numberOfNeurons)
{
	nNeurons = numberOfNeurons;
}

int Layer::getNeuronCount()
{
	return nNeurons;
}

int Layer::getInputCount()
{
	return nInputs;
}
