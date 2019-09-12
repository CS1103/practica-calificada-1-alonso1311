//
// Created by rudri on 9/12/2019.
//

#include <stdexcept>
#include <iostream>
#include "Polynomial.h"

//----------------------------Monomio--------------------------------------------------

Monomio::Monomio(Coef coeficiente, int exponente) : coeficiente(coeficiente), exponente(exponente) {
    next = nullptr;
}

Coef Monomio::getCoeficiente() const {
    return coeficiente;
}

void Monomio::setCoeficiente(Coef coeficiente) {
    Monomio::coeficiente = coeficiente;
}

int Monomio::getExponente() const {
    return exponente;
}

void Monomio::setExponente(int exponente) {
    Monomio::exponente = exponente;
}

Monomio *Monomio::getNext() const {
    return next;
}

void Monomio::setNext(Monomio *monomio) {
    Monomio::next = monomio;
}


//----------------------------Polinomio--------------------------------------------------

Polynomial::Polynomial() {
    p = nullptr;
}

void Polynomial::add(Coef coeficiente, int exponente) {
    Monomio* nuevoMonomio = new Monomio(coeficiente, exponente);
    if (p == nullptr)
        p = nuevoMonomio;
    else {
        Monomio* temp = p;
        while(temp->getNext() != nullptr)
            temp = temp->getNext();
        temp->setNext(nuevoMonomio);
    }
}

ostream& operator << (ostream& ss, const Polynomial& n){
    Monomio* temp = n.p;
    while(temp != nullptr){
        if (temp->getExponente() == 0){
            ss << temp->getCoeficiente() << endl;
            temp = temp->getNext();
        }
        else {
            ss << temp->getCoeficiente() << "x^" << temp->getExponente() << endl;
            temp = temp->getNext();
        }
    }
    return ss;
}

Polynomial operator+(const Polynomial & poly, const int & numero) {
    Polynomial temp1;
    Monomio* temp = poly.p;
    while(temp != nullptr && temp->getExponente() == 0){
        temp1.add(temp->getCoeficiente() + numero, 0);
    }
    return temp1;
}

int Polynomial::degree() {
    int mayor = 0;
    Monomio* temp = p;
    while(temp->getNext() != nullptr){
        if (temp->getExponente() > mayor)
            mayor = temp->getExponente();
        temp = temp->getNext();
    }
    return mayor;
}

Polynomial operator+(const Polynomial & P1, const Polynomial & P2) {
    Polynomial P3;

    Monomio* temp1 = P1.p;
    Monomio* temp2 = P2.p;
    while(temp1 != nullptr && temp2 != nullptr){
        temp1.add(temp->getCoeficiente() + numero, 0);
    }

}

