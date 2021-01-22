#include <cstdlib>
#include <string>
#include <iostream>
#include "TextUI.h"
#include "Piloto.h"
#include "CrazyPiloto.h"
#include <vector>
#include "TextUI.h"

using namespace std;

int main(int argc, char** argv) {
    TextUI* textUi = new TextUI();
    textUi->start();
    delete textUi;

    return 0;
}