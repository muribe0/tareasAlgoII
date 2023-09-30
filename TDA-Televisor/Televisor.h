//
// Created by muribe on 30/09/23.
//

#ifndef TAREASALGOII_TELEVISOR_H
#define TAREASALGOII_TELEVISOR_H

#define ULTIMO_CANAL 140
#define PRIMER_CANAL 1


#include "Canal.h"
#include "Vector.h"

class Televisor {
private:
	Vector<Canal *> * canales;
	unsigned int canalActual;
	unsigned int volumenActual;

	void cambiarVolumenCanalActual();
	void validarCanal(Canal *);
public:
	/*
	 * Pos: Crea el Televisor con 140 canales, el canal 1
	 * 		y volumen pasado por parametro para todos los canales
	 */
	Televisor(unsigned int);

	/*
	 * Pos: Destruye el canal
	 */
	~Televisor();

	/*
	 * Pre: El canala esta entre PRIMER_CANAL y ULTIMO_CANAL
	 * Pos: Cambia el canal hacia el indicado
	 * 		y actualiza el volumen del canal
	 */
	void cambiarCanal(unsigned int);

	/*
	 * Pos: Cambia el canal hacia arria (si es el ultimo, vuelve al primero)
	 * 		y actualiza el volumen del canal
	 */
	void siguienteCanal();

	/*
	 * Pos: Cambia el canal hacia abajo (si es el primero, vuelve al ultimo)
	 * 		y actualiza el volumen del canal
	 */
	void anteriorCanal();

	/*
	 * Pos: Sube el volumen en un digito, hasta llegar a 100
	 * 		y actualiza el volumen del canal
	 */
	void subirVolumen();

	/*
	 * Pos: Baja el volumen en un digito, si es 0, lo mutea
	 *      y actualiza el volumen del canal
	 */
	void bajarVolumen();

	/*
	 * Pos: Mutea el televisor y actualiza el volumen del canal
	 */
	void mutear();

	/*
	 * Pre: El canal esta entre PRIMER_CANAL y ULTIMO_CANAL
	 * Pos: Devuelve el ultimo volumen que tuvo ese canal
	 */
	unsigned int getUltimoVolumen(Canal * canal);

	/*
	 * Pre: El canal esta entre PRIMER_CANAL y ULTIMO_CANAL
	 * Pos: Devuelve el volumen maximo al cual se escucho ese canal
	 */
	unsigned int getVolumenMaximo(Canal * canal);

	Canal * getCanalConMaximoVolumen();

};


#endif //TAREASALGOII_TELEVISOR_H
