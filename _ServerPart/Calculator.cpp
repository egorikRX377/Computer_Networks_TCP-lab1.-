#include "Calculator.h"


using namespace std;

Calculator::Calculator(int a, int b)
{
	this->a = a;
	this->b = b;
}

double Calculator::addition()
{
	double result = a + b;
	return result;
}

double Calculator::substraction()
{
	double result = a - b;
	return result;
}

double Calculator::multiplication()
{
	double result = a * b;
	return result;
}

double Calculator::division()
{
	double result = a / b;
	return result;
}
