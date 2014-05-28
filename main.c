#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#include "initialisation.h"
#include "deplacement.h"
#include "affichage.h"
#include "structures.h"
#include "deplacementfantomes.h"
#include "renduarene.h"
#include "setwindow.h"


int main()
{
    //Initialisation des variables
    char terrain [20][38];
    coordonees PacMan;
    coordonees fantomeA;
    coordonees fantomeB;
    coordonees fantomeC;
    coordonees fantomeD;

    SetWindow(40,25); //On redimentionne la fen�tre (c'est le seul r�glage faisable automatiquement)

    srand(time(NULL)); //On initialise les nombres al�atoires

    initialisation(terrain, &PacMan, &fantomeA, &fantomeB, &fantomeC, &fantomeD); //On g�n�re l'ar�ne

    renduarene(terrain); //On effectue un rendu sur l'ar�ne pr�c�dement g�n�r�e afin d'avoir un r�sultat plus joli

    affichage(terrain, 0, 0, 0); //On affiche une premi�re fois le terrain

    deplacements(terrain, &PacMan, &fantomeA, &fantomeB, &fantomeC, &fantomeD); //On lance la gestion des d�placements

    printf("Appuyez sur une touche pour quitter"); //Message de fin (car lors d'une release le programme ce ferme automatiquement � la fin)
    getch();

    return 0;
}
