#include "NeuralNet.h"
#include <fstream>



NeuralNet::NeuralNet(int numberOfInputs, int numberOfOutputs, int numberOfHiddenLayers)
{
	nInputs = numberOfInputs;
	nOutputs = numberOfOutputs;
	nLayers = numberOfHiddenLayers + 1;
	layers = new Layer[nLayers];
}

NeuralNet::~NeuralNet()
{
}

void NeuralNet::setNeuronCountInLayer(int layer, int numberOfNeurons)
{
	layers[layer].setNeuronCount(numberOfNeurons);
}

int NeuralNet::getNeuronCountInLayer(int layer)
{
	return layers[layer].getInputCount();
}

void NeuralNet::save(const std::string & filename)
{

}

void NeuralNet::load(const std::string & filename)
{

}

void NeuralNet::init()
{
	layers[0].setInputCount(nInputs);
	for (int i = 1; i < nLayers; i++)
	{
		layers[i].setInputCount(layers[i - 1].getNeuronCount());
	}
	layers[nLayers - 1].setNeuronCount(nOutputs);

	for (int i = 0; i < nLayers; i++)
	{
		layers[i].init();
	}
}

float * NeuralNet::think(float * input)
{
	float * output = input;
	for (int i = 0; i < nLayers; i++)
	{
		output = layers[i].think(output);
	}
	return output;
}


/*
int NeuralNet::makeMove(const int * board)
{
	for (int i = 0; i < 42; i++)
	{
		if (board[i] == 1)
			input[i] = 1.0f;
		else
			input[i] = 0.0f;

		if (board[i] == 2)
			input[42 + i] = 1.0f;
		else
			input[42 + i] = 0.0f;
	}
	return 0;
}
*/
