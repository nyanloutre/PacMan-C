#include <stdio.h>
#include <stdlib.h>

void tableauDesScores(int score)
{
    //
    FILE* sauv;
    char nom[3], t_nom[3][100], t_score[100];
    char lecture;
    int i=0, j=0, place;

    sauv = fopen("score.txt", "r");

    if (sauv == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier pour lecture");
    }
    else
    {
        gets(nom);
        //printf("TEST");
        fseek(sauv, 0, SEEK_SET);
        while (fgets(lecture, 3, sauv)!=NULL)
        {
            t_nom[1][i] = lecture;

            fgets(lecture, 3,sauv);
            t_score[i] = atoi(lecture);         //conversion caractère en nombre
            i++;
        }

        i = 0;
        while(score < t_score[i])
        {
            i++;
        }

        if (i==0)
        {
            printf("Meilleur score a ce jour avec %d points.", score);
        }
        else
        {
            place=i+1;
            printf("Vous etes %d eme avec %d points", place, score);
        }

        fseek(sauv, 0, SEEK_SET);
        while(j<i)
        {
            lecture = fgetc(sauv);
            if (lecture == '\n')
            {
                j++;
            }
        }
        fprintf(sauv, "%s%d\n", nom, score);
        fclose(sauv);
    }
}
