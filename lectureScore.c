#include <stdio.h>
#include <stdlib.h>

void lectureScore(char pseudo[100][4], int score[100])
{
    FILE* sauv = NULL;
    sauv = fopen("score.txt", "r");

    char lecture[4];
    int i=0;

    if (sauv != NULL)
    {
        //execution du code dans le cas o� il n'y a pas d'erreur
        fseek(sauv, 0, SEEK_SET);
        while (!feof(sauv))
        {
            fgets(lecture, 4, sauv);
            strcpy(pseudo[i], lecture); //Il faut utiliser �a pour copier des chaines de caract�re

            fseek(sauv, 1, SEEK_CUR); // On passe l'espace

            fgets(lecture, 4, sauv); //On lit le score
            score[i] = atoi(lecture); //On convertit la lecture en nombre

            i++;
        }

        /*while (fgets(lecture, 3, sauv)!=NULL)
        {
            pseudo[i] = lecture;
            fgets(*lecture, 3,sauv);
            score[i] = atoi(*lecture);         //conversion caract�re en nombre
            i++;
        }*/
        fclose(sauv);
    }
    else
    {
        printf("Erreur lors de l'ouverture du fichier pour lecture");
    }
}
