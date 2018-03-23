#pragma once
#include <vector>
#include <stdlib.h>
//activation function 1/1+pow(e,-a);
using namespace std;

class Perceptron
{
private:
	//bool usingBias = true; //only use for first variant, otherwise always true
	vector<double> x;
	vector<double> w;

public:
	Perceptron(vector<double> _x, bool usingBias = true);
	~Perceptron();
	void train(); //E(x,w) = 1/2 sum (P elements from p =1) [sum(M elements from m=1) ((tm^p-ym(x^p,w))^2]
				  //SSE -> sum of squares errors
				  //tm - target (known answer)
				  //ym(x) - received answer
				  //sum(M elements from m=1) - sum of given answers
				  //sum (P elements from p =1) - sum of all variants
				  //w - weight
	double sum();
	//activation function;
};

