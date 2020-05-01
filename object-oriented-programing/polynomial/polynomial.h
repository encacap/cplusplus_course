#include <iostream>
#include <cstring>
#ifndef POLYNOMIAL
#define POLYNOMIAL

using namespace std;

const int MAX_DEGREE = 5;

class Polynomial
{
public:
    // Constructor
    Polynomial(int degree);

    // Modification member functions
    void setCoef(int k, double value);
    void clear();

    // Accessor functions
    double getCoef(int k) const;
    int getDegree() const;
    void getPolynomial();

    // Overloading Operator
    friend Polynomial operator+(const Polynomial &leftPoly, const Polynomial &rightPoly);
    friend Polynomial operator-(const Polynomial &leftPoly, const Polynomial &rightPoly);
    friend Polynomial operator*(const Polynomial &leftPoly, const Polynomial &rightPoly);
    Polynomial &operator=(const Polynomial &poly);
    Polynomial &operator+=(const Polynomial &poly);
    Polynomial &operator-=(const Polynomial &poly);
    Polynomial &operator*=(const Polynomial &poly);
    friend ostream &operator<<(ostream &out, const Polynomial &p);

    // Destructor
    ~Polynomial();

private:
    int degree;
    double *coef;
    // double coef(MAX_DEGREE + 1);
};

#endif