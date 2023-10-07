//
// Created by muribe on 06/10/23.
//

#include "NodoEntero.h"
#include <iostream>

NodoEntero::NodoEntero(int dato) {
	this->dato = dato;
	this->sig = NULL;
}

int NodoEntero::getDato() {
	return this->dato;
}

NodoEntero * NodoEntero::getSig() {
	return this->sig;
}

void NodoEntero::setDato(int dato) {
	this->dato = dato;
}

void NodoEntero::setSig(NodoEntero * sig) {
	this->sig = sig;
}