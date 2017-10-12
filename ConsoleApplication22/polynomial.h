#pragma once
#include "term.h"
class polynomial
{
public:
	polynomial();
	polynomial(int d,int n);
	~polynomial();

	float Eval(float f);
	float * sum(polynomial p);
	void fill(int index, int exp, float value);
	float extract(int index);
	float * Subtract(polynomial p);
	float * multiply(polynomial p);
	void sort();

	void print();

	int degree;
	int num;
	term *term_;
};

