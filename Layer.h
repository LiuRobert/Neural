#pragma once
class Layer
{
public:
	Layer();
	~Layer();
	void load(float * weights, float * biases, int inputCount, int neuronCount);
	void init();
	float * think(const float* input);
	
	void setInputCount(int neuronCount);
	void setNeuronCount(int neuronCount);
	int getNeuronCount();
	int getInputCount();
	float * getWeights();
	float * getBiases();

	

private:
	int _intputCount;
	float * _weights;
	float * _biases;
	float * _neurons;
	int _neuronCount;
};

