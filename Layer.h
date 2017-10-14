#pragma once
class Layer
{
public:
	Layer();
	~Layer();

	float * think(const float* input);
	void setInputCount(int numberOfInputs);
	void setNeuronCount(int numberOfNeurons);
	int getNeuronCount();
	int getInputCount();

	void init();

private:
	int nInputs;
	float * weights;
	float * biases;
	float * output;
	int nNeurons;
};

