//
// Created by muribe on 30/09/23.
//

#ifndef TAREASALGOII_CANAL_H
#define TAREASALGOII_CANAL_H

class Canal {
private:
	unsigned int numero;
	unsigned int volumenMax;
	unsigned int volumenDeUltimoUso;
	void validarNumero(unsigned int);
	void validarVolumen(unsigned int);
public:
	/*
	 * Pre: volumen debe estar entre 0 y 100, el canal debe ser mayor a 0
	 * Pos: Crea una instancia de Canal con el numero y volumen indicado
	 */
	Canal(unsigned int, unsigned int);

	Canal(unsigned int);

	/*
	 * Pre: -
	 */
	~Canal();

	/*
	 * Pre: -
	 * Pos: Devuelve el numero del canal
	 */
	unsigned int getNumero();

	/*
	 * Pre: -
	 * Pos: Devuelve el volumen maximo del canal
	 */
	unsigned int getVolumenMaximo();

	/*
	 * Pre: volumen debe estar entre 0 y 100
	 * Pos: Cambia el volumen maximo del canal
	 */
	void setVolumenMaximo(unsigned int);

	/*
	 * Pre: -
	 * Pos: Devuelve el volumen en que se escucho por ultima vez
	 */
	unsigned int getVolumenDeUltimoUso();

	/*
	 * Pre: volumen debe estar entre 0 y 100
	 * Pos: Cambia el volumen actual del canal
	 */
	void setVolumenDeUltimoUso(unsigned int);
};


#endif //TAREASALGOII_CANAL_H
