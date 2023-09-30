//
// Created by muribe on 29/09/23.
//


#ifndef EJERCICIOSALGOIIPARTE1_EXAMEN_H
#define EJERCICIOSALGOIIPARTE1_EXAMEN_H

#include "Vector.h"
#include "Ejercicio.h"

class Examen {
private:
    Vector<Ejercicio *> * ejercicios;
    void validarIndice(unsigned int);
public:
    /*
     * Pre: cantidadDeEjercicios es la cantidad de ejercicios que tiene el examen
     * Pos: crea una instancia de Examen con la cantidad de ejercicios indicada
     * 	y todos los ejercicios con nota 0
     */
    Examen(unsigned int cantidadDeEjercicios);

	/*
	 * Pre: -
	 * Pos: Destruye la instancia de Examen y libera la memoria de todos los ejercicios
	 */
    ~Examen();

	/*
	 * Pre: numeroDeEjercicio debe ser un numero de ejercicio valido [1, cantidadEjercicios]
	 * Pos: Devuelve el ejercicio con
	 */
    Ejercicio * getEjercicio(unsigned int);

    /*
     * Pos: devulve la cantidad de ejercicios corregidos del examen
     */
    unsigned int cantidadEjercicios();

    /*
     * Pre:
     * Pos: Devuelve la cantidad de ejercicios corregidos
     */
    unsigned int cantidadEjerciciosCorregidos();

    /*
     * Pre: El examen debe estar completamente corregido
     * Pos: Devuelve el puntaje del examen [0, 10]
     */
    double getPuntaje();

    /*
     * Pre: El examen debe estar completamente corregido
     * Pos: Devuelve la nota promedio del examen [0, 10]
     */
    double getPuntajePromedio();

	/*
	 * Pre: numeroDeEjercicio debe ser un numero de ejercicio valido [1, cantidadEjercicios]
	 * 		puntaje debe estar entre [0, 10]
	 * Pos: Asigna el puntaje a un ejercicio
	 */
	void setPuntaje(double, unsigned int);

	void ordenarEjercicios();
};


#endif //EJERCICIOSALGOIIPARTE1_EXAMEN_H
