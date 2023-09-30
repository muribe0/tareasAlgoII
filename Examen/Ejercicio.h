//
// Created by muribe on 29/09/23.
//

#ifndef EJERCICIOSALGOIIPARTE1_EJERCICIO_H
#define EJERCICIOSALGOIIPARTE1_EJERCICIO_H
enum EstadoEjercicio {
    CORREGIDO,
    NO_CORREGIDO
};

class Ejercicio {
private:
    double puntaje;
    double porcentajeDeCorreccion;
    EstadoEjercicio estado;
	unsigned int numero;
    void validarPuntaje(double);
    void validarPorcentaje(double);
	void validarNumero(unsigned int);
public:


	/*
	 * Crea la instancia de Ejercicio con puntaje 0 y porcentaje de correccion 0
	 * lo marca como no corregido y le asigna el № de ejercicio
	 */
    Ejercicio(unsigned int);

	/*
	 * Destruye la instancia de Ejercicio
	 */
    ~Ejercicio();

    /*
     * Pre: Si esta corregido
     * Pos: Devuelve el puntaje del ejercicio [0, 10]
     */
    double getPuntaje();

    /*
     * Pre: Si exite el ejercicio
     * Pos: Devuelve el porcentaje de correccion del ejercicio [0, 100]
     */
    double getPorcentajeDeCorreccion();

    /*
     * Pre: puntaje esta entre [0, 10]
     * Pos: cambia el puntaje y lo marca como corregido
     */
	void setPuntaje(double);

    /*
     * Pre: porcentajeDeCorreccion esta entre [0, 100]
     * Pos: cambia el porcentaje de correccion
     */
	void setPorcentajeDeCorreccion(double);

    /*
     * Pre: -
     * Pos: devuelve el estado de correccion del ejercicio
     */
    bool estaCorregido();

	/*
	 * Pre: -
	 * Pos: devuelve el numero del ejercicio
	 */
	unsigned int getNumero();

	/*
	 * Pre: numero es mayor a 0
	 * Pos: cambia el numero de ejercicio
	 */
	void setNumero(unsigned int);
};

#endif //EJERCICIOSALGOIIPARTE1_EJERCICIO_H
