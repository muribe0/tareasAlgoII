//
// Created by muribe on 06/10/23.
//
#include "ListaEnteros.h"
#include <iostream>


int main () {
	ListaEnteros * lista = new ListaEnteros();
	lista->altaPrincipio(1);
	lista->altaPrincipio(2);
	lista->altaPrincipio(3);
	lista->altaPosicion(3, 5);
	lista->altaPosicion(2, 5);
	lista->altaPosicion(5, 5);

	lista->listar();
	std::cout<< std::endl;
	lista->listarInverso();

	lista->borrarElemento(5);
	std::cout<< std::endl;
	lista->listar();
	delete lista;

}