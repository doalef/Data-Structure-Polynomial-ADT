#pragma once
class term
{
	friend class polynomial;
public:
	term();
	~term();
private:
	int exp;
	float coef;
};

