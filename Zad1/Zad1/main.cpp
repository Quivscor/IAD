#include <iostream>
#include "Matrix.h"
#include "NeuralNetwork.h"
#include <time.h>
#include <windows.h>
#include <fstream>

using namespace std;

int main()
{
	srand(time(NULL));
	Matrix input(2, 1, "Input.txt", 2);
	Matrix answer(2, 1, "Answer.txt");

	input.display();
	answer.display();

	NeuralNetwork brain(2, 2, 2);
	
	for (int i = 0; i < 5; i++)
	{
		brain.Train(input, answer);
		Matrix showTrain = brain.Feedforward(input);
		showTrain.display();
	}
	Matrix output = brain.Feedforward(input);

	output.display();

	system("pause");
	return 0;
}