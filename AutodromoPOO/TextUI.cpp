#include <time.h>
#include "TextUI.h"

TextUI::TextUI() {
    camp = new Campeonato();
}

void resetCores() {
    Consola::setTextColor(Consola::BRANCO);
    Consola::setBackgroundColor(Consola::PRETO);
}

void ecraMenu() {

    Consola::clrscr();
    Consola::setScreenSize(40, 120);

    Consola::setBackgroundColor(Consola::ROXO);
    Consola::setTextColor(Consola::ROXO);

    //Delimitações das secções

    //XX
    for (int x = 0; x < 120; x++) {
        Consola::gotoxy(x, 39);
        cout << (char) 219;
    }

    for (int x = 0; x < 120; x++) {
        Consola::gotoxy(x, 0);
        cout << (char) 219;
        Consola::gotoxy(x, 1);
        cout << (char) 219;
        Consola::gotoxy(x, 2);
        cout << (char) 219;
        Consola::gotoxy(x, 3);
        cout << (char) 219;
    }

    //YY
    for (int y = 0; y < 40; y++) {
        Consola::gotoxy(0, y);
        cout << (char) 219;
        Consola::gotoxy(1, y);
        cout << (char) 219;
        Consola::gotoxy(2, y);
        cout << (char) 219;
        Consola::gotoxy(3, y);
        cout << (char) 219;
        Consola::gotoxy(4, y);
        cout << (char) 219;
        Consola::gotoxy(5, y);
        cout << (char) 219;
    }



    for (int y = 0; y < 40; y++) {
        Consola::gotoxy(114, y);
        cout << (char) 219;
        Consola::gotoxy(115, y);
        cout << (char) 219;
        Consola::gotoxy(116, y);
        cout << (char) 219;
        Consola::gotoxy(117, y);
        cout << (char) 219;
        Consola::gotoxy(118, y);
        cout << (char) 219;
        Consola::gotoxy(199, y);
        cout << (char) 219;
    }
    resetCores();
}

char ecraMenuInicial() {
    Consola::clrscr();
    Consola::setScreenSize(12, 86);

    Consola::setBackgroundColor(Consola::VERMELHO);
    Consola::setTextColor(Consola::VERMELHO);

    //XX
    for (int x = 0; x < 86; x++) {
        Consola::gotoxy(x, 11);
        cout << " ";
    }

    for (int x = 0; x < 86; x++) {
        Consola::gotoxy(x, 0);
        cout << " ";
    }

    //YY
    for (int y = 0; y < 12; y++) {
        Consola::gotoxy(0, y);
        cout << " ";
        Consola::gotoxy(1, y);
        cout << " ";
    }



    for (int y = 0; y < 12; y++) {
        Consola::gotoxy(85, y);
        cout << " ";
        Consola::gotoxy(84, y);
        cout << " ";
    }
    resetCores();

    char ex;
    Consola::gotoxy(20, 3);
    Consola::setBackgroundColor(Consola::PRETO);
    Consola::setTextColor(Consola::COR_DE_ROSA);
    cout << "Deseja iniciar o programa com ficheiros predefenidos ?";
    resetCores();
    Consola::gotoxy(35, 6);
    Consola::setTextColor(Consola::CYAN_CLARO);
    cout << "S";
    resetCores();
    Consola::gotoxy(37, 6);
    cout << "-> Sim ou";
    Consola::gotoxy(47, 6);
    Consola::setTextColor(Consola::AMARELO_CLARO);
    cout << "N";
    Consola::gotoxy(49, 6);
    resetCores();
    cout << "-> Nao";
    Consola::gotoxy(35, 7);
    cout << "Reposta: ";
    cin >> ex;

    return ex;
}

void OutputInicial(vector<string> listaComandos) {
    Consola::gotoxy(43, 6);
    Consola::setTextColor(Consola::COR_DE_ROSA);
    Consola::setBackgroundColor(Consola::CYAN_CLARO);
    cout << "** Bem vindo a corrida de carros **" << endl << endl;
    resetCores();

    Consola::gotoxy(43, 10);
    Consola::setTextColor(Consola::VERDE_CLARO);
    Consola::setBackgroundColor(Consola::CINZENTO);
    cout << "Para definir mundo:\n" << endl;
    resetCores();

    int aux = 11;
    for (auto i = listaComandos.begin(); i != listaComandos.end(); i++) {
        Consola::gotoxy(43, aux++);
        if (aux % 2 == 0)
            Consola::setTextColor(Consola::CYAN);
        else
            Consola::setTextColor(Consola::ROXO);
        cout << "->" << *i;
    }
    resetCores();
}

bool TextUI::start() {
    dgv.push_back(DGV());
    iter = 0;
    string comando;

    Consola::setScreenSize(40, 120);
    vector<string> listaComandos = {"carregaP", "carregaC", "carregaA", "cria", "apaga", "cria",
        "apaga", "entranocarro", "saidocarro", "lista", "savedgv", "loaddgv", "deldgv", "campeonato", "sair"};

    do {
        Consola::clrscr();
        ecraMenu();
        OutputInicial(listaComandos);
        Consola::gotoxy(43, 30);
        Consola::setTextColor(Consola::VERMELHO_CLARO);
        cout << "-> ";
        resetCores();
        cout << "Comando: ";
        getline(cin, comando);
        resetCores();
        Consola::clrscr();
    } while (leComandos(this->toLower(comando)));
    if (comando == "sair") {
        return false;
    }
    Consola::setTextColor(Consola::COR_DE_ROSA);
    Consola::setBackgroundColor(Consola::CYAN_CLARO);
    cout << "------------Entrou no modo 2------------\n";
    do {
        resetCores();
        Consola::setTextColor(Consola::VERMELHO);
        cout << "->";
        resetCores();
        cout << "Comando: ";
        getline(cin, comando);
    } while (leComandosModo2(this->toLower(comando)));

}

bool TextUI::iniciaModo2() {
    for (int i = 0; i < camp->getConcorrentes().size(); i++) {
        camp->getConcorrentes()[i]->setCapActual(camp->getConcorrentes()[i]->getCapInicial());
        camp->getConcorrentes()[i]->setVelocidade(0);
        camp->getConcorrentes()[i]->setPosicao(0);
        camp->getConcorrentes()[i]->getPiloto()->setAcelera(false);
        camp->getConcorrentes()[i]->getPiloto()->setTrava(false);
    }
    camp->addConcorrentesAoAutodromo();
    camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->carrosParaCorrida();


    mostra_janela_inicial();
    //Mostra Janela inicial - mostra competidores e resp carros

    //Mostra Janela Corrida - mostra interface atualizada com pista e classificação
    return true;
}

bool TextUI::mostra_janela_passatempo(int num) {
    Consola::gotoxy(0, 1);
    Consola::clrscr();
    cout << "A corrida do " << camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getNome() << ": " << endl;

    int n_carros_2 = camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getCorrida().size();

    Consola::gotoxy(0, 1);

    for (int h = 0; h < n_carros_2; h++) {
        Consola::setBackgroundColor(Consola::CINZENTO + h);
        for (int k = 0; k < 100; k++) {
            cout << " ";
        }
        Consola::setBackgroundColor(Consola::PRETO);
        cout << " FINAL\n";
    }

    Consola::gotoxy(0, 1);
    for (int i = 0; i < n_carros_2; i++) {
        Consola::gotoxy(camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getCorrida()[i]->getPosicaoCorrida(), i + 1);
        cout << camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getCorrida()[i]->getID() << endl;
        Consola::setBackgroundColor(Consola::PRETO);
    }
    Consola::gotoxy(0, n_carros_2 + 2);

    camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->mostraClassificacaoCorrida();
    for (int i = 0; i < camp->getConcorrentes().size(); i++) {
        if (camp->getConcorrentes().at(i)->getVolta()*100 + camp->getConcorrentes()[i]->getPosicao() >= camp->getAutodromoCampeonato().at(camp->getActualAutodromo())->getComprimento()) {
            return true;
        }
    }
    return false;
}

void TextUI::mostra_janela_inicial() {
    Consola::clrscr();
    cout << "------------------------ Simulador de Corridas -----------------------------------------" << endl;

    int n_carros_2 = camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getCorrida().size();

    Consola::gotoxy(0, 1);


    Consola::setScreenSize(40, 120);

    for (int i = 0; i < n_carros_2; i++) {
        cout << camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getCorrida()[i]->getID();
        Consola::setBackgroundColor(Consola::CINZENTO + i);

        for (int j = 0; j < 100; j++) {
            cout << " ";
        }
        Consola::setBackgroundColor(Consola::PRETO);
        cout << " FINAL\n";
    }

    cout << "\n\t Pilotos Concorrentes: " << endl;

    for (int i = 0; i < camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao().size(); i++)
        cout << "Nome: " << camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[i]->getPiloto()->getNome() << endl << "ID: " << camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[i]->getID() << " Marca: " << camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[i]->getMarca() << " Modelo: " << camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[i]->getModelo() << "\n" << endl;

    Consola::setBackgroundColor(Consola::PRETO);
}

void TextUI::imprimeNome() {
    cout << "------------Simulador de Corridas------------" << endl;
}

bool TextUI::leComandos(string comando) {
    vector<string> stringSeparada;
    string aux;
    stringSeparada = separaComando(comando, ' ');
    if (stringSeparada.size() != 0) {
        if (stringSeparada[0] == "sair") {
            return false;
        }
        if (stringSeparada[0] == "campeonato") {
            Consola::clrscr();
            if (stringSeparada.size() > 1) {
                int flag = 0;
                for (int i = 1; i < stringSeparada.size(); i++) {
                    for (int j = 0; j < camp->getTodasAsPistas().size(); j++) {
                        if (camp->getTodasAsPistas()[j].getNome().compare(stringSeparada[i]) == 0) { // algum tipo de erro aqui
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0) {
                        Consola::gotoxy(10, 10);
                        imprimeErro(" ");
                        cout << "Este autodromo '" << stringSeparada[i] << "' nao existe!\n";
                        Consola::getch();
                        return true;

                    }
                    flag = 0;
                }
                if (dgv[iter].getVectorCarros().size() != 0) {
                    if (dgv[iter].getVectorPilotos().size() != 0) {
                        if (camp->getTodasAsPistas().size() != 0) {
                            return comandoCampeonato(stringSeparada);
                        }
                    }
                }
                if (dgv[iter].getVectorCarros().size() == 0) {
                    Consola::gotoxy(10, 10);
                    imprimeErro("Nao existe carros\n");
                }
                if (dgv[iter].getVectorPilotos().size() == 0) {
                    imprimeErro("Nao existe pilotos\n");
                }
                if (camp->getTodasAsPistas().size() == 0) {
                    imprimeErro("Nao existem autodromos\n");
                }
            } else {
                imprimeErro("Numero de argumentos errado! Ex: campeonato <autodromo1> <autodromo2>...\n");
            }
        } else if (stringSeparada[0] == "cria") {
            if (stringSeparada[1] == "c") {
                if (stringSeparada.size() == 6) {
                    if (atoi(stringSeparada[3].c_str()) > atoi(stringSeparada[4].c_str())) {
                        imprimeErro("Carro nao foi criado, porque capacidade inicial > capacidade maxima!\n");
                    } else {
                        dgv[iter].addCarro(Carro(atoi(stringSeparada[2].c_str()), atoi(stringSeparada[3].c_str()), atoi(stringSeparada[4].c_str()), stringSeparada[5]));
                        imprimeLog("Carro criado com sucesso!\n");
                    }
                } else if (stringSeparada.size() == 7) {
                    if (atoi(stringSeparada[3].c_str()) > atoi(stringSeparada[4].c_str())) {
                        imprimeErro("Carro nao foi criado, porque capacidade inicial > capacidade maxima!\n");
                    } else {
                        dgv[iter].addCarro(Carro(atoi(stringSeparada[2].c_str()), atoi(stringSeparada[3].c_str()), atoi(stringSeparada[4].c_str()), stringSeparada[5], stringSeparada[6]));
                        imprimeLog("Carro criado com sucesso!\n");
                    }
                } else {
                    imprimeErro("Comando mal implementado -->EX: cria c <velocidade> <cap_inicial> <cap_max> <marca> <modelo>\n");
                }
            } else if (stringSeparada[1] == "p") {
                if (stringSeparada.size() == 4) {
                    if (stringSeparada[2] == "crazy" || stringSeparada[2] == "surpresa" || stringSeparada[2] == "rapido") {
                        aux = juntarNome(stringSeparada, 3);
                        dgv[iter].addPiloto(stringSeparada[2], aux);
                        imprimeLog("Piloto criado com sucesso!\n");
                    } else
                        imprimeErro("Comando mal implementado -->EX: cria p tipo nome1\n");
                } else
                    imprimeErro("Comando mal implementado -->EX: cria p tipo nome2\n");
            } else if (stringSeparada[1] == "a") {
                if (stringSeparada.size() == 5) {
                    camp->addAutodromo(atoi(stringSeparada[2].c_str()), atoi(stringSeparada[3].c_str()), stringSeparada[4]);
                    imprimeLog("Autodromo criado com sucesso!\n");
                } else {
                    imprimeErro("Comando mal implementado -->EX: cria a <pistas> <comprimento> <nome>\n");
                }
            }
        } else if (stringSeparada[0] == "carregap") {
            if (stringSeparada.size() == 2) {
                if (!comandoLoadPilotos(stringSeparada[1])) {
                    imprimeErro(" ");
                    cout << "Ficheiro " << stringSeparada[1] << " nao encontrado!\n";
                } else {
                    imprimeLog("Ficheiro carregado com sucesso!\n");
                }
            } else {
                imprimeErro("Numero de argumentos errado!\n");
            }
        } else if (stringSeparada[0] == "carregac") {
            if (stringSeparada.size() == 2) {
                if (!comandoLoadCarros(stringSeparada[1])) {
                    imprimeErro(" ");
                    cout << "Ficheiro " << stringSeparada[1] << " nao encontrado!\n";
                } else {
                    imprimeLog("Ficheiro carregado com sucesso!\n");
                }
            } else {
                imprimeErro("Numero de argumentos errado!\n");
            }
        } else if (stringSeparada[0] == "carregaa") {
            if (stringSeparada.size() == 2) {
                if (!comandoLoadAutodromos(stringSeparada[1])) {
                    imprimeErro(" ");
                    cout << "Ficheiro " << stringSeparada[1] << " nao encontrado!\n";
                } else {
                    imprimeLog("Ficheiro carregado com sucesso!\n");
                }
            } else {
                imprimeErro("Numero de argumentos errado!\n");
            }
        } else if (stringSeparada[0] == "apaga") {
            if (stringSeparada.size() == 3) {
                if (stringSeparada[1] == "c") {
                    if (stringSeparada[2].size() == 1) {
                        if (comandoRemoveCarro(stringSeparada[2])) {
                            imprimeLog(" ");
                            cout << "Carro " << stringSeparada[2] << " eliminado!\n";
                        } else {
                            imprimeErro("Carro nao existe!\n");
                        }
                    } else
                        imprimeErro("Id demasiado grande!\n");

                } else if (stringSeparada[1] == "p") {
                    aux = juntarNome(stringSeparada, 2);
                    if (comandoRemovePiloto(aux)) {
                        imprimeLog(" ");
                        cout << "Piloto " << aux << " eliminado!\n";
                    } else {
                        imprimeErro(" ");
                        cout << "Piloto " << aux << " nao existe!\n";
                    }
                } else if (stringSeparada[1] == "a") {
                    if (comandoRemoveAutodromo(stringSeparada[2])) {
                        imprimeLog(" ");
                        cout << "Autodromo " << stringSeparada[2] << " eliminado!\n";
                    } else {
                        imprimeErro(" ");
                        cout << "Autodromo " << stringSeparada[2] << " nao existe!\n";
                    }
                } else
                    imprimeErro("Comando mal escrito!\n");

            } else
                imprimeErro("Numero de argumentos invalido -> apaga <letratipo> identificador");

        } else if (stringSeparada[0] == "entranocarro") {
            if (stringSeparada.size() > 2) {
                int aux;
                aux = comandoEntraNoCarro(stringSeparada);
                switch (aux) {
                    case -1:
                        imprimeErro("Piloto nao existe!\n");
                        break;
                    case 0:
                        imprimeErro("Carro nao existe!\n");
                        break;
                    case 1:
                        imprimeLog("Piloto entrou no carro com sucesso!\n");
                        break;
                    case 2:
                        imprimeErro("Piloto ja se encontra noutro carro!\n");
                        break;
                    case 3:
                        imprimeErro("Carro ja se encontra ocupado!\n");
                        break;
                }
            } else {
                imprimeErro("Comando mal escrito! entranocarro <idCarro> <nomePiloto>\n");

            }
        } else if (stringSeparada[0] == "saidocarro") {
            if (stringSeparada.size() == 2) {
                if (dgv[iter].encontraCarro(stringSeparada[1][0])) {
                    if (dgv[iter].buscaCarro(stringSeparada[1][0])->getPiloto() != NULL) {
                        dgv[iter].buscaCarro(stringSeparada[1][0])->getPiloto()->setCarro(false);
                        dgv[iter].buscaCarro(stringSeparada[1][0])->setPiloto(NULL);
                        dgv[iter].buscaCarro(stringSeparada[1][0])->setOcupado(false);
                        imprimeLog("Piloto saio do carro com sucesso!\n");
                    } else {
                        imprimeErro("Carro encontra ja se sem piloto!\n");
                    }
                } else {
                    imprimeErro("Carro nao existe!\n");
                }
            } else
                imprimeErro("Numero de argumentos inválido -> saidocarro <letraCarro>");
        } else if (stringSeparada[0] == "lista") {
            ecraMenu();
            Consola::gotoxy(10, 4);
            Consola::setTextColor(Consola::AMARELO_CLARO);
            Consola::setBackgroundColor(Consola::VERMELHO);
            cout << "Menu Lista: " << endl;
            resetCores();
            vector<Piloto *> pil = dgv[iter].getVectorPilotos();
            vector<Carro> car = dgv[iter].getVectorCarros();

            // LISTA OS PILOTOS
            Consola::gotoxy(11, 8);
            Consola::setTextColor(Consola::COR_DE_ROSA);
            Consola::setBackgroundColor(Consola::CYAN_CLARO);
            cout << "Pilotos: " << endl;
            resetCores();

            Consola::gotoxy(11, 8);
            Consola::setTextColor(Consola::COR_DE_ROSA);
            Consola::setBackgroundColor(Consola::CYAN_CLARO);
            cout << "Pilotos: " << endl;
            resetCores();

            // LISTA Pilotos
            int auxLinhas = 9;
            for (auto i = pil.begin(); i != pil.end(); ++i) {
                Consola::gotoxy(12, auxLinhas++);
                if (auxLinhas % 2 == 0)
                    Consola::setBackgroundColor(Consola::CINZENTO);
                else
                    Consola::setBackgroundColor(Consola::AZUL);
                cout << (*i)->getAsString();
            }

            //LISTA OS CARROS
            auxLinhas++;
            Consola::gotoxy(11, auxLinhas++);
            Consola::setTextColor(Consola::COR_DE_ROSA);
            Consola::setBackgroundColor(Consola::CYAN_CLARO);
            cout << "Carros: " << endl;
            resetCores();
            for (auto i = car.begin(); i != car.end(); ++i) {
                if (auxLinhas % 2 == 0)
                    Consola::setBackgroundColor(Consola::CINZENTO);
                else
                    Consola::setBackgroundColor(Consola::AZUL);
                Consola::gotoxy(12, auxLinhas++);
                cout << (*i).getAsString();

            }

            //LISTA OS AUTODROMOS
            vector <Autodromo> listaAutodromos = camp->getTodasAsPistas();
            auxLinhas++;
            Consola::gotoxy(11, auxLinhas++);
            Consola::setTextColor(Consola::COR_DE_ROSA);
            Consola::setBackgroundColor(Consola::CYAN_CLARO);
            cout << "Autodromos: " << endl;
            resetCores();

            for (auto i = listaAutodromos.begin(); i != listaAutodromos.end(); ++i) {
                if (auxLinhas % 2 == 0)
                    Consola::setBackgroundColor(Consola::CINZENTO);
                else
                    Consola::setBackgroundColor(Consola::AZUL);
                Consola::gotoxy(12, auxLinhas++);
                cout << (*i).getAsString();
            }
            resetCores();
            Consola::gotoxy(11, auxLinhas + 2);
            Consola::setTextColor(Consola::CINZENTO);
            cout << "Carregue Enter para sair!";
            Consola::gotoxy(11, auxLinhas + 3);
            resetCores();
        } else if (stringSeparada[0] == "savedgv") {
            if (stringSeparada.size() == 2) {
                if (comandoSaveDGV(stringSeparada[1])) {
                    dgv.push_back(DGV(dgv[iter]));
                    iter = dgv.size() - 1;
                    dgv[iter].setNome("");
                    imprimeLog("DGV guardado!\n");
                } else {
                    imprimeErro("Ocorreu um erro a guardar o DGV!\n");
                }
            } else {
                imprimeErro("Numero de argumentos inválido -> savedgv <nome>");
            }
        } else if (stringSeparada[0] == "loaddgv") {
            if (stringSeparada.size() == 2) {
                if (comandoLoadDGV(stringSeparada[1])) {
                    imprimeLog("Load do DGV ocorreu com sucesso!\n");
                } else {
                    imprimeErro("Ocorreu um erro a fazer load do DGV! Confirme o nome do seu load\n");
                }
            } else {
                imprimeErro("Numero de argumentos inválido -> loaddgv <nome>");
            }
        } else if (stringSeparada[0] == "deldgv") {
            if (stringSeparada.size() == 2) {
                if (comandoDelDGV(stringSeparada[1])) {
                    imprimeLog("DGV foi removido com sucesso!\n");
                } else {
                    imprimeErro("Ocorreu um erro a fazer rempve do DGV! Confirme o nome que quer remover\n");
                }
            } else {
                imprimeErro("Numero de argumentos inválido -> deldgv <nome>");
            }
        } else if (stringSeparada[0] == "a") {
            for (int i = 0; i < dgv.size(); i++) {
                cout << dgv[i].getNome() << endl;
            }
        } else {
            imprimeErro("Este comando nao existe!\n");
        }
    } else {
        imprimeErro("Comando nao recebeu parametros\n");
    }
    Consola::getch();
}

bool TextUI::leComandosModo2(string comando) {
    vector<string> stringSeparada;
    stringSeparada = separaComando(comando, ' ');
    if (flag == 0) {
        if (stringSeparada.size() != 0) {
            if (stringSeparada[0] == "corrida") {
                if (stringSeparada.size() == 1) {
                    iniciaModo2();
                    flag = 1;
                } else {
                    imprimeLog("Comando mal escrito! corrida\n");
                }
            } else {
                imprimeLog("Escreva o comando 'corrida' para inicia a prox corrida!\n");
            }
        } else {
            imprimeErro("Comando nao recebeu parametros\n");
        }
    } else {
        if (stringSeparada.size() != 0) {
            if (stringSeparada[0] == "sair") {
                return false;
            } else if (stringSeparada[0] == "passatempo") {
                if (stringSeparada.size() == 2) {
                    //ESTE COMANDO AUMENTA A POSICAO CONSOANTE A VELOCIDADE/TRAVAGEM
                    //para esta 1a meta foi deixado em comentario

                    comandoPassaTempo(atoi(stringSeparada[1].c_str()));
                    if (mostra_janela_passatempo(atoi(stringSeparada[1].c_str()))) {
                        imprimeLog("CORRIDA ACABOU!\n");
                        flag = 0;
                        //classificacao final
                        int pontos = 10;
                        cout << "----------Classificacao final da corrida---------\n";
                        for (int i = 0; i < camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao().size(); i++) {
                            camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[i]->getPiloto()->setPontos(pontos);
                            cout << i + 1 << "- " << camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[i]->getID() << "  //   ->"
                                    << camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[i]->getPiloto()->getNome() << " --------- " << pontos << "pts\n";
                            pontos -= 2;
                            if (pontos <= 0) {
                                pontos = 0;
                            }
                        }


                        Carro * p;
                        vector <Carro * > cla = camp->getConcorrentes();
                        cout << "\n----------Classificacao actual do campeonato---------\n";
                        for (int i = 0; i < cla.size() - 1; i++) {
                            if (cla[i]->getPiloto()->getPontos() < cla[i + 1]->getPiloto()->getPontos()) {
                                p = cla[i + 1];
                                cla[i + 1] = cla[i];
                                cla[i] = p;
                                i = -1;
                            }
                        }
                        for (int i = 0; i < cla.size(); i++) {
                            cout << i + 1 << " - " << cla[i]->getPiloto()->getNome() << "   ------------->"
                                    << cla[i]->getPiloto()->getPontos() << "pts\n";
                        }
                        //classificacao e atribuicao de pontos para campeonato
                        if (camp->getActualAutodromo() == camp->getAutodromoCampeonato().size() - 1) {
                            imprimeLog("Campeonato acabou !\n");
                            return false;
                        }
                        camp->setActualAutodromo(camp->getActualAutodromo() + 1);
                    }
                } else {
                    imprimeErro("Comando mal escrito! passatempo <int>\n");
                }
            } else if (stringSeparada[0] == "listacarros") {
                if (stringSeparada.size() == 1) {
                    comandoListaCarros();
                } else {
                    imprimeErro("Comando mal escrito! listacarros\n");
                }
            } else if (stringSeparada[0] == "carregabat") {
                if (stringSeparada.size() == 3) {
                    int op = comandoCarregaBat(stringSeparada);
                    switch (op) {
                        case 0:
                            imprimeErro("Comando mal escrito! ID do carro tem apenas um caracter\n");
                            break;
                        case 1:
                            imprimeLog("O carro ");
                            cout << stringSeparada[1] << " encontra se com a bateria no maximo!\n";
                            break;
                        case 2:
                            imprimeLog("O carro ");
                            cout << stringSeparada[1] << " foi carregado!\n";
                            break;
                        case 3:
                            imprimeErro("O carro ");
                            cout << stringSeparada[1] << " nao se encontra na corrida!\n";
                            break;
                    }
                } else {
                    imprimeErro("Comando mal escrito! carregabat <letraCarro> <Q mAh>\n");
                }
            } else if (stringSeparada[0] == "carregatudo") {
                if (stringSeparada.size() == 1) {
                    comandoCarregaTudo();
                    cout << "Todos os carros foram carregados com sucesso\n";
                } else {
                    imprimeErro("Comando mal escrito! carregatudo\n");
                }
            } else if (stringSeparada[0] == "acidente") {
                if (stringSeparada.size() == 2) {
                    if (stringSeparada[1].size() == 1) {
                        if (comandoAcidente(stringSeparada[1][0])) {
                            imprimeLog("Carro teve um acidente!\n");
                        } else {
                            imprimeErro("Carro nao existe!\n");
                        }
                    } else {
                        imprimeErro("Carro nao existe!\n");
                    }
                } else {
                    imprimeErro("Comando mal escrito! acidente <letraCarro>\n");
                }
            } else if (stringSeparada[0] == "stop") {
                int flag = 0;
                if (stringSeparada.size() == 2) {
                    for (int i = 0; i < camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao().size(); i++) {
                        if (camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[i]->getPiloto()->getNome().compare(stringSeparada[1])) {
                            camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[i]->setVelocidade(0);
                            flag = 1;
                            imprimeLog("Carro foi parado com sucesso!\n");
                            //cout << " " << camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[i]->getVelocidade() << endl;
                            break;
                        }
                    }
                    if (flag == 0) {
                        imprimeErro("O piloto nao existe!\n");
                    }
                } else {
                    imprimeErro("Comando mal escrito! stop <nomePiloto>\n");
                }
            } else if (stringSeparada[0] == "destroi") {
                if (stringSeparada.size() == 2) {
                    if (stringSeparada[1].size() == 1) {
                        if (dgv[iter].encontraCarro(stringSeparada[1][0])) {
                            comandoDestroi(dgv[iter].buscaCarro(stringSeparada[1][0]));
                            imprimeLog("Carro foi destruido com sucesso!\n");
                        } else {
                            imprimeErro("Carro nao existe!\n");
                        }
                    } else {
                        imprimeErro("Carro nao existe!\n");
                    }
                } else {
                    imprimeErro("Comando mal escrito! destroi <letraCarro>\n");
                }
            } else if (stringSeparada[0] == "log") {
                if (stringSeparada.size() == 1) {

                } else {
                    imprimeErro("Comando mal escrito! log\n");
                }
            } else {
                imprimeErro("Este comando nao existe!\n");
            }
        } else {
            imprimeErro("Comando nao recebeu parametros\n");
        }
    }
}

bool TextUI::comandoCampeonato(vector<string> comando) {
    for (int i = 0; i < dgv[iter].getVectorCarros().size(); i++) { //Ver se existem pilotos dentro dos carros
        if (dgv[iter].getVectorCarros()[i].getPiloto() != NULL) {
            camp->addConcorrentes(dgv[iter].getVectorCarros()[i].getVelociadeMax(), dgv[iter].getVectorCarros()[i].getCapInicial(), dgv[iter].getVectorCarros()[i].getCapMax(),
                    dgv[iter].getVectorCarros()[i].getMarca(), dgv[iter].getVectorCarros()[i].getID(), dgv[iter].getVectorCarros()[i].getPiloto(), dgv[iter].getVectorCarros()[i].getModelo());
        }
    }
    if (camp->getConcorrentes().size() > 1) {
        for (int i = 1; i < comando.size(); i++) {
            if (camp->getPista(comando[i]) != NULL) {
                camp->addAutodromoParaCampeonato(camp->getPista(comando[i]));
            }
        }
        return false;
    } else {
        cout << "Nao existem pilotos para conduzir os carros!\n";
        cout << "Introduza alguns dos pilotos nos carros existentes!\n";
        return true;
    }

}

int TextUI::comandoEntraNoCarro(vector<string> comando) {
    string aux;
    Carro * c;
    if (dgv[iter].encontraCarro(comando[1][0])) {
        if (!dgv[iter].buscaCarro(comando[1][0])->getOcupado()) {
            aux = juntarNome(comando, 2);
            if (dgv[iter].encontraPiloto(aux)) {
                if (!dgv[iter].buscaPiloto(aux)->getCarro()) {
                    dgv[iter].buscaCarro(comando[1][0])->setPiloto(dgv[iter].buscaPiloto(aux));
                    dgv[iter].buscaPiloto(aux)->setCarro(true);
                    dgv[iter].buscaCarro(comando[1][0])->setOcupado(true);
                } else {
                    return 2;
                }

            } else {
                return -1;
            }
        } else {
            return 3;
        }
    } else {
        return 0;
    }
    return 1;
}

bool TextUI::comandoRemoveCarro(string id) {
    if (!dgv[iter].removeCarro(id[0])) {
        return false;
    }
    return true;
}

bool TextUI::comandoRemovePiloto(string nome) {
    Carro * c = dgv[iter].verSePilotoEstaAoVolante(nome);
    if (c != NULL) {
        c->setPiloto(NULL);
        c->setOcupado(false);
    }
    if (!dgv[iter].removePiloto(nome)) {
        return false;
    }
    return true;
}

bool TextUI::comandoRemoveAutodromo(string nome) {
    if (!camp->removeAutodromo(nome)) {
        return false;
    }
    return true;
}

bool TextUI::comandoLoadPilotos(string ficheiro) {
    ifstream dados(ficheiro);
    string linha;
    string aux;
    vector<string> stringSeparada;
    if (!dados.is_open()) {
        return false;
    }
    while (!dados.eof()) {
        getline(dados, linha);
        stringSeparada = separaComando(linha, ' ');
        if (stringSeparada.size() > 2) {
            aux = juntarNome(stringSeparada, 1);
            dgv[iter].addPiloto(stringSeparada[0], this->toLower(aux));
        } else if (stringSeparada.size() == 2) {
            dgv[iter].addPiloto(stringSeparada[0], this->toLower(stringSeparada[1]));
        }
    }
    dados.close();
    return true;
}

bool TextUI::comandoLoadCarros(string ficheiro) {
    ifstream dados(ficheiro);
    string linha;
    vector<string> stringSeparada;
    if (!dados.is_open()) {
        return false;
    }
    while (!dados.eof()) {
        getline(dados, linha);
        stringSeparada = separaComando(linha, ' ');
        dgv[iter].addCarro(Carro(atoi(stringSeparada[0].c_str()), atoi(stringSeparada[1].c_str()), atoi(stringSeparada[2].c_str()), stringSeparada[3], stringSeparada[4]));
    }
    dados.close();

    return true;
}

bool TextUI::comandoLoadAutodromos(string ficheiro) {
    ifstream dados(ficheiro);
    string linha;
    vector<string> stringSeparada;
    if (!dados.is_open()) {
        return false;
    }
    while (!dados.eof()) {
        getline(dados, linha);
        stringSeparada = separaComando(linha, ' ');
        camp->addAutodromo(atoi(stringSeparada[0].c_str()), atoi(stringSeparada[1].c_str()), this->toLower(stringSeparada[2]));
    }
    dados.close();

    return true;
}

bool TextUI::comandoSaveDGV(string nome) {
    if (dgv[iter].getNome() != "") {
        for (int i = 0; i < dgv.size(); i++) {
            if (dgv[i].getNome() == toLower(nome)) {
                return false;
            }
        }
    } else {
        dgv[iter].setNome(toLower(nome));
    }
    return true;
}

bool TextUI::comandoLoadDGV(string nome) {
    for (int i = 0; i < dgv.size(); i++) {
        if (dgv[i].getNome().compare(toLower(nome)) == 0) {
            iter = i;
            return true;
        }
    }
    return false;
}

bool TextUI::comandoDelDGV(string nome) {
    for (int i = 0; i < dgv.size(); i++) {
        if (dgv[i].getNome().compare(toLower(nome)) == 0) {
            dgv.erase(dgv.begin() + i);
            return true;
        }
    }
    return false;
}

bool TextUI::comandoAcidente(char carro) {
    for (int i = 0; i < camp->getConcorrentes().size(); i++) {
        if (camp->getConcorrentes()[i]->getID() == carro) {
            camp->getConcorrentes()[i]->setDanificado(true);
            return true;
        }
    }
    return false;
}

void TextUI::comandoPassaTempo(int passa) {
    vector <Carro*> cl;
    int x, flag = 0;
    for (int i = passa; i > 0; i--) {
        for (int j = 0; j < camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao().size(); j++) {
            cl.push_back(camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]);
        }
        camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->passaUmSegundo();
        // Ver como se algum carro ficou danificado ou sinal de emergencia activado
        for (int j = 0; j < camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao().size(); j++) {
            if (camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getCapActual() <= 0) {
                camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->setCapActual(0);
                camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->setVelocidade(camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getVelocidade() - 1);
                camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getPiloto()->setAcelera(false);
            } else {
                if (camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getPiloto()->getTipo().compare("crazy") == 0) {
                    for (int x = 0; x < cl.size(); x++) {
                        if (cl[x]->getID() == camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getID()) {
                            break;
                        }
                    }

                    //comeca so a correr num x tempo
                    if (camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getPiloto()->caracteristicaPiloto(camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getSegundoActual()) ==
                            rand() % 5 + 1) {
                        camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getPiloto()->setAcelera(true);
                        camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getPiloto()->setTrava(false);
                    }
                    if (camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getPosicaoCorrida() ==
                            camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao().size()) {
                        camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getPiloto()->setAcelera(false);
                        camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getPiloto()->setTrava(true);
                    }

                    if (camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getCapActual() == 0) {
                        camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->setSinalEmergencia(true);
                    }

                    if (rand() % 100 + 1 < 5) {
                        camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j + 1]->setDanificado(true);

                    }
                } else if (camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getPiloto()->getTipo().compare("rapido") == 0) {
                    if (camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getCapActual() > camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getCapMax() / 2) {
                        camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getPiloto()->setAcelera(true);
                        count = 0;
                    } else {
                        if (count == 3) {
                            camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getPiloto()->setAcelera(true);
                            count = 0;
                        } else {
                            camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getPiloto()->setAcelera(false);
                            camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getPiloto()->setTrava(false);
                            count++;
                        }
                    }
                    if (camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getPiloto()->caracteristicaPiloto(camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getSegundoActual()) % 10 == 0) {
                        camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->setSinalEmergencia(true);
                    }
                } else if (camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getPiloto()->getTipo().compare("surpresa") == 0) {
                    if (camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getPosicaoCorrida() == 1) {
                        camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->setVelocidade(1);
                        camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getPiloto()->setAcelera(true);
                        camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getPiloto()->setTrava(false);
                    }
                    if (camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getVelocidade() < camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getVelociadeMax() % 2 == 0 &&
                            camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getPosicaoCorrida() > 3) {
                        camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->setVelocidade(2);
                        camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getPiloto()->setAcelera(true);
                        camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getPiloto()->setTrava(false);
                    } else {
                        camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->setVelocidade(1);
                        camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getPiloto()->setAcelera(false);
                        camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getPiloto()->setTrava(false);
                    }
                }
            }
            if (camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getSinalEmergencia()) {
                camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->sinalEmergenciaActivado(camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]);
            }
            if (camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getDanificado()) {
                camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->carroDanificado(camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]);
            }
            if (camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getClassificacao()[j]->getPosicao() >= camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getComprimento()) {
                flag = 1;
            }
        }
        if (flag == 1) {
            break;
        }
    }
    cl.erase(cl.begin(), cl.end());
}

void TextUI::comandoListaCarros() {
    cout << "----Em Corrida----\n";
    for (int i = 0; i < camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getCorrida().size(); i++) {
        camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getCorrida()[i]->mostraCarroEmCorrida();
    }
    cout << "----Na Garagem----\n";
    for (int i = 0; i < camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getGaragem().size(); i++) {
        camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getGaragem()[i]->mostraCarroEmCorrida();
    }
}

bool TextUI::comandoDestroi(Carro * carro) {
    camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->destroiCarro(carro);
    camp->destroiCarro(carro);
    dgv[iter].removeCarro(carro->getID());
    return true;
}

int TextUI::comandoCarregaBat(vector <string> comando) {
    if (comando[1].size() == 1) {
        for (int i = 0; i < camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getCorrida().size(); i++) {
            if (camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getCorrida()[i]->getID() == comando[1][0]) {
                camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getCorrida()[i]->setCapActual(camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getCorrida()[i]->getCapActual() + atoi(comando[2].c_str()));
                if (camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getCorrida()[i]->getCapActual() > camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getCorrida()[i]->getCapMax()) {
                    camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getCorrida()[i]->setCapActual(camp->getAutodromoCampeonato()[camp->getActualAutodromo()]->getCorrida()[i]->getCapMax());
                    return 1;
                }
                return 2;
            }
        }
        return 3;
    } else {
        return 0;
    }
}

void TextUI::comandoCarregaTudo() {
    for (int i = 0; i < camp->getConcorrentes().size(); i++) {
        camp->getConcorrentes()[i]->setCapActual(camp->getConcorrentes()[i]->getCapMax());
    }
}

vector<string> TextUI::separaComando(string comando, char separador) {
    vector<string> stringSeparada;
    stringstream ss;
    ss.str(comando);
    string token;
    while (getline(ss, token, separador)) {
        if (!token.empty()) {
            stringSeparada.push_back(token);
        }
    }
    return stringSeparada;
}

string TextUI::juntarNome(vector<string> nome, int num) {
    for (int i = num; i < nome.size() - 1; i++) {

        nome[num] += ' ';
        nome[num] += nome[i + 1];
    }
    return nome[num];
}

string TextUI::toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

string TextUI::toUpper(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

int TextUI::count = 0;

int TextUI::flag = 0;

void TextUI::imprimeErro(string msg) {
    Consola::setTextColor(Consola::VERMELHO_CLARO);
    cout << "[ERRO] ";
    Consola::setTextColor(Consola::BRANCO_CLARO);
    cout << msg;
}

void TextUI::imprimeLog(string msg) {
    Consola::setTextColor(Consola::VERDE_CLARO);
    cout << "[LOG] ";
    Consola::setTextColor(Consola::BRANCO_CLARO);
    cout << msg;
}

TextUI::~TextUI() {
    delete camp;
}