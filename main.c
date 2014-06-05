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
#include "menu.h"
#include "lectureScore.h"
#include "triScore.h"

int main()
{
    //Initialisation des variables
    int mode, maxi;
    char terrain [20][38];
    char pseudo[100][4];  //Les deux tableaux suivants servent à l'affichage des meilleurs scores
    int score[100];

    coordonees PacMan;
    coordonees fantomeA;
    coordonees fantomeB;
    coordonees fantomeC;
    coordonees fantomeD;

    SetWindow(70,26); //On redimentionne la fenêtre (c'est le seul réglage faisable automatiquement)

    srand(time(NULL)); //On initialise les nombres aléatoires

    initialisation(terrain, &PacMan, &fantomeA, &fantomeB, &fantomeC, &fantomeD); //On génère l'arène

    renduarene(terrain); //On effectue un rendu sur l'arène précédement générée afin d'avoir un résultat plus joli

    do
    {
        menu(&mode);
        switch(mode)
        {
        case 1 :
            affichage(terrain, 0, 0, 0); //On affiche une première fois le terrain
            deplacements(terrain, &PacMan, &fantomeA, &fantomeB, &fantomeC, &fantomeD); //On lance la gestion des déplacements
            break;

        case 2:
            maxi = lectureScore(pseudo, score);
            triScore(pseudo, score, maxi);
            break;

        default:
            break;

        }
    }while(mode>0 && mode<3);

    return 0;
}
