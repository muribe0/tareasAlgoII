//
// Created by muribe on 06/10/23.
//

#ifndef EJERCICIOSALGOIIPARTE1_NODOENTERO_H
#define EJERCICIOSALGOIIPARTE1_NODOENTERO_H


class NodoEntero {
private:
	int dato;
	NodoEntero *sig;
public:
	NodoEntero(int);

	int getDato();

	NodoEntero * getSig();

	void setDato(int);

	void setSig(NodoEntero *);
};


#endif //EJERCICIOSALGOIIPARTE1_NODOENTERO_H
