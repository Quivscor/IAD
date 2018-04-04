#include "NeuralNetwork.h"
#include <cmath>

double Activation(double x)
{
	return 1 / (1 + exp(-x));
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

void NeuralNetwork::Feedforward(Matrix input)
{
	double(*f)(double) = Activation;

	Matrix hidden = (weightsIH * input) + biasH;
	hidden.map(f);
}

