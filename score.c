#include <string.h>

void fscore(int scorePlayer)
{
    int score[100]={0}, maxi, i;
    char name[12];
    char pseudo[100][4];

    printf("Votre Pseudo (3 caracteres): ");
    do
    {
        gets(name);
        for (i=0 ; i<4 ; i++)
        {
            name[i]=toupper(name[i]);
        }
    }while (strlen(name)!=3);

    printf("\nVotre score : %d\n", scorePlayer);
    inscriptionScore(name, scorePlayer);
    maxi = lectureScore(pseudo, score);
    triScore(pseudo, score, maxi);
}
