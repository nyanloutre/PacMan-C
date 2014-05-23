#include <windows.h>
#include "symboles.h"

void affichage(char terrain[20][38], int score)
{
    int i, j;

    system("CLS"); //On vide l'écran entre chaque frame

    printf("Votre score est actuellement de %d\nDeplacez vous a l'aide des touches z, q, s et d\nQuittez avec Echap\n", score);

    for(i=0; i<20; i++)
    {
        for(j=0; j<38; j++)
        {
            if(terrain[i][j]=='C')
            {
                printf("%c", smiley);
            }
            else
            {
                printf("%c", terrain[i][j]); //On affiche le terrain
            }


        }

        printf("\n");
    }



    Sleep(200); //On fait une pause entre chaque frame pour contrôler la vitesse du jeu
}
