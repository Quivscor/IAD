#pragma once
#include "Matrix.h"

class Matrix;

class NeuralNetwork
{
private:
	int input;
	int hidden;
	int output;
	bool usingBias = true;

	Matrix weightsIH;
	Matrix weightsHO;
	Matrix biasH;
	Matrix biasO;

public:
	NeuralNetwork(int input, int hidden, int output);
	~NeuralNetwork();
	void Feedforward(Matrix input);
};

