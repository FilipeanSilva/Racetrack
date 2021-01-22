#include "CrazyPiloto.h"

CrazyPiloto::CrazyPiloto(string nome) : Piloto("crazy", nome) {
    int a =(rand()%6)+1;
    this->comeca_corrida = a-1;
    this->acelera = false;
    this->trava = false;
    this->tipo = "crazy";
    srand((int)time(0));
}

string CrazyPiloto::getTipo() const {
    return this->tipo;
}
