#include "NeuralNetwork.h"
#include <cmath>

double Activation(double x)
{
	return 1 / (1 + exp(-x)); //sigmoid
}

NeuralNetwork::NeuralNetwork(int input, int hidden, int output) : input(input), hidden(hidden), output(output)
{
	weightsIH = Matrix(hidden, input);
	weightsHO = Matrix(output, hidden);
	biasH = Matrix(hidden, 1);
	biasO = Matrix(output, 1);
}


NeuralNetwork::~NeuralNetwork()
{

}

Matrix NeuralNetwork::Feedforward(Matrix input)
{
	double(*f)(double) = Activation;

	Matrix hidden = (weightsIH * input);
	if (usingBias)
		hidden = hidden + biasH;
	hidden.map(f);

	Matrix output = (weightsHO * hidden);
	if (usingBias)
		output = output + biasO;
	output.map(f);

	return output;
}

void NeuralNetwork::Train(Matrix output, Matrix answer)
{

}

