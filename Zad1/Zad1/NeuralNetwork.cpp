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

double Linear(double x)
{
	return 1;
}

NeuralNetwork::NeuralNetwork(int input, int hidden, int output, bool usingBias) : input(input), hidden(hidden), output(output), usingBias(usingBias)
{
	weightsIH = Matrix(hidden, input);
	weightsHO = Matrix(output, hidden);
	weightsIHdelta = Matrix(hidden, input);
	weightsHOdelta = Matrix(output, hidden);
	biasH = Matrix(hidden, 1);
	biasO = Matrix(output, 1);
	biasHdelta = Matrix(hidden, 1);
	biasOdelta = Matrix(output, 1);
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

double NeuralNetwork::SSError(vector<Matrix> input, vector<Matrix> answer, int size)
{
	vector<vector<double>> errors;
	double error = 0;	//init of empty matrix with right size
	for (int i = 0; i < size; i++)
	{
		double target = answer[i].toScalar();
		double result = Feedforward(input[i]).toScalar();
		error = error + (target - result) * (target - result);
	}
	error = error * (1.0/size);
	return error;
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

	//calculate errors
	Matrix errorO = answer - output;
	Matrix errorH = weightsHO.transpose() * errorO;

	//gradient of output layer
	Matrix gradient = output;
	gradient.map(Derivative);
	gradient = (gradient * errorO) * learningRate;

	//delta of weights between hidden and output
	weightsHOdelta = (gradient * hidden.transpose()) + (weightsHOdelta * momentum);
	weightsHO = weightsHO + weightsHOdelta;

	//adjusting bias
	if (usingBias)
	{
		biasOdelta = gradient + (biasOdelta * momentum);
		biasO = biasO + biasOdelta;
	}

	//gradient of hidden layer
	Matrix gradienth = hidden;
	gradienth.map(Derivative);
	gradienth = (gradienth * errorH) * learningRate;

	//delta of weights between input and hidden
	weightsIHdelta = (gradienth * input.transpose()) + (weightsIHdelta * momentum);
	weightsIH = weightsIH + weightsIHdelta;

	//adjusting bias
	if (usingBias)
	{
		biasHdelta = gradienth + (biasHdelta * momentum);
		biasH = biasH + biasHdelta;
	}

	
}

