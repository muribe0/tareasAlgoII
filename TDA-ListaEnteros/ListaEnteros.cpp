//
// Created by muribe on 06/10/23.
//

#include "ListaEnteros.h"
#include <iostream>

ListaEnteros::ListaEnteros() {
	this->primero = NULL;
	this->tamanio = 0;

	this->cursor = NULL;
}

ListaEnteros::~ListaEnteros() {
	NodoEntero * act = this->primero;
	while (this->primero) {
		act = this->primero;
		this->primero = act->getSig();
		delete act;
	}
}

void ListaEnteros::validarPosicion(int posicion) {
	if (posicion < 1 || posicion > this->tamanio) {
		throw "Indice fuera de rango";
	}
}

void ListaEnteros::altaPrincipio(int dato) {
	NodoEntero * nuevo = new NodoEntero(dato);
	nuevo->setSig(this->primero);
	this->primero = nuevo;
	this->tamanio++;
}

void ListaEnteros::altaFinal(int dato) {
	NodoEntero * act = this->primero;
	while (act && act->getSig()) {
		act = act->getSig();
	}
	NodoEntero * nuevo = new NodoEntero(dato);
	act->setSig(nuevo);
	this->tamanio++;
}

void ListaEnteros::altaPosicion(int posicion, int dato) {
	if (posicion < 1 || posicion > this->tamanio + 1) {
		throw "Indice fuera de rango";
	}

	if (posicion == 1) {
		altaPrincipio(dato);
	} else {
		NodoEntero * anterior = this->getPosicion(posicion - 1);
		NodoEntero * nuevo = new NodoEntero(dato);
		nuevo->setSig(anterior->getSig());
		anterior->setSig(nuevo);
	}
	this->tamanio++;
}

void ListaEnteros::borrarPrincipio() {
	borrarPosicion(1);
}

void ListaEnteros::borrarFinal() {
	borrarPosicion(this->tamanio);
}

void ListaEnteros::borrarPosicion(int posicion) {
	validarPosicion(posicion);

	NodoEntero * aRemover = NULL;
	if (posicion == 1) {
		aRemover = this->primero;
		this->primero = aRemover->getSig();
	} else {
		NodoEntero * anterior = getPosicion(posicion);
		aRemover = anterior->getSig();
		anterior->setSig(aRemover->getSig());
	}
	delete aRemover;
	this->tamanio--;
}

void ListaEnteros::borrarPrimeraOcurrencia(int dato) {
	NodoEntero * anterior = NULL;
	NodoEntero * actual = this->primero;
	while (actual && actual->getDato() != dato) {
		anterior = actual;
		actual = actual->getSig();
	}
	if (actual) {
		anterior->setSig(actual->getSig());
		delete actual;
		this->tamanio--;
	}
}

void ListaEnteros::borrarElemento(int dato) {
	NodoEntero * anterior = NULL;
	NodoEntero * actual = this->primero;

	while (actual) {

		if (actual->getDato() == dato) {
			if (!anterior) {
				this->primero = actual->getSig();
				delete actual;
				actual = this->primero;
			} else {
				anterior->setSig(actual->getSig());
				delete actual;
				actual = anterior->getSig();
			}
			this->tamanio--;
		} else {
			anterior = actual;
			actual = actual->getSig();
		}
 	}
}

NodoEntero * ListaEnteros::getPrimero() {
	if (!this->primero) {
		throw "Lista vacia";
	}
	return this->primero;
}

NodoEntero * ListaEnteros::getUltimo() {
	return getPosicion(this->tamanio);
}

NodoEntero * ListaEnteros::getPosicion(int posicion) {
	validarPosicion(posicion);
	NodoEntero * actual = this->primero;
	for (int i = 1; i < posicion; i++) {
		actual = actual->getSig();
	}
	return actual;
}

int ListaEnteros::getTamanio() {
	return this->tamanio;
}

void ListaEnteros::listar() {
	NodoEntero * act = this->primero;
	while (act) {
		std::cout << act->getDato() << std::endl;
		act = act->getSig();
	}
}

void ListaEnteros::listarInverso(NodoEntero * actual) {
	if (actual) {
		listarInverso(actual->getSig());
		std::cout << actual->getDato() << std::endl;
	}
}

void ListaEnteros::listarInverso() {
	listarInverso(this->primero);
}

void ListaEnteros::iniciarCursor() {
	this->cursor = NULL;
}

bool ListaEnteros::avanzarCursor() {
	if (this->cursor) {
		this->cursor = this->cursor->getSig();
	} else {
		this->cursor = this->primero;
	}
	return this->cursor != NULL;
}

int ListaEnteros::getCursor() {
	int valor;
	if (this->cursor) {
		valor = this->cursor->getDato();
	}
	return valor;
}