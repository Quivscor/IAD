#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Matrix
{
public:
	vector<vector<double>> values;
	Matrix();
	Matrix(int rows, int cols);
	Matrix(const Matrix &_m);
	~Matrix();
	void display();
	void map(double(*f)(double));
	Matrix operator*(double s);
	Matrix operator*(Matrix _m);
	Matrix operator+(double s);
	Matrix operator+(Matrix _m);
	Matrix transpose();
};

