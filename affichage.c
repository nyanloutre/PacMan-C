#include <windows.h>
#include "symboles.h"
#include "conio.c"

void affichage(char terrain[20][38], int score, int bonus, int frame)
{
    int i, j;

    system("CLS"); //On vide l'écran entre chaque frame

    textcolor(WHITE);
    printf("Votre score est actuellement de %d\nDeplacez vous a l'aide des touches z, q, s et d.\nTentez d'attraper les %c\nQuittez avec Echap\n", score, point);

    for(i=0; i<20; i++)
    {
        for(j=0; j<38; j++)
        {

            if(terrain[i][j] == 'C')
            {
                textcolor(YELLOW);
            }
            else if(terrain[i][j] == 'M')
            {
                textcolor(LIGHTRED);
                if(bonus && (frame<35 || frame%2))
                {
                    textcolor(LIGHTGREEN);
                }
            }
            else if(terrain[i][j] == '.')
            {
                textcolor(WHITE);
            }
            else if(terrain[i][j] == point)
            {
                textcolor(LIGHTGREEN);
            }
            else
            {
                textcolor(LIGHTBLUE);
            }

            printf("%c", terrain[i][j]); //On affiche le terrain

        }

        printf("\n");
    }

    textcolor(LIGHTGREEN);

    if(bonus)
    {
        printf("========== BONUS ACTIVE %d ==========", 50 - frame);
    }

    textcolor(WHITE);

    Sleep(200); //On fait une pause entre chaque frame pour contrôler la vitesse du jeu
}
