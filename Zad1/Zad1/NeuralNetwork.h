#pragma once
#include "Matrix.h"

class Matrix;

class NeuralNetwork
{
private:
	int input;
	int hidden;
	int output;
	bool usingBias;

	int generation = 0; //will be used for plotting

	double learningRate = 0.1;
	double momentum = 0.1; //must be < 1

	Matrix weightsIH;
	Matrix weightsHO;
	Matrix weightsIHdelta;
	Matrix weightsHOdelta;
	Matrix biasH;
	Matrix biasO;
	Matrix biasHdelta;
	Matrix biasOdelta;

public:
	NeuralNetwork(int input, int hidden, int output, bool usingBias = true);
	~NeuralNetwork();
	Matrix Feedforward(Matrix input);
	void Import(); //importing wages for testing
	void Export(); //exporting files for plotting
	void Train(Matrix input, Matrix answer);
};

//MSE - mean squared error
// 1/P sum (p elements from p = 1 sum(M elements from m = 1(((tm)^p - (ym)^p)^2)) 

