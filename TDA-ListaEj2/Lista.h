//
// Created by muribe on 07/10/23.
//

/*
 * Implementar de forma recursiva:
 * La clase ListaEnteros con los siguientes métodos:
 * - Constructor / Destructor
 * - Alta al principio ✓
 * - Alta al final ✓
 * - Alta en posición determinada ✓
 * - Borrar primero ✓
 * - Borrar último ✓
 * - Borrar en determinada posición ✓
 * - Borrar primer elemento (se indica qué elemento quiere ser borrado, y se
 *   borra su primera aparición) ✓
 * - Borrar elemento (se indica qué elemento quiere ser borrado y se borran
 *   todas sus apariciones)
 * - Obtener primero ✓
 * - Obtener último ✓
 * - Obtener el elemento de una posición determinada ✓
 * - Obtener el tamaño de la lista ✓
 * - Listar (muestra todos los elementos de la lista) ✓
 * - Listar en forma inversa (muestra desde el último hasta el final) ✓
 * */

#ifndef TAREASALGOII_LISTA_H
#define TAREASALGOII_LISTA_H

#include "Nodo.h"
#include <iostream>

template <class T>
class ListaRecursiva {
private:
	int longitud;
	Nodo<T> *primero;
	Nodo<T> *cursor;

	void validarPosicion(int posicion) {
		if (posicion < 1 || posicion > this->longitud) {
			throw "Indice fuera de rango";
		}
	}

	void _eliminarLista(Nodo<T> * actual) {
		if (actual) {
			_eliminarLista(actual->getSiguiente());
			delete actual;
		}
	}

	void _altaEnPosicion(T dato, int posicion, Nodo<T> * anterior) {
		if (posicion == 1) {
			Nodo<T> * nuevo = new Nodo<T>(dato);
			nuevo->setSiguiente(anterior->getSiguiente());
			anterior->setSiguiente(nuevo);
			this->longitud++;
		} else {
			_altaEnPosicion(dato, posicion - 1, anterior->getSiguiente());
		}
	}

	void _borrarEnPosicion(int posicion, Nodo<T> * anterior) {
		if (posicion == 1) {
			Nodo<T> * aBorrar = anterior->getSiguiente();
			anterior->setSiguiente(aBorrar->getSiguiente());
			delete aBorrar;
			this->longitud--;
		} else {
			_borrarEnPosicion(posicion - 1, anterior->getSiguiente());
		}
	}

	void _borrarPrimeraAparicion(T dato, Nodo<T> * anterior, Nodo<T> * actual) {
		if (actual && actual->getDato() == dato) {
			// Si el anterior no es NULL
			if (anterior) {
				anterior->setSiguiente(actual->getSiguiente());
			} else { // Si el anterior es NULL
				this->primero = actual->getSiguiente();
			}
			delete actual;
			this->longitud--;
		} else {
			_borrarElemento(dato, actual, actual->getSiguiente());
		}
	}

	T _obtenerEnPosicion(int posicion, Nodo<T> * actual) {
		if (posicion == 1) {
			return actual->getDato();
		} else {
			return _obtenerEnPosicion(posicion - 1, actual->getSiguiente());
		}
	}

	void _listar(Nodo<T> * actual) {
		if (actual) {
			std::cout << actual->getDato() << std::endl;
			_listar(actual->getSiguiente());
		}
	}

	void _listarInversa(Nodo<T> * actual) {
		if (actual) {
			_listarInversa(actual->getSiguiente());
			std::cout << actual->getDato() << std::endl;
		}
	}

public:
	ListaRecursiva() {
		this->longitud = 0;
		this->primero = NULL;

		this->cursor = NULL;
	}

	~ListaRecursiva() {
		eliminarLista(this->primero);
	}

	void altaAlPrincipio(T dato) {
		Nodo<T> * nuevo = new Nodo<T>(dato);
		nuevo->setSiguiente(this->primero);
		this->primero = nuevo;
		this->longitud++;
	}

	void altaAlFinal(T dato) {
		altaEnPosicion(dato, this->longitud + 1);
	}

	void altaEnPosicion(T dato, int posicion) {
		if (posicion < 1 || posicion > this->longitud + 1) {
			throw "Indice fuera de rango";
		}
		if (posicion == 1) {
			altaAlPrincipio(dato);
		} else {
			altaEnPosicion(dato, posicion - 1, this->primero);
		}
	}

	void borrarPrimero() {
		Nodo<T> * auxiliar = this->primero->getSiguiente();
		delete this->primero;
		this->primero = auxiliar;
		this->longitud--;
	}

	void borrarUltimo() {
		borrarEnPosicion(this->longitud);
	}

	void borrarEnPosicion(int posicion) {
		validarPosicion(posicion);
		if (posicion == 1) {
			borrarPrimero();
		} else {
			_borrarEnPosicion(posicion, this->primero);
		}
	}

	void borrarPrimeraAparicion(T dato) {
		_borrarPrimeraAparicion(dato, NULL,this->primero);
	}

	T obtenerPrimero() {
		obtenerEnPosicion(1);
	}

	T obtenerUltimo() {
		return obtenerEnPosicion(this->longitud);
	}

	T obtenerEnPosicion(int posicion) {
		validarPosicion(posicion);
		return _obtenerEnPosicion(posicion, this->primero);
	}

	void obtenerTamanio() {
		return this->longitud;
	}

	void listar() {
		_listar(this->primero);
	}

	void listarInversa() {
		_listarInversa(this->primero);
	}
};

#endif //TAREASALGOII_LISTA_H
