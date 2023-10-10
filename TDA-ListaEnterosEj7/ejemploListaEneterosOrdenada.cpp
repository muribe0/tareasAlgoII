//
// Created by muribe on 10/10/23.
//

#include "ListaEnterosOrdanada.h"

int main () {
	ListaEnterosOrdanada<int> * lista = new ListaEnterosOrdanada<int> ();
	lista->alta(1);
	lista->alta(2);
	lista->alta(2);
	lista->alta(3);

	lista->listar();
	std::cout<< std::endl;
	lista->ListarInverso();

	lista->borrarElemento(5);
	std::cout<< std::endl;
	lista->listar();
	delete lista;

}