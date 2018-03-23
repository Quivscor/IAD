#include <iostream>
#include "Matrix.h"
#include "Perceptron.h"
#include <time.h>
#include <windows.h>

using namespace std;

int main()
{
	Matrix m(2, 3);
	Matrix o = m.transpose();
	o.display();
	system("pause");
	return 0;
}