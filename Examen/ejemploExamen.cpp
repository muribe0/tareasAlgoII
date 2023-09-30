//
// Created by muribe on 29/09/23.
//

#include <iostream>
#include "Examen.h"

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
	for (int i = 1; i <= miExamen->cantidadEjercicios(); i++) {
		std::cout << "El ejercicio "
				  << miExamen->getEjercicio(i)->getNumero()
				  << " tiene nota: "
				  << miExamen->getEjercicio(i)->getPuntaje()
				  << std::endl;
	}

	delete miExamen;
    return 0;
}