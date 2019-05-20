#ifndef SQUAREC_H
#define SQUAREC_H

#include "figure.h"

class squareC : public figure
{
protected:
    double top_;
    double bottom_;
    double left_;
    double right_;
public:
    squareC(double t, double b, double l, double r) : top_(t), bottom_(b), left_(l), right_(r){};
    ~squareC() = default;
	void draw() override;
	double square() override;
};

#endif // SQUAREC_H
