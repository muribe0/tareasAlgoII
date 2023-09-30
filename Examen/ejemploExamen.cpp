//
// Created by muribe on 29/09/23.
//

#include <iostream>
#include "Examen.h"

void mostrarEjercicios(Examen * examen) {
	for (int i = 1; i <= examen->cantidadEjercicios(); i++) {
		std::cout << "El ejercicio "
				  << examen->getEjercicio(i)->getNumero()
				  << " tiene nota: "
				  << examen->getEjercicio(i)->getPuntaje()
				  << std::endl;
	}
}

int main () {
	Examen * miExamen = new Examen(3);
	miExamen->getEjercicio(1)->setPuntaje(3);
	miExamen->setPuntaje(10, 2);
	miExamen->setPuntaje(4, 3);

	miExamen->getEjercicio(1)->setNumero(2);
	miExamen->getEjercicio(2)->setNumero(3);
	miExamen->getEjercicio(3)->setNumero(1);

	// puntaje total
	std::cout << "La nota del examen es: " << miExamen->getPuntaje() << std::endl;
	// puntaje promedio
	std::cout << "El puntaje promedio es: " << miExamen->getPuntajePromedio() << std::endl;
	// numeros de ejercicios
	mostrarEjercicios(miExamen);
	miExamen->ordenarEjercicios();
	std::cout << "Ejercicios ordenados" << std::endl;
	mostrarEjercicios(miExamen);


	delete miExamen;
    return 0;
}