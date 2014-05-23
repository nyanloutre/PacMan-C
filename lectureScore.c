#include <stdio.h>
#include <stdlib.h>

void lectureScore(char *pseudo[], int score[])
{
    FILE* sauv = NULL;
    sauv = fopen("score.txt", "r");
    if (sauv != NULL)
    {
        //execution du code dans le cas où il n'y a pas d'erreur
        fseek(sauv, 0, SEEK_SET);
        while (fgets(lecture, 3, sauv)!=NULL)
        {
            t_nom[1][i] = lecture;

            fgets(lecture, 3,sauv);
            t_score[i] = atoi(lecture);         //conversion caractère en nombre
            i++;
        }
        fclose(sauv);
    }
    else
    {
        printf("Erreur lors de l'ouverture du fichier pour lecture");
    }
}
