#ifndef SURPRESAPILOTO_H
#define SURPRESAPILOTO_H

#include "Piloto.h"

class SurpresaPiloto : public Piloto {
    
public:
    SurpresaPiloto(string nome);
    virtual string getTipo() const;

    virtual int getComecaCorrida() const {
        return comeca_corrida;
    }

    virtual bool caracteristicaPiloto(int segundo) const {
        int rande;
        rande = (rand() % 100) + 1;
        if (rande > 0 && rande <= 25) {
            return false;
        }
        return true;
    }


    virtual ~SurpresaPiloto() {

    }
};

#endif /* SURPRESAPILOTO_H */

