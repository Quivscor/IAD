#include "Matrix.h"



Matrix::Matrix(int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		vector<double> temp;
		for (int j = 0; j < cols; j++)
		{
			temp.push_back(0);
		}
		m.push_back(temp);
	}
}

Matrix::~Matrix()
{
}

void Matrix::display()
{
	cout << "Matrix:\n";
	for (int i = 0; i < m.size(); i++)
	{
		vector<double> temp;
		for (int j = 0; m[i].size(); j++)
		{
			cout << m[i][j] << " ";
		}
		cout << "\n";
	}
}

Matrix Matrix::operator*(double s) 
{
	for (int i = 0; i < m.size(); i++)
	{
		for (int j = 0; j < m[i].size(); j++)
		{
			m[i][j] *= s;
		}
	}
	return *this;
}

Matrix Matrix::operator+(double s)
{
	for (int i = 0; i < m.size(); i++)
	{
		for (int j = 0; j < m[i].size(); j++)
		{
			m[i][j] += s;
		}
	}
	return *this;
}

Matrix Matrix::operator+(Matrix _m)
{
	for (int i = 0; i < m.size(); i++)
	{
		for (int j = 0; j < m[i].size(); j++)
		{
			m[i][j] += _m.m[i][j];
		}
	}
	return *this;
}
