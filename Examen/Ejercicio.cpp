//
// Created by muribe on 29/09/23.
//
#include <iostream>
#include "Ejercicio.h"

void Ejercicio::validarPuntaje(double puntaje) {
    if (puntaje < 0 || puntaje > 10) {
        throw std::invalid_argument("El puntaje debe estar entre 0 y 10");
    }
}

void Ejercicio::validarPorcentaje(double porcentaje) {
    if (porcentaje < 0 || porcentaje > 100) {
        throw std::invalid_argument("El porcentaje debe estar entre 0 y 100");
    }
}

void Ejercicio::validarNumero(unsigned int numero) {
	if (numero < 1) {
		throw std::invalid_argument("El numero de ejercico debe ser mayor a 0");
	}
}


Ejercicio::Ejercicio(unsigned int numero) {
    this->puntaje = 0;
    this->porcentajeDeCorreccion = 0;
    this->estado = NO_CORREGIDO;
	this->numero = numero;
}

Ejercicio::~Ejercicio() {

}

double Ejercicio::getPuntaje() {
    if (this->estaCorregido()) {
        return this->puntaje;
    } else {
        throw "El ejercicio no esta corregido";
    }
}

double Ejercicio::getPorcentajeDeCorreccion() {
    return this->porcentajeDeCorreccion;
}

void Ejercicio::setPuntaje(double puntaje) {
    validarPuntaje(puntaje);
    this->puntaje = puntaje;
    this->porcentajeDeCorreccion = 100;
    this->estado = CORREGIDO;
}
void Ejercicio::setPorcentajeDeCorreccion(double porcentajeDeCorreccion) {
	validarPorcentaje(porcentajeDeCorreccion);
    this->porcentajeDeCorreccion = porcentajeDeCorreccion;
}

bool Ejercicio::estaCorregido() {
	return this->estado == CORREGIDO;
}

unsigned int Ejercicio::getNumero() {
	return this->numero;
}

void Ejercicio::setNumero(unsigned int numero) {
	validarNumero(numero);
	this->numero = numero;
}
