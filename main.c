#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "generation.h"
#include "deplacement.h"
#include "affichage.h"
#include "structures.h"
#include "deplacementfantomes.h"
#include "betterlook.h"


int main()
{
    //Variables
    char terrain [20][38];
    coordonees PacMan;
    coordonees fantomeA;
    coordonees fantomeB;
    coordonees fantomeC;
    coordonees fantomeD;

    SMALL_RECT WinRect = {0, 0, 37, 24}; //On définit un rectangle pour la fenêtre
    SMALL_RECT* WinSize = &WinRect; //Il est nécessaire de créer un pointeur pour cette fonction
    /*COORD taille;
    CONSOLE_FONT_INFO font;*/

    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), 1, WinSize); //On définit la taille de la console suivant le rectangle
    /*taille.X = 20;
    taille.Y = 20;
    font.dwFontSize = taille;
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &font);*/


    srand(time(NULL));

    initialisation(terrain, &PacMan, &fantomeA, &fantomeB, &fantomeC, &fantomeD);

    renduarene(terrain);

    affichage(terrain, 0);

    deplacements(terrain, &PacMan, &fantomeA, &fantomeB, &fantomeC, &fantomeD);

    return 0;
}
