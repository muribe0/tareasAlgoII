//
// Created by muribe on 10/10/23.
//


#include <iostream>
#include "Televisor.h"
using namespace std;

void mostrarVolumen(Televisor * televisor) {
    cout << "Volumen: " << televisor->getVolumenActual() << endl;
}

void mostrarCanalActual(Televisor * televisor) {
    Canal * canal = televisor->getCanalActual();
    cout << "Canal :" << canal->getNumero() << endl;
    cout << "Volumen ultima vez :" << televisor->getVolumenMaximo(canal) << endl;
    cout << "Volumen maximo: " << televisor->getVolumenMaximo(canal) << endl;

}

int main () {

    Televisor * televisor = new Televisor(10);

    cout << "Canal actual: " << televisor->getCanalActual()->getNumero() << endl;
    mostrarVolumen(televisor);
    cout << "Canal con volumen maximo " << televisor->getCanalConMaximoVolumen()->getNumero() << endl;

    // Test de subirVolumen, bajarVolumen y mutear

    televisor->subirVolumen();
    mostrarVolumen(televisor);
    televisor->bajarVolumen();
    mostrarVolumen(televisor);
    televisor->mutear();
    mostrarVolumen(televisor);

    cout << "Subo el volumen por 40" << endl;
    for (int i = 0; i < 40; i++) {
        televisor->subirVolumen();
    }
    mostrarVolumen(televisor);

    // Test de cambio de canal

    cout << "Cambio al canal 55" << endl;
    televisor->cambiarCanal(55);
    mostrarCanalActual(televisor);
    televisor->siguienteCanal();

    mostrarCanalActual(televisor);

    cout << "Subo el volumen por 40" << endl;
    for (int i = 0; i < 40; i++) {
        televisor->subirVolumen();
    }

    mostrarCanalActual(televisor);

    // Volumen escuchado por ultima vez

    cout << "Volumen escuchado por ultima vez del canal actual: "
         << televisor->getUltimoVolumen(televisor->getCanalActual())
         << endl;

    // Canal con el volumen maximo

    cout << "bajo el volumen por 50" << endl;
    for (int i = 0; i < 50; i++) {
        televisor->bajarVolumen();
    }


    televisor->anteriorCanal();
    televisor->anteriorCanal();
    televisor->anteriorCanal();

    mostrarCanalActual(televisor);

    cout << "Canal con maximo volumen: " << televisor->getCanalConMaximoVolumen()->getNumero() << endl;


    cout << "bajo el volumen por 50" << endl;
    for (int i = 0; i < 50; i++) {
        televisor->bajarVolumen();
    }

    mostrarVolumen(televisor);

    cout << "subo el volumen por 150" << endl;
    for (int i = 0; i < 150; i++) {
        televisor->subirVolumen();
    }

    mostrarVolumen(televisor);
    delete televisor;


    return 0;
}