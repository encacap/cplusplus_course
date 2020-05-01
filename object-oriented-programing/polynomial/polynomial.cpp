#include "polynomial.h"

Polynomial::Polynomial(int degree)
{
    this->degree = degree;
    coef = new double[degree];
    for (int i = 0; i < degree; i++)
        coef[i] = 0;
}

void Polynomial::setCoef(int k, double value)
{
    this->coef[k] = value;
}

Polynomial::~Polynomial()
{
    delete this->coef;
}

void Polynomial::getPolynomial()
{
    for (int i = 0; i < this->degree; i++)
    {
        cout << coef[i] << "*x^" << i << " + ";
    }
}

Polynomial operator+(const Polynomial &leftPoly, const Polynomial &rightPoly)
{
    for (int i = 0; i < leftPoly.degree; i++)
        leftPoly.coef[i] += rightPoly.coef[i];
    return leftPoly;
}

Polynomial operator-(const Polynomial &leftPoly, const Polynomial &rightPoly)
{
    for (int i = 0; i < leftPoly.degree; i++)
        leftPoly.coef[i] -= rightPoly.coef[i];
    return leftPoly;
}

Polynomial operator*(const Polynomial &leftPoly, const Polynomial &rightPoly)
{
    for (int i = 0; i < leftPoly.degree; i++)
        leftPoly.coef[i] *= rightPoly.coef[i];
    return leftPoly;
}

int main()
{
    Polynomial polyLeft(6);
    Polynomial polyRight(6);
    Polynomial poly(6);
    polyLeft.setCoef(0, 2);
    polyLeft.setCoef(1, 10);
    polyLeft.setCoef(2, 4);
    polyLeft.setCoef(5, 1);
    polyRight.setCoef(0, 2);
    polyRight.setCoef(1, 5);
    polyRight.setCoef(2, 1);
    polyRight.setCoef(4, 6);
    poly = polyLeft + polyRight;
    poly = polyLeft - polyRight;
    poly.getPolynomial();
    return 0;
}