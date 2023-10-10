//
// Created by muribe on 07/10/23.
//

#ifndef TAREASALGOII_NODO_H
#define TAREASALGOII_NODO_H

template <class T>
class Nodo {
private:
	T dato;
	Nodo<T> *siguiente;
public:
	Nodo(T dato) {
		siguiente = nullptr;
		this->dato = dato;
	}

	~Nodo();

	T getDato() {
		return this->dato;
	}

	Nodo<T> * getSiguiente() {
		return this->siguiente;
	}

	void setDato(T dato) {
		this->dato = dato;
	}

	void setSiguiente(Nodo<T> *siguiente) {
		this->siguiente = siguiente;
	}
};

#endif //TAREASALGOII_NODO_H
