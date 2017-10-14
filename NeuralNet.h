#pragma once
#include "Layer.h"
#include <string>

class NeuralNet
{
public:
	NeuralNet(int numberOfInputs, int numberOfOutputs, int numberOfHiddenLayers);
	~NeuralNet();

	void setNeuronCountInLayer(int layer, int numberOfNeurons);
	int getNeuronCountInLayer(int layer);

	void save(const std::string& filename);
	void load(const std::string& filename);

	void init();
	float * think(float* input);
	

private:
	int nLayers;
	int nInputs;
	int nOutputs;
	Layer * layers;
};

