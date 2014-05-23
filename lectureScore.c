#include <stdio.h>
#include <stdlib.h>

void lectureScore(char *pseudo[], int score[])
{
    FILE* sauv = NULL;
    sauv = fopen("score.txt", "");
    if (sauv != NULL)
    {
        //execution du code dans le cas où il n'y a pas d'erreur

        fclose(sauv);
    }
    else
    {
        printf("Erreur lors de l'ouverture du fichier");
    }
}
