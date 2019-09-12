//
// Created by ruben on 9/12/2019.
//

#ifndef POLINOMIO_POLINOMIO_H
#define POLINOMIO_POLINOMIO_H

#include <vector>
#include <string.h>
#include <string>

using namespace std;

using Coef = double;

class Monomio {
private:
    Coef coeficiente;
    int exponente;
    Monomio* next;

public:
    Monomio(Coef coeficiente, int exponente);

    Coef getCoeficiente() const;

    void setCoeficiente(Coef coeficiente);

    int getExponente() const;

    void setExponente(int exponente);

    Monomio *getNext() const;

    void setNext(Monomio *monomio);
};


class Polynomial {
private:
    Monomio* p;

public:
    Polynomial();

    void add (Coef, int);

    friend ostream& operator << (ostream& ss, const Polynomial& n);

    friend Polynomial operator +(const Polynomial &, const int &);

    int degree();

    friend Polynomial operator +(const Polynomial &, const Polynomial &);
};

#endif //POLINOMIO_POLINOMIO_H
