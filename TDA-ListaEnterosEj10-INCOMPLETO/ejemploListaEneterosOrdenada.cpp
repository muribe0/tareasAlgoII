//
// Created by muribe on 10/10/23.
//

#include "ListaEnterosOrdanada.h"

int main () {
	ListaEnterosOrdanada<int> * lista = new ListaEnterosOrdanada<int> ();
	lista->alta(0);
	lista->alta(1);
	lista->alta(2);
	lista->alta(4);
	lista->alta(6);
	lista->alta(8);

	lista->listar();
	std::cout<< std::endl;
	lista->ListarInverso();

	lista->borrarElemento(0);
	std::cout<< std::endl;
	lista->listar();

	ListaEnterosOrdanada<int> * otraLista = new ListaEnterosOrdanada<int> ();
	otraLista->alta(2);
	otraLista->alta(4);
	otraLista->alta(6);


	lista->mostrar(otraLista);

	delete lista;

}