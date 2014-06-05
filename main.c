#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "initialisation.h"
#include "deplacement.h"
#include "affichage.h"
#include "structures.h"
#include "deplacementfantomes.h"
#include "renduarene.h"
#include "setwindow.h"
#include "menu.h"


int main()
{
    //Initialisation des variables
    char terrain [20][38];
    coordonees PacMan;
    coordonees fantomeA;
    coordonees fantomeB;
    coordonees fantomeC;
    coordonees fantomeD;

    SetWindow(70,26); //On redimentionne la fenêtre (c'est le seul réglage faisable automatiquement)

    srand(time(NULL)); //On initialise les nombres aléatoires

    menu();

    initialisation(terrain, &PacMan, &fantomeA, &fantomeB, &fantomeC, &fantomeD); //On génère l'arène

    renduarene(terrain); //On effectue un rendu sur l'arène précédement générée afin d'avoir un résultat plus joli

    affichage(terrain, 0, 0, 0); //On affiche une première fois le terrain

    deplacements(terrain, &PacMan, &fantomeA, &fantomeB, &fantomeC, &fantomeD); //On lance la gestion des déplacements

    printf("Appuyez sur une touche pour quitter"); //Message de fin (car lors d'une release le programme ce ferme automatiquement à la fin)
    getch();

    return 0;
}
