#ifndef CAMPEONATO_H
#define CAMPEONATO_H

#include "Autodromo.h"

class Campeonato{
    vector <Autodromo *> campeonato;
    int actualAutodromo;   // saber em que corrida vai
    vector <Autodromo> todas_as_pistas;
    vector <Carro*> concorrentes; //carros e pilotos que estao a participar no campeonato
    vector <Piloto *> classificacao; // que pilotos e carros que estao a frente
public:
    Campeonato();
    int getActualAutodromo();
    void setActualAutodromo(int prox);
    vector <Autodromo*> getAutodromoCampeonato();
    vector <Carro*> getConcorrentes();
    void addAutodromoParaCampeonato( Autodromo *autodromo);
    void addAutodromo(int pistas, int comp, string nome);
    void addConcorrentes(int vel, double cap_ini, int cap_max, string marca, char id, Piloto * piloto, string modelo);
    void destroiCarro(Carro* carro);
    bool removeAutodromo(string nome);
    void mostraClassificacaoFinal();
    void mostraAutodromos();
    vector <Autodromo> getTodasAsPistas();
    Autodromo *getPista(string nome);   // Todas as pistas
    void addConcorrentesAoAutodromo();
    ~Campeonato();
};

#endif /* CAMPEONATO_H */

