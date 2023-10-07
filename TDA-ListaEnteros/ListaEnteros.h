//
// Created by muribe on 06/10/23.
//

#ifndef EJERCICIOSALGOIIPARTE1_LISTAENTEROS_H
#define EJERCICIOSALGOIIPARTE1_LISTAENTEROS_H

#include "NodoEntero.h"

class ListaEnteros {
private:
	NodoEntero *primero;
	int tamanio;
	NodoEntero *cursor;

	/*
	 * Pre: posicion es un numero entero
	 * Pos: Verifica que la posicion sea valida
	 */
	void validarPosicion(int);

	/*
	 * Pre: Funcion recursiva que recibe un puntero a nodo
	 * 		y muestra por pantalla el contenido de la lista
	 * 		de manera invertida
	 */
	void listarInverso(NodoEntero *);
public:
	/*
	 * Pre: -
	 * Pos: Crea una lista vacia, con un cursor
	 */
	ListaEnteros();

	/*
	 * Pre: la lista debe estar creada
	 * Pos: Libera la memoria de la lista y sus nodos
	 */
	~ListaEnteros();

	/*
	 * Pre: -
	 * Pos: Agrega un elemento al principio de la lista
	 */
	void altaPrincipio(int);

	/*
	 * Pre: -
	 * Pos: Agrega un elemento al final de la lista
	 */
	void altaFinal(int);

	/*
	 * Pre: dato debe ser un entero
	 * Pos: Agrega un elemento en la posicion indicada
	 * 		posicion va de 1 a n
	 */
	void altaPosicion(int, int);

	/*
	 * Pre: -
	 * Pos: Borra el primer elemento de la lista
	 */
	void borrarPrincipio();

	/*
	 * Pre: -
	 * Pos: Borra el ultimo elemento de la lista
	 */
	void borrarFinal();

	/*
	 * Pre: posicion debe ser un entero
	 * Pos: Borra el elemento de la posicion indicada
	 * 		posicion va de 1 a n
	 */
	void borrarPosicion(int);

	/*
	 * Pre: -
	 * Pos: Borra la primera ocurrencia del elemento
	 */
	void borrarPrimeraOcurrencia(int);

	/*
	 * Pre: -
	 * Pos: Borra todas las ocurrencias del elemento
	 */
	void borrarElemento(int);

	/*
	 * Pre: la lista debe tener al menos un elemento
	 * Pos: Retorna el primer elemento de la lista
	 */
	NodoEntero * getPrimero();

	/*
	 * Pre: la lista debe tener al menos un elemento
	 * Pos: Retorna true si el elemento se encuentra en la lista
	 */
	NodoEntero * getUltimo();

	/*
	 * Pre: posicion debe ser un entero
	 * Pos: Retorna el elemento de la posicion indicada
	 * 		posicion va de 1 a n
	 */
	NodoEntero * getPosicion(int);

	/*
	 * Pre: -
	 * Pos: Retorna el tamanio de la lista
	 */
	int getTamanio();

	/*
	 * Pre: -
	 * Pos: muestra la lista por pantalla
	 */
	void listar();

	/*
	 * Pre: -
	 * Pos: muestra la lista por pantalla de manera invertida
	 */
	void listarInverso();

	/*
	 * Pre: -
	 * Pos: Inicializa el cursor en NULL
	 */
	void iniciarCursor();

	/*
	 * Pre: -
	 * Pos: Avanza el cursor una posicion y retorna true si pudo avanzar
	 */
	bool avanzarCursor();

	/*
	 * Pre: -
	 * Pos: Retorna el elemento del cursor
	 */
	int getCursor();

};


#endif //EJERCICIOSALGOIIPARTE1_LISTAENTEROS_H
