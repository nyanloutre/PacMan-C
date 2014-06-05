#include <stdlib.h>
#include <stdio.h>

#include "affichageBestScore.h"


void triScore(char pseudo[100][4], int score[100], int maxi)
{
    int i, j, new_score;
    char new_pseudo[4], temp_pseudo[4];
    for (i = 1; i < maxi; i++)      // tri score du plus petit au plus grand
    {
        new_score = score[i];
        strcpy(new_pseudo, pseudo[i]);
        j=i;
        while (j > 0 && score[j-1] > new_score)
        {
            score[j] = score[j-1];
            strcpy(pseudo[j], pseudo[j-1]);
            j--;
        }
        score[j] = new_score;
        strcpy(pseudo[j], new_pseudo);
    }
    printf("Le meilleur score est %d detenu par %s\n", score[maxi-1], pseudo[maxi-1]);


    //Affichage tableau des scores
    affichageBestScore(pseudo, score, maxi);

    //Suppression lorsque fichier trop gros
    if (maxi>50)
    {
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
}
