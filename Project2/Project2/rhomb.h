#pragma once
#include "squarec.h"
class rhombus :
	public squareC
{
public:
	rhombus(double t, double b, double l, double r) : squareC(t, b, l, r){};
	void draw() override;
	double square() override;
	~rhombus() = default;
};

