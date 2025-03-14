#ifndef TEXTUI_H
#define TEXTUI_H

#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <cstring>
#include "DGV.h"
#include "Campeonato.h"
#include "Consola.h"

using namespace std;

class TextUI {
    vector<DGV> dgv;
    Campeonato * camp;
    int iter;
    static int count;
    static int flag;
public:
    TextUI();

    bool start();
    void imprimeNome();
    bool leComandos(string comando);
    bool leComandosModo2(string comando);
    vector<string> separaComando(string comando, char separador);
    bool comandoLoadPilotos(string ficheiro);
    bool comandoLoadCarros(string ficheiro);
    bool comandoLoadAutodromos(string ficheiro);
    bool comandoRemoveCarro(string id);
    bool comandoRemovePiloto(string nome);
    bool comandoRemoveAutodromo(string nome);
    int  comandoEntraNoCarro(vector <string> comando);
    bool comandoSaveDGV(string nome);
    bool comandoLoadDGV(string nome);
    bool comandoDelDGV(string nome);
    bool comandoCampeonato(vector<string> comando);
    void comandoPassaTempo(int passa);
    bool comandoDestroi(Carro * carro);
    void comandoListaCarros();
    int comandoCarregaBat(vector<string> comando);
    void comandoCarregaTudo();
    bool comandoAcidente(char carro);
    string juntarNome(vector<string> nome, int num);
    bool iniciaModo2();
    bool mostra_janela_passatempo(int num);
    void mostra_janela_inicial();
    string toLower(string str);
    string toUpper(string str);
    void imprimeLog(string msg);
    void imprimeErro(string msg);
    ~TextUI();
};

#endif /* TEXTUI_H */

