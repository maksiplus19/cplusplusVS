#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "figure.h"
#include <utility>

class ellipse : public figure
{
    std::pair<double, double> center_;
    double v_radius_;
    double h_radius_;
public:
    ellipse(double x_center, double y_center, double v_r, double h_r) :
        center_(std::pair<double, double>(x_center, y_center)), v_radius_(v_r), h_radius_(h_r){};
    ~ellipse() = default;
	void draw() override;
	double square() override;
};

#endif // ELLIPSE_H
