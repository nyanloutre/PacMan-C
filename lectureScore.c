#include <stdio.h>
#include <stdlib.h>

void lectureScore(char *pseudo[], int score[])
{
    FILE* sauv = NULL;
    sauv = fopen("score.txt", "r");


    int i=0;

    if (sauv != NULL)
    {
        //execution du code dans le cas où il n'y a pas d'erreur
        fseek(sauv, 0, SEEK_SET);
        while (!feof(sauv))
        {
            printf("%d\t", i);
            fscanf(sauv, "%s %d\n", &pseudo[i], &score[i]);
            i++;
        }

        /*while (fgets(lecture, 3, sauv)!=NULL)
        {
            pseudo[i] = lecture;
            fgets(*lecture, 3,sauv);
            score[i] = atoi(*lecture);         //conversion caractère en nombre
            i++;
        }*/
        fclose(sauv);
    }
    else
    {
        printf("Erreur lors de l'ouverture du fichier pour lecture");
    }
}
