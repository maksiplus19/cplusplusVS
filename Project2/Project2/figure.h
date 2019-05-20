#ifndef FIGURE_H
#define FIGURE_H


class figure
{
public:
    figure() = default;
	~figure() = default;
    virtual void draw() = 0;
    virtual double square() = 0;
protected:
    int angle_;
};

#endif // FIGURE_H
