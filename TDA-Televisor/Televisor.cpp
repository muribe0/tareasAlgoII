//
// Created by muribe on 30/09/23.
//

#include "Televisor.h"

Televisor::Televisor(unsigned int volumen) {
	this->canales = new Vector<Canal *>(ULTIMO_CANAL);
	for (int i = 0; i < 140; i++) {
		this->canales->setDato(i, new Canal(i + 1, volumen));
	}
	this->canalActual = 1;
	this->volumenActual = volumen;
}

Televisor::~Televisor() {
	for (int i = 0; i < 140; i++) {
		if (this->canales->getDato(i)) {
			delete this->canales->getDato(i);
		}
	}
	delete this->canales;
}

Canal * Televisor::getCanalActual() {
    return this->canales->getDato(this->canalActual - 1);
}

unsigned int Televisor::getVolumenActual() {
    return this->volumenActual;
}

void Televisor::cambiarCanal(unsigned int canal) {
	if (canal < PRIMER_CANAL || canal > ULTIMO_CANAL) {
		throw std::invalid_argument("El canal debe estar entre 1 y 140");
	}
	this->canalActual = canal;
	// Cambia el volumen del canal actual
	cambiarVolumenCanalActual();
}

void Televisor::siguienteCanal() {
	if (this->canalActual == ULTIMO_CANAL) {
		this->canalActual = PRIMER_CANAL;
	} else {
		this->canalActual++;
	}
	// Cambia el volumen del siguiente canal
	cambiarVolumenCanalActual();
}

void Televisor::anteriorCanal() {
	if (this->canalActual == PRIMER_CANAL) {
		this->canalActual = ULTIMO_CANAL;
	} else {
		this->canalActual--;
	}
	// Cambia el volumen del anterior canal
	cambiarVolumenCanalActual();
}

void Televisor::subirVolumen() {
	if (this->volumenActual < 100) {
		this->volumenActual++;
	}
	// Cambia el volumen del canal actual
	cambiarVolumenCanalActual();
}

void Televisor::bajarVolumen() {
	if (this->volumenActual > 0) {
		this->volumenActual--;
	}
	// Cambia el volumen del canal actual
	cambiarVolumenCanalActual();
}

void Televisor::mutear() {
	this->volumenActual = 0;
	cambiarVolumenCanalActual();
}

unsigned int Televisor::getUltimoVolumen(Canal * canal) {
	validarCanal(canal);
	return this->canales->getDato(canal->getNumero() - 1)->getVolumenDeUltimoUso();
}

unsigned int Televisor::getVolumenMaximo(Canal *canal) {
	validarCanal(canal);
	return this->canales->getDato(canal->getNumero() - 1)->getVolumenDeUltimoUso();
}

Canal * Televisor::getCanalConMaximoVolumen() {
	Canal * canalConMaximoVolumen;
	unsigned int volumenMaximo = 0;
	for (int i = 0; i < ULTIMO_CANAL; i++) {
        Canal * canalAux = this->canales->getDato(i);
		if (volumenMaximo < canalAux->getVolumenMaximo()) {
			volumenMaximo = canalAux->getVolumenMaximo();
			canalConMaximoVolumen = canalAux;
		}
	}
    return canalConMaximoVolumen;
}


void Televisor::cambiarVolumenCanalActual() {
	this->canales->getDato(this->canalActual - 1)->setVolumenDeUltimoUso(this->volumenActual);
}

void Televisor::validarCanal(Canal *canal) {
	if (!canal) {
		throw std::invalid_argument("El canal no puede ser nulo");
	} else if (canal->getNumero() < PRIMER_CANAL || canal->getNumero() > ULTIMO_CANAL) {
		throw std::invalid_argument("El canal debe estar entre 1 y 140");
	}
}