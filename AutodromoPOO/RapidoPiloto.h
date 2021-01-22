#ifndef RAPIDOPILOTO_H
#define RAPIDOPILOTO_H

#include "Piloto.h"

class RapidoPiloto : public Piloto {
    int primeiro;
public:
    RapidoPiloto(string nome);
    virtual string getTipo() const;

    virtual int getComecaCorrida()const {
        return comeca_corrida;
    }
    
    int getPrimeiro();
    void setPrimeiro(int primeiro);

    virtual bool caracteristicaPiloto(int segundo) const {
        int rande;
        if (segundo % 10 == 0) {
            rande = rand() % 100 + 1;
            if (rande > 0 && rande <= 10) {
                return false;
            }
        }
        return true;
    }
};


#endif /* RAPIDOPILOTO_H */

