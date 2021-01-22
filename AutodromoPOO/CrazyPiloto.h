#ifndef CRAZYPILOTO_H
#define CRAZYPILOTO_H


#include "Piloto.h"

class CrazyPiloto : public Piloto {
public:
    CrazyPiloto(string nome);
    virtual string getTipo() const;

    virtual int getComecaCorrida() const {
        return comeca_corrida;
    }

    virtual bool caracteristicaPiloto(int segundo) const {
        int rande;
        rande = (rand() % 100) + 1;
        if (rande > 0 && rande <= 5) {
            return false;
        }
        return true;
    }
};


#endif /* CRAZYPILOTO_H */

