#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lectureScore(char pseudo[100][4], int score[100])
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

            fseek(sauv, 1, SEEK_CUR); // On passe l'espace

            fgets(lecture, 4, sauv); //On lit le score
            score[i] = atoi(lecture); //On convertit la lecture en nombre

            i++;
        }

        fclose(sauv);
    }
    else
    {
        printf("Erreur lors de l'ouverture du fichier pour lecture");
    }

    return (i-1);
}
