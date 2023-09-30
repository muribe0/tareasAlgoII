
#ifndef EJERCICIOSALGOIIPARTE1_VECTOR_H
#define EJERCICIOSALGOIIPARTE1_VECTOR_H

#include <iostream>

template <class T> class Vector {
private:
    T *datos;
    unsigned int longitud;
    void validarIndice(unsigned int indice) {
        std::cout << "Se construye el vector" << std::endl;
        if (indice >= longitud) {
            throw std::invalid_argument("El indice debe ser menor a la longitud del vector");
        }
    }
public:

    Vector(unsigned int longitud) {
        if (longitud < 1) {
            throw std::invalid_argument("El tamaño del vector debe ser mayor que 0");
        }
        this->longitud = longitud;
        datos = new T[longitud];
    }

    ~Vector() {
        delete [] datos;
    }


    int getLongitud() {
        return longitud;
    }


    T getDato(unsigned int indice) {
//        validarIndice(indice);
        return datos[indice];
    }

    /*
     * Pre: 0 <= indice < longitud
     * Pos: Setea el dato en la posicion indice
     */
    void setDato(unsigned int indice, T dato) {
//        validarIndice(indice);
        if (datos[indice] != NULL) {
            throw std::invalid_argument("La posicion ya esta ocupada");
        }
        datos[indice] = dato;
    }
};


#endif //EJERCICIOSALGOIIPARTE1_VECTOR_H
