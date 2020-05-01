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

Polynomial operator+(const Polynomial &leftPoly, const Polynomial &rightPoly)
{
    Polynomial result(6);
    for (int i = 0; i < result.degree; i++)
        result.coef[i] = leftPoly.coef[i] + rightPoly.coef[i];
    return result;
}

Polynomial operator-(const Polynomial &leftPoly, const Polynomial &rightPoly)
{
    Polynomial result(6);
    for (int i = 0; i < result.degree; i++)
        result.coef[i] = leftPoly.coef[i] - rightPoly.coef[i];
    return result;
}

Polynomial operator*(const Polynomial &leftPoly, const Polynomial &rightPoly)
{
    Polynomial result(6);
    for (int i = 0; i < result.degree; i++)
        result.coef[i] = leftPoly.coef[i] * rightPoly.coef[i];
    return result;
}

Polynomial &Polynomial::operator=(const Polynomial &poly)
{
    for (int i = 0; i < poly.degree; i++)
    {
        this->coef[i] = poly.coef[i];
    }
    return *this;
}

Polynomial &Polynomial::operator+=(const Polynomial &poly)
{
    for (int i = 0; i < this->degree; i++)
    {
        this->coef[i] += poly.coef[i];
    }
    return *this;
}

Polynomial &Polynomial::operator-=(const Polynomial &poly)
{
    for (int i = 0; i < this->degree; i++)
    {
        this->coef[i] -= poly.coef[i];
    }
    return *this;
}

Polynomial &Polynomial::operator*=(const Polynomial &poly)
{
    for (int i = 0; i < this->degree; i++)
    {
        this->coef[i] *= poly.coef[i];
    }
    return *this;
}

ostream &operator<<(ostream &out, const Polynomial &p)
{
    for (int i = p.degree - 1; i >= 0; i--)
    {
        if (i > 1)
            out << p.coef[i] << "x^" << i << " + ";
        else if (i == 1)
            out << p.coef[i] << "x"
                << " + ";
        else if (i == 0)
            out << p.coef[i];
    }
    return out;
}

int main()
{
    int degree;
    cout << "Bac cua da thuc: ";
    cin >> degree;
    Polynomial polyLeft(degree);
    Polynomial polyRight(degree);
    Polynomial poly(degree);
    polyLeft.setCoef(0, 2);
    polyLeft.setCoef(1, 10);
    polyLeft.setCoef(2, 4);
    polyLeft.setCoef(5, 1);
    polyRight.setCoef(0, 2);
    polyRight.setCoef(1, 1);
    polyRight.setCoef(2, 1);
    polyRight.setCoef(4, 6);
    poly = polyLeft + polyRight;
    cout << poly << endl;
    poly = polyLeft - polyRight;
    cout << poly << endl;
    cout << polyLeft << endl;
    polyLeft += polyRight;
    cout << polyLeft << endl;
    return 0;
}