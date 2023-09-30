//
// Created by muribe on 29/09/23.
//
/*
 * Disenar la especificacion e implementar el TDA Examen. Debe proveer operaciones para:
* crearlo indicando la cantidad total de ejercicios que tiene.
* puntuar un ejercicio, indicando su porcentaje de correccion [0.0, 100.0]
* contar la cantidad de ejercicio que tiene el examen
* contar los ejercicio que ya fueron corregidos
* calcular la nota, devolviendo la nota final del examen, comprendida en el rango [0.0, 10.0]
* calcular el puntaje promedio obtenido por ejercicio.
 *
 * tip: el porcentaje de correccion indica que tanto ha corregido el profesor
 *
 * T-odo lo calculable debe hacerse mediante metodos. No atributos.
   A menos que se me pida optimizar el tiempo de ejecucion.

   Desafio: Hacer que los ejercicios tengan un numero asociado,
   que describa el orden en el que deberian estar y un metodo para ordenarlos
 */

#include "Examen.h"

Examen::Examen(unsigned int cantidadDeEjericicos) {
    this->ejercicios = new Vector<Ejercicio *>(cantidadDeEjericicos);
    for (int i = 0; i < this->ejercicios->getLongitud(); i++) {
        this->ejercicios->setDato(i, new Ejercicio(i+1));
    }
}

Examen::~Examen() {
    for (int i = 0; i < this->ejercicios->getLongitud(); i++) {
        if (this->ejercicios->getDato(i)) {
            delete this->ejercicios->getDato(i);
        }
    }
    delete this->ejercicios;
}

Ejercicio * Examen::getEjercicio(unsigned int indice) {
	validarIndice(indice-1);
	return this->ejercicios->getDato(indice-1);
}


void Examen::validarIndice(unsigned int indice) {
    if (indice < 0 || indice >= this->ejercicios->getLongitud()) {
        throw "Indice fuera de rango";
    }
}

unsigned int Examen::cantidadEjercicios() {
    return this->ejercicios->getLongitud();
}

unsigned int Examen::cantidadEjerciciosCorregidos() {
    unsigned int cantidadDeCorregidos = 0;
    for (int i = 0; i < this->ejercicios->getLongitud(); i++) {
        if (this->ejercicios->getDato(i)->estaCorregido()) {
			cantidadDeCorregidos++;
        }
    }
    return cantidadDeCorregidos;
}



double Examen::getPuntaje() {
    double puntaje = 0;
    for (int i = 0; i < this->ejercicios->getLongitud(); i++) {
        if (!this->ejercicios->getDato(i)->estaCorregido()) {
            throw "El examen no esta corregido";
        }
        puntaje += this->ejercicios->getDato(i)->getPuntaje();
    }
	if (puntaje > 10) {
		return 10;
	}
    return puntaje;
}

double Examen::getPuntajePromedio() {
    return this->getPuntaje() / this->cantidadEjercicios();
}

void Examen::setPuntaje(double puntaje, unsigned int posicion) {
	validarIndice(posicion-1);
	this->ejercicios->getDato(posicion-1)->setPuntaje(puntaje);
}

void Examen::ordenarEjercicios() {
	if (this->cantidadEjercicios() > 0) {
		unsigned int key;
		double puntaje;
		for (int i = 1; i < this->cantidadEjercicios(); i++) {
			key = this->ejercicios->getDato(i)->getNumero();
			puntaje = this->ejercicios->getDato(i)->getPuntaje();
			int j = i - 1;
			while (j >= 0 && key < this->ejercicios->getDato(j)->getNumero()) {
				this->ejercicios->getDato(j + 1)->setNumero(this->ejercicios->getDato(j)->getNumero());
				this->ejercicios->getDato(j + 1)->setPuntaje(this->ejercicios->getDato(j)->getPuntaje());
//				arr[j + 1] = arr[j];
				j--;
			}
			this->ejercicios->getDato(j + 1)->setNumero(key);
			this->ejercicios->getDato(j + 1)->setPuntaje(puntaje);
//			arr[j + 1] = key;
		}
	}

}