#pragma once
//activation function 1/1+pow(e,-a);

class Perceptron
{
private:
	bool usingBias; //only use for first variant, otherwise always true

public:
	Perceptron();
	~Perceptron();
	void train();
	double sum();
};

