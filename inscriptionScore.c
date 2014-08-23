#include <stdio.h>
#include <stdlib.h>

void inscriptionScore(char name[],int score)
{
    FILE* sauv = NULL;
    sauv = fopen("score.txt", "a");
    if (sauv != NULL)
    {
        //execution du code dans le cas où il n'y a pas d'erreur
        fprintf(sauv, "%s %d\n", name, score);      //ecriture du score dans le fichier
        fclose(sauv);
    }
    else
    {
        printw("Erreur lors de l'ouverture du fichier pour ecriture");
    }
}
