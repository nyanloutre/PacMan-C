#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "inscriptionScore.h"
#include "triScore.h"
#include "lectureScore.h"



void fscore(int scorePlayer)
{
    int score[100]={0}, maxi, i;
    char name[12];
    char pseudo[100][4];

    printw("Votre Pseudo (3 caracteres): ");
    //Saisie du pseudo
    do
    {
        gets(name);

    }while (strlen(name)!=3);

    //Passage en majuscule
    for (i=0 ; i<4 ; i++)
    {
        name[i]=toupper(name[i]);
    }


    printw("\n\nVotre score est: %d\n\n", scorePlayer);
    inscriptionScore(name, scorePlayer);    //Inscription du score dans le fichier .txt
    maxi = lectureScore(pseudo, score);     //
    triScore(pseudo, score, maxi);
}
