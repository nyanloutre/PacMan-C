#include <stdio.h>
#include <stdlib.h>

void lectureScore(char *pseudo[], int score[])
{
    FILE* sauv = NULL;
    sauv = fopen("score.txt", "r");

    char *lecture;
    int i=0;

    if (sauv != NULL)
    {
        //execution du code dans le cas o� il n'y a pas d'erreur
        fseek(sauv, 0, SEEK_SET);
        while (!feof(sauv))
        {
            fgets(lecture, 4, sauv);
            i++;
            pseudo[i]=lecture;
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
