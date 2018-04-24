#include <iostream>
#include "Matrix.h"
#include "NeuralNetwork.h"
#include <time.h>
#include <windows.h>
#include <fstream>
#include "Losowanie.h"
#include <algorithm>
#include <random>

using namespace std;

int main()
{
	srand(time(NULL));

	const int learning_base = 4;
	fstream file("Input.txt", ios_base::in);

	vector<Matrix> learning, answer;
	for (int k = 0; k < learning_base; k++)
	{
		Matrix temp;
		vector<vector<double>> temp2;
		for (int i = 0; i < 4; i++)
		{
			vector<double> temp3;
			double temp4;
			file >> temp4;
			temp3.push_back(temp4);
			temp2.push_back(temp3);
		}
		temp = temp2;
		learning.push_back(temp);
		answer.push_back(temp);
	}
	file.close();

	NeuralNetwork brain(4, 3, 4);
	
	vector<int> wylosowane={0,1,2,3};
	auto rng = std::default_random_engine{};
	
	


		for (int i = 0; i < 1000; i++)
		{
			
			std::shuffle(std::begin(wylosowane), std::end(wylosowane), rng);
			

			for (int j = 0; j < 4; j++)
			{
				brain.Train(learning[wylosowane[j]], answer[wylosowane[j]]);
				//Matrix showTrain = brain.Feedforward(learning[wylosowane[j]]);
				//showTrain.print();
				//showTrain.toFile(outFile);
			}
		}
	
	for (int i = 0; i < 4; i++)
	{
		Matrix output = brain.Feedforward(answer[i]);
		answer[i].display();
		output.display();
	}

	system("pause");
	return 0;
}