#include "stdafx.h"
#include "polynomial.h"
#include <math.h>
#include <iostream>
#include <string>
using namespace std;



polynomial::polynomial()
{
}


polynomial::~polynomial()
{
}


polynomial::polynomial(int d, int n)
{
	degree = d;
	num = n;
	term_ = new term[n];
}

float polynomial::Eval(float f) {

	float res = 0;
	for (int i = 0; i < num; i++) {
		res += term_[i].coef + pow(f, term_[i].exp);
	}
	return res;
}

//float * polynomial::sum(polynomial p) {
//	float *res;
//	if (p.degree >= degree) {
//		res = new float[p.degree];
//		for (int i = 0; i <= degree; i++) {
//			res[i] = (A[i] + p.A[i]);
//		}
//	}
//	else
//	{
//		res = new float[degree];
//		for (int i = 0; i <= p.degree; i++) {
//			res[i] = (A[i] + p.A[i]);
//		}
//	}
//	return res;
//}

void polynomial::fill(int index, int exp, float value) {
	term_[index].coef = value;
	term_[index].exp = exp;
}

//return the coef of the given index
float polynomial::extract(int index) {
	return term_[index].coef;
}

//TODO what?
void polynomial::print() {
	sort();
	string x = "x^";

	for (int i = num - 1; i >= 0; i--) {
		//if == 0 then doesn't need + at the end of it 
		if (i == 0 && term_[i].exp == 0) {
			//checking for positive and negative 
			if (term_[i].coef > 0) {
				cout << term_[i].coef;
			}
			else
			{
				cout << "(-" << term_[i].coef << ")";
			}
		}
		else if (i == 0 && term_[i].exp > 0) {
			//checking for positive and negative 
			if (term_[i].coef > 0) {
				cout << term_[i].coef;
			}
			else
			{
				cout << "(-" << term_[i].coef << ")";
			}
		}
		else
		{
			//checking for positive and negative 
			if (term_[i].coef > 0) {
				cout << term_[i].coef << x << term_[i].exp << " + ";
			}
			else
			{
				cout << "(-" << term_[i].coef << ")" << x << term_[i].exp << " + ";
			}
		}
	}
}

//float * polynomial::Subtract(polynomial p) {
//	float *res;
//	if (p.degree >= degree) {
//		res = new float[p.degree];
//		for (int i = 0; i <= degree; i++) {
//			res[i] = (A[i] - p.A[i]);
//		}
//	}
//	else
//	{
//		res = new float[degree];
//		for (int i = 0; i <= p.degree; i++) {
//			res[i] = (A[i] - p.A[i]);
//		}
//	}
//	return res;
//}


//float * polynomial::multiply(polynomial p) {
//	float *result;
//	result = new float[degree + p.degree];
//	for (int i = 0; i <= (degree + p.degree + 2); i++) {
//		result[i] = 0;
//	}
//	for (int i = degree; i >= 0; i--) {
//		for (int j = p.degree; j >= 0; j--) {
//			result[i + j] += (A[i] * p.A[j]);
//			cout << result[i + j] << "\n";
//		}
//	}
//
//	return result;
//}

void polynomial::sort() {
	int exp;
	float coef;
	for (int i = num-1; i > 0 ; i--) {
		if (term_[i].coef > term_[i-1].coef) {
			coef = term_[i].coef;
			exp = term_[i].exp;
			term_[i].coef = term_[i-1].coef;
			term_[i].exp = term_[i - 1].exp;
			term_[i - 1].coef = coef;
			term_[i - 1].exp = exp;
		}
	}
}
