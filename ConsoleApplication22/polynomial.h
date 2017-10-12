#pragma once
#include "term.h"
class polynomial
{
public:
	polynomial();
	polynomial(int d,int n);
	~polynomial();

	float Eval(float f);
	polynomial sum(polynomial p);
	void fill(int index, int exp, float value);
	float extract(int index);
	polynomial Subtract(polynomial p);
	polynomial multiply(polynomial p);
	void sort();

	void print();

	int degree;
	int num;
	term *term_;
};

