#include <iostream>
#ifndef POLYNOMIAL
#define POLYNOMIAL

using namespace std;

const int MAX_DEGREE = 5;

class Polynomial
{
public:
    // Constructor
    Polynomial();

    // Modification member functions
    void setCoef(int k, double value);
    void setDegree(int degree);
    void clear();

    // Accessor functions
    double getCoef(int k) const;
    int getDegree() const;

    // Overloading Operator
    // Polynomial operator+(const Polynomial &leftPoly, const Polynomial &rightPoly);
    // ostream &operator<<(ostream &out, const Polynomial &p);

private:
    int degree;
    double *coef;
    // double coef(MAX_DEGREE + 1);
};

#endif