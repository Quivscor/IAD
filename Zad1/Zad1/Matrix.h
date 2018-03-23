#pragma once
#include <vector>
#include <iostream>

typedef double(*f)(double);

using namespace std;

class Matrix
{
public:
	vector<vector<double>> values;

	Matrix(int rows, int cols);
	Matrix(const Matrix &_m);
	~Matrix();
	void display();
	void map(f function);
	Matrix operator*(double s);
	Matrix operator*(Matrix _m);
	Matrix operator+(double s);
	Matrix operator+(Matrix _m);
	Matrix transpose();
};

