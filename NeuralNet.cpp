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
	delete[] layers;
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
	std::ofstream stream(filename, std::ios::binary);
	int inputCount, neuronCount;
	float * f;
	stream.write(reinterpret_cast<const char*>(&nLayers), sizeof(int));

	for (int i = 0; i < nLayers; i++)
	{
		inputCount = layers[i].getInputCount();
		stream.write(reinterpret_cast<const char*>(&inputCount), sizeof(int));
		neuronCount = layers[i].getNeuronCount();
		stream.write(reinterpret_cast<const char*>(&neuronCount), sizeof(int));

		f = layers[i].getWeights();
		for (int j = 0; j < inputCount * neuronCount; j++)
		{
			stream.write(reinterpret_cast<const char*>(&f[j]), sizeof(float));
		}

		f = layers[i].getBiases();
		for (int j = 0; j < inputCount; j++)
		{
			stream.write(reinterpret_cast<const char*>(&f[j]), sizeof(float));
		}
	}

	stream.close();
}

void NeuralNet::load(const std::string & filename)
{
	if (layers != nullptr)
		delete[] layers;

	std::ifstream stream(filename, std::ios::binary);
	int inputCount;
	int neuronCount;

	stream.read(reinterpret_cast<char*>(&nLayers), sizeof(int));
	layers = new Layer[nLayers];

	for (int i = 0; i < nLayers; i++)
	{
		stream.read(reinterpret_cast<char*>(&inputCount), sizeof(int));
		stream.read(reinterpret_cast<char*>(&neuronCount), sizeof(int));

		// Will be deleted by the destructor in Layer
		float * weights = new float[inputCount * neuronCount];
		float * biases = new float[inputCount];
		for (int j = 0; j < inputCount * neuronCount; j++)
		{
			stream.read(reinterpret_cast<char*>(&weights[j]), sizeof(float));
		}
		for (int j = 0; j < inputCount; j++)
		{
			stream.read(reinterpret_cast<char*>(&biases[j]), sizeof(float));
		}

		layers[i].load(weights, biases, inputCount, neuronCount);
	}

	stream.close();
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
