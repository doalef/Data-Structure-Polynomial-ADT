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

polynomial polynomial::sum(polynomial p) {
	if (p.num >= num) {
		polynomial res(p.degree, p.num + num);

		//flag , incase there are unique exps
		bool exists = false;
		//first loop for the bigger one
		for (int i = num - 1; i >= 0; i--) {
			for (int j = p.num - 1; j >= 0; j--) {
				//subtracts if exps match
				if (term_[i].exp == p.term_[j].exp) {
					res.term_[i].coef = (term_[i].coef - p.term_[j].coef);
					res.term_[i].exp = p.term_[i].exp;
					exists = true;
				}
			}
			//adds it incase it doesn't exist in the second object
			if (!exists) {
				res.term_[i].coef = term_[i].coef;
				res.term_[i].exp = p.term_[i].exp;
				exists = false;
			}
		}
		return res;
	}
	else
	{
		polynomial res(degree, p.num + num);

		//flag , incase there are unique exps
		bool exists = false;
		//first loop for the bigger one
		for (int i = p.num - 1; i >= 0; i--) {
			for (int j = num - 1; j >= 0; j--) {
				//subtracts if exps match
				if (term_[i].exp == p.term_[j].exp) {
					res.term_[i].coef = (term_[i].coef - p.term_[j].coef);
					res.term_[i].exp = p.term_[i].exp;
					exists = true;
				}
			}
			//adds it incase it doesn't exist in the second object
			if (!exists) {
				res.term_[i].coef = term_[i].coef;
				res.term_[i].exp = p.term_[i].exp;
				exists = false;
			}
		}
		return res;
	}
}

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

polynomial  polynomial::Subtract(polynomial p) {
	if (p.num >= num) {
		polynomial res(p.degree, p.num + num);

		//flag , incase there are unique exps
		bool exists = false;
		//first loop for the bigger one
		for (int i = num - 1; i >= 0; i--) {
			for (int j = p.num - 1; j >= 0; j--) {
				//subtracts if exps match
				if (term_[i].exp == p.term_[j].exp) {
					res.term_[i].coef = (term_[i].coef - p.term_[j].coef);
					res.term_[i].exp = p.term_[i].exp;
					exists = true;
				}
			}
			//adds it incase it doesn't exist in the second object
			if (!exists) {
				res.term_[i].coef = term_[i].coef;
				res.term_[i].exp = p.term_[i].exp;
				exists = false;
			}
		}
		return res;
	}
	else
	{
		polynomial res(degree, p.num + num);

		//flag , incase there are unique exps
		bool exists = false;
		//first loop for the bigger one
		for (int i = p.num - 1; i >= 0; i--) {
			for (int j = num - 1; j >= 0; j--) {
				//subtracts if exps match
				if (term_[i].exp == p.term_[j].exp) {
					res.term_[i].coef = (term_[i].coef - p.term_[j].coef);
					res.term_[i].exp = p.term_[i].exp;
					exists = true;
				}
			}
			//adds it incase it doesn't exist in the second object
			if (!exists) {
				res.term_[i].coef = term_[i].coef;
				res.term_[i].exp = p.term_[i].exp;
				exists = false;
			}
		}
		return res;
	}
}

polynomial polynomial::multiply(polynomial p) {
	polynomial res(p.degree + degree, num + p.num);
	for (int i = num - 1; i >= 0; i++) {
		for (int j = p.num; j >= 0; j++) {
			if (term_[i].exp == p.term_[i].exp && term_[i].coef == p.term_[i].coef) {
				res.term_[i + j].coef = term_[i].coef * term_[i].coef;
				res.term_[i + j].exp = term_[i].exp * 2;
				break;
			}
			else {
				res.term_[i + j].coef = term_[i].coef * p.term_[i].coef;
				res.term_[i + j].exp = term_[i].exp + p.term_[i].exp;
			}
		}
	}
	return res;
}

void polynomial::sort() {
	int exp;
	float coef;
	for (int i = num - 1; i > 0; i--) {
		if (term_[i].coef > term_[i - 1].coef) {
			coef = term_[i].coef;
			exp = term_[i].exp;
			term_[i].coef = term_[i - 1].coef;
			term_[i].exp = term_[i - 1].exp;
			term_[i - 1].coef = coef;
			term_[i - 1].exp = exp;
		}
	}
}
