#include <stdlib.h>
#include <stdio.h>

void nettoyageScore(char pseudo[100][4], int score[100], int maxi)
{
    int i=0;
    FILE* fichier = NULL;
    fichier = fopen("score.txt","w+");

    if (fichier !=NULL)
    {
        for (i=maxi-1; i>maxi-11; i--)
        {
            fprintf(fichier, "%s %d\n", pseudo[i], score[i]);
        }
        fclose(fichier);
    }
    else
    {
        printf("Erreur lors de l'ouverture/suppression du contenu du fichier score\n");
    }
}
