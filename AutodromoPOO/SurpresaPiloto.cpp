#include "SurpresaPiloto.h"

SurpresaPiloto::SurpresaPiloto(string nome) : Piloto("surpresa", nome) {
    this->comeca_corrida = 0;
    this->acelera = false;
    this->trava = false;
    this->tipo = "surpresa";
}

string SurpresaPiloto::getTipo() const {
    return this->tipo;
}
