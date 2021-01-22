#include "RapidoPiloto.h"
#include "Autodromo.h"

RapidoPiloto::RapidoPiloto(string nome) : Piloto("rapido", nome) {
    this->comeca_corrida = 0;
    this->acelera = false;
    this->trava = false;
    this->tipo = "rapido";
}

string RapidoPiloto::getTipo() const {
    return this->tipo;
}