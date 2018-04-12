#include "NeuralNetwork.h"
#include <cmath>

double Activation(double x)
{
	return 1 / (1 + exp(-x)); //sigmoid
}

double Derivative(double x)
{
	return x * (1 - x);
}

NeuralNetwork::NeuralNetwork(int input, int hidden, int output, bool usingBias) : input(input), hidden(hidden), output(output), usingBias(usingBias)
{
	weightsIH = Matrix(hidden, input);
	weightsHO = Matrix(output, hidden);
	weightsIHdelta = Matrix(hidden, input);
	weightsIHdelta = weightsIHdelta * 0;
	weightsHOdelta = Matrix(output, hidden);
	weightsHOdelta = weightsHOdelta * 0;
	biasH = Matrix(hidden, 1);
	biasO = Matrix(output, 1);
	biasHdelta = Matrix(hidden, 1);
	biasHdelta = biasHdelta * 0;
	biasOdelta = Matrix(output, 1);
	biasOdelta = biasOdelta * 0;
}


NeuralNetwork::~NeuralNetwork()
{

}

Matrix NeuralNetwork::Feedforward(Matrix input)
{
	Matrix hidden = (weightsIH * input);
	if (usingBias)
		hidden = hidden + biasH;
	hidden.map(Activation);

	Matrix output = (weightsHO * hidden);
	if (usingBias)
		output = output + biasO;
	output.map(Activation);
	return output;
}

void NeuralNetwork::Train(Matrix input, Matrix answer)
{
	Matrix hidden = (weightsIH * input);
	if (usingBias)
		hidden = hidden + biasH;
	hidden.map(Activation);

	Matrix output = (weightsHO * hidden);
	if (usingBias)
		output = output + biasO;
	output.map(Activation);
	//FEEDFORWARD ENDS

	Matrix errorO = answer - output;

	Matrix gradient = output;
	gradient.map(Derivative);
	gradient = (gradient * errorO) * learningRate;

	Matrix hiddent = hidden.transpose();
	weightsHOdelta = (gradient * hiddent) + (weightsHOdelta * momentum);
	
	weightsHO = weightsHO + weightsHOdelta;
	//HO Delta applied

	if (usingBias)
	{
		biasOdelta = gradient + (biasOdelta * momentum);
		biasO = biasO + biasOdelta;
	}
	//Adjusting biasO
	

	Matrix weightsHOt = weightsHO.transpose();
	Matrix errorH = weightsHOt * errorO;

	Matrix gradienth = hidden;
	gradienth.map(Derivative);
	gradienth = (gradienth * errorH) * learningRate;

	Matrix inputt = input.transpose();
	weightsIHdelta = (gradienth * inputt) + (weightsIHdelta * momentum);

	weightsIH = weightsIH + weightsIHdelta;

	if (usingBias)
	{
		biasHdelta = gradienth + (biasHdelta * momentum);
		biasH = biasH + biasHdelta;
	}
}

