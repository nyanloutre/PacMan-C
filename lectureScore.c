#include <stdio.h>
#include <stdlib.h>

void lectureScore(char pseudo[100][4], int score[])
{
    FILE* sauv = NULL;
    sauv = fopen("score.txt", "r");

    char lecture[4];
    int i=0;

    if (sauv != NULL)
    {
        //execution du code dans le cas où il n'y a pas d'erreur
        fseek(sauv, 0, SEEK_SET);
        while (!feof(sauv))
        {
            fgets(lecture, 4, sauv);
            strcpy(pseudo[i], lecture); //Il faut utiliser ça pour copier des chaines de caractère
            //pseudo[i][0]=lecture;

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
