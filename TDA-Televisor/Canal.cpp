//
// Created by muribe on 30/09/23.
//

#include "Canal.h"
#include <iostream>

void Canal::validarNumero(unsigned int numero) {
	if (numero < 1) {
		throw std::invalid_argument("El numero de canal debe ser mayor a 1");
	}
}

void Canal::validarVolumen(unsigned int volumen) {
	if (volumen < 0 || volumen > 100) {
		throw std::invalid_argument("El volumen debe estar entre 1 y 100");
	}
}

Canal::Canal(unsigned int numero, unsigned int volumenInicial) {
	validarNumero(numero);
	this->numero = numero;
	this->volumenMax = volumenInicial;
	this->volumenDeUltimoUso = volumenInicial;
}

Canal::Canal(unsigned int numero) {
	this->numero = numero;
	this->volumenMax = 0;
	this->volumenDeUltimoUso = 0;
}

Canal::~Canal() {
}

unsigned int Canal::getNumero() {
	return this->numero;
}

unsigned int Canal::getVolumenMaximo() {
	return this->volumenMax;
}

void Canal::setVolumenMaximo(unsigned int volumen) {
	validarVolumen(volumen);
	this->volumenMax = volumen;
}

unsigned int Canal::getVolumenDeUltimoUso() {
	return this->volumenDeUltimoUso;
}

void Canal::setVolumenDeUltimoUso(unsigned int volumen) {
	if (volumen > this->volumenMax) {
		this->volumenMax = volumen;
	}
	validarVolumen(volumen);
	this->volumenDeUltimoUso = volumen;
}