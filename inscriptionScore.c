#include <stdio.h>
#include <stdlib.h>

void inscriptionScore(char name[],int score)
{
    FILE* sauv = NULL;
    sauv = fopen("score.txt", "a");
    if (sauv != NULL)
    {
        //execution du code dans le cas où il n'y a pas d'erreur
        printf("%s", name);
        fprintf(sauv, "%s %d\n", name, score);
        fclose(sauv);
    }
    else
    {
        printf("Erreur lors de l'ouverture du fichier pour ecriture");
    }
}
