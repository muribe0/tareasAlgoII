//
// Created by muribe on 10/10/23.
//
/*
 * Implementar de forma recursiva:
 * La clase ListaEnteros con los siguientes métodos:
 * - Constructor / Destructor ✓
 * - Alta al final ✓
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
#ifndef TAREASALGOII_LISTAENTEROSE7_H
#define TAREASALGOII_LISTAENTEROSE7_H

/*
 * 7) Diseñar e implementar una nueva ListaEnteros donde el alta será únicamente en
	  orden, por lo que no se indicará la posición. Tener en cuenta que puede haber
	  elementos repetidos.
 */

#include "Nodo.h"
#include <iostream>

template <class T>
class ListaEnterosOrdanada {
private:
	Nodo<T> * ultimo;
	unsigned int longitud;

	void validarPosicion(unsigned int posicion) {
		if (posicion < 1 || posicion > this->longitud) {
			throw "Indice fuera de rango";
		}
	}

	void _listar(Nodo <T> * actual) {
		if (actual) {
			_listar(actual->getSiguiente());
			std::cout << actual->getDato() << " ";
		}
	}
public:

	/*
	 * Crea una lista vacia con longitud 0
	 */
	ListaEnterosOrdanada() {
		this->ultimo = NULL;
		this->longitud = 0;
	}

	~ListaEnterosOrdanada() {
		Nodo<T> * aBorrar = this->ultimo;
		while (aBorrar) {
			this->ultimo = this->ultimo->getSiguiente();
			delete aBorrar;
			aBorrar = this->ultimo;
		}
	}

	void alta(T dato) {
		Nodo <T> * nuevo = new Nodo<T>(dato);
		nuevo->setSiguiente(this->ultimo);
		this->ultimo = nuevo;
		this->longitud++;
	}

	void borrarPosicion(unsigned int posicion) {
		validarPosicion(posicion);
		posicion = this->longitud - posicion + 1;
		Nodo<T> * aBorrar;
		if (posicion == this->longitud) {
			aBorrar = this->ultimo;
			this->ultimo = this->ultimo->getSiguiente();

		} else {
			Nodo<T> * anterior = this->ultimo;
			for (int i = 1; i < posicion && anterior; i++) {
				anterior = anterior->getSiguiente();
			}
			aBorrar = anterior->getSiguiente();
			anterior->setSiguiente(aBorrar->getSiguiente());
		}
		delete aBorrar;
		this->longitud--;
	}

	void borrarPrimero() {
		borrarPosicion(1);
	}

	void borrarUltimo() {
		borrarPosicion(this->longitud);
	}

	void borrarPrimeraAparicion(T dato) {
		Nodo<T> * anterior = NULL;
		Nodo<T> * actual = this->ultimo;
		while (actual && actual->getDato() != dato) {
			anterior = actual;
			actual = actual->getSiguiente();
		}
		if (actual) {
			if (anterior) {
				anterior->setSiguiente(actual->getSiguiente());
			} else {
				this->ultimo = actual->getSiguiente();
			}
			delete actual;
			this->longitud--;
		}
	}

	void borrarElemento(T dato) {
		Nodo <T> * anterior = NULL;
		Nodo <T> * actual = this-ultimo;
		bool borrado = false;

		while (actual) {
			if (actual->getDato() == dato) {
				if (anterior) {
					anterior->setSiguiente(actual->getSiguiente());
					delete actual;
					actual = anterior->getSiguiente();
				} else {
					this->ultimo = actual->getSiguiente();
					delete actual;
					actual = this->ultimo;
				}
				this->longitud--;
				borrado = true;
			} else {
				anterior = actual;
				actual = actual->getSiguiente();
			}
		}
		if (!borrado) {
			throw "No se encontro el elemento a borrar";
		}
	}

	T obtenerPrimero() {
		return obtenerPosicion(1);
	}

	T obtenerUltimo() {
		return obtenerPosicion(this->longitud);
	}

	T obtenerPosicion(unsigned int posicion) {
		validarPosicion(posicion);
		posicion = this->longitud - posicion + 1;
		Nodo<T> * actual = this->ultimo;
		for (int i = 1; i < posicion; i++) {
			actual = actual->getSiguiente();
		}
		return actual->getDato();
	}

	unsigned int obtenerLongitud() {
		return this->longitud;
	}

	void listar() {
		_listar(this->ultimo);
	}

	void ListarInverso() {
		Nodo<T> * actual = this->ultimo;
		while (actual) {
			std::cout << actual->getDato() << " ";
			actual = actual->getSiguiente();
		}
	}
};

#endif //TAREASALGOII_LISTAENTEROSE7_H
