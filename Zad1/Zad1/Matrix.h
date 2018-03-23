#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Matrix
{
public:
	vector<vector<double>> m;

	Matrix(int rows, int cols);
	~Matrix();
	void display();
	Matrix operator*(double s);
	Matrix operator+(double s);
	Matrix operator+(Matrix _m);
};

