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
		values.push_back(temp);
	}
}

Matrix::Matrix(const Matrix &_m)
{
	for (int i = 0; i < _m.values.size(); i++)
	{
		vector<double> temp;
		for (int j = 0; j < _m.values[0].size(); j++)
		{
			temp.push_back(_m.values[i][j]);
		}
		values.push_back(temp);
	}
}

Matrix::~Matrix()
{
}

void Matrix::display()
{
	cout << "Matrix:\n";
	for (int i = 0; i < values.size(); i++)
	{
		for (int j = 0; j < values[i].size(); j++)
		{
			cout << values[i][j] << " ";
		}
		cout << "\n";
	}
}

void Matrix::map(f function)
{
	for (int i = 0; i < values.size(); i++)
	{
		for (int j = 0; j < values[i].size(); j++)
		{
			values[i][j] = function(values[i][j]);
		}
	}
}

Matrix Matrix::operator*(double s) 
{
	for (int i = 0; i < values.size(); i++)
	{
		for (int j = 0; j < values[i].size(); j++)
		{
			values[i][j] *= s;
		}
	}
	return *this;
}

Matrix Matrix::operator*(Matrix _m)
{
	if (values[0].size() != _m.values.size())
		throw invalid_argument("Wrong size of matrices.");

	Matrix result(values.size(), _m.values[0].size());
	for (int i = 0; i < result.values.size(); i++)
	{
		for (int j = 0; j < result.values[i].size(); j++)
		{
			double sum = 0;
			for (int k = 0; k < values[0].size(); k++)
			{
				sum += values[i][k] * _m.values[k][j];
			}
			result.values[i][j] = sum;
		}
	}
	return result;
}

Matrix Matrix::operator+(double s)
{
	for (int i = 0; i < values.size(); i++)
	{
		for (int j = 0; j < values[i].size(); j++)
		{
			values[i][j] += s;
		}
	}
	return *this;
}

Matrix Matrix::operator+(Matrix _m)
{
	for (int i = 0; i < values.size(); i++)
	{
		for (int j = 0; j < values[i].size(); j++)
		{
			values[i][j] += _m.values[i][j];
		}
	}
	return *this;
}

Matrix Matrix::transpose()
{
	Matrix result(values[0].size(), values.size());
	for (int i = 0; i < values.size(); i++)
	{
		for (int j = 0; j < values[i].size(); j++)
		{
			result.values[j][i] = values[i][j];
		}
	}
	return result;
}
