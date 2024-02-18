#pragma once
#include <iostream>



class Calculator
{
private:
	double a;
	double b;
public:
	Calculator(int a, int b);

	double addition();
	double substraction();
	double multiplication();
	double division();
};