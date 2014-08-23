#include <stdio.h>

void affichageBestScore(char pseudo[100][4], int score[100], int maxi)
{
    int i=1;

    printw("   MEILLEURS SCORES\n\n");
    printw("\nPseudo\t|\tScore\n");
    printw("----------------------\n");

    while (i<=maxi && i<11)
    {
        printw("%s\t|\t%d\n", pseudo[maxi-i], score[maxi-i]); //parcours du tableau à l'envers
        i++;
    }

    printw("\n");
    getch();

}
