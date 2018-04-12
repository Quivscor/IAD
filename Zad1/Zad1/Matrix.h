#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Matrix
{
public:
	vector<vector<double>> values;
	Matrix();
	Matrix(int rows, int cols, string filename, int skipInputs = 0);
	Matrix(int rows, int cols);
	Matrix(const Matrix &_m);
	~Matrix();
	void display();
	void map(double(*f)(double));
	Matrix operator*(double s);
	Matrix operator*(Matrix _m);
	Matrix operator+(double s);
	Matrix operator+(Matrix _m);
	Matrix operator-(double s);
	Matrix operator-(Matrix _m);
	Matrix transpose();
};

