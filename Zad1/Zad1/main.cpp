#include <iostream>
#include "Matrix.h"
#include "NeuralNetwork.h"
#include <time.h>
#include <windows.h>

using namespace std;

int main()
{
	srand(time(NULL));

	NeuralNetwork brain(2, 2, 4);
	Matrix m(4, 1);
	Matrix n(3, 1);
	Matrix o = m * n;
	o.display();
	m = brain.Feedforward(m);
	m.display();
	system("pause");
	return 0;
}