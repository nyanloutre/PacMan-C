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
#include "setwindow.h"


int main()
{
    //Variables
    char terrain [20][38];
    coordonees PacMan;
    coordonees fantomeA;
    coordonees fantomeB;
    coordonees fantomeC;
    coordonees fantomeD;

    SetWindow(39,25);

    srand(time(NULL));

    initialisation(terrain, &PacMan, &fantomeA, &fantomeB, &fantomeC, &fantomeD);

    renduarene(terrain);

    affichage(terrain, 0);

    deplacements(terrain, &PacMan, &fantomeA, &fantomeB, &fantomeC, &fantomeD);

    return 0;
}
