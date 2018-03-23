#include "Perceptron.h"

Perceptron::Perceptron(vector<double> _x, bool usingBias)
{
	x = _x;

	if(usingBias)																		//Only for testing purposes
		x.push_back(1);

	for (int i = 0; i < x.size(); i++)
	{
		w.push_back(static_cast <float> (rand()) / static_cast <float> (RAND_MAX));		//Init with random number from 0.0 to 1.0
	}

}

Perceptron::~Perceptron()
{
}

void Perceptron::train()
{
}

double Perceptron::sum()																//Weighted sum
{
	double sum = 0;
	for (int i = 0; i < x.size(); i++)
	{
		sum += x[i] * w[i];
	}
	return sum;
}