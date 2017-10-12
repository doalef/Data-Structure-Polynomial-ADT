// ConsoleApplication22.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include "polynomial.h"
using namespace std;

int main()
{
	polynomial a(2,3);
	a.fill(2, 3, 2);
	a.fill(1, 2, 3);
	a.fill(0, 1, 5);
	a.print();
	system("pause");
    return 0;
}

