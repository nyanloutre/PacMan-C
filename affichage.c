#include <ncurses.h>
#include "symboles.h"

void affichage(char terrain[20][38], int score, int bonus, int frame, int vies)
{
    int i, j;

    clear(); //On vide l'écran entre chaque frame

    init_pair(1, COLOR_WHITE, COLOR_BLACK); //Initialisation de la couleur blanche
    init_pair(2, COLOR_YELLOW, COLOR_BLACK); //Initialisation de la couleur jaune
    init_pair(3, COLOR_GREEN, COLOR_BLACK); //Initialisation de la couleur verts
    init_pair(4, COLOR_BLUE, COLOR_BLACK); //Initialisation de la couleur bleue
    init_pair(5, COLOR_RED, COLOR_BLACK); //Initialisation de la couleur rouge

    attron(COLOR_PAIR(1)); //Affichage avec la couleur blanche
    printw("Deplacez vous a l'aide des touches z, q, s et d.\nTentez d'attraper les %c\nQuittez avec Echap\n", point);

    for(i=0; i<20; i++)
    {
        for(j=0; j<38; j++)
        {

            if(terrain[i][j] == 'C')
            {
                attron(COLOR_PAIR(2)); //jaune
            }
            else if(terrain[i][j] == 'M')
            {
                attron(COLOR_PAIR(5)); //rouge
                if(bonus && (frame<35 || frame%2))
                {
                    attron(COLOR_PAIR(3)); //vert
                }
            }
            else if(terrain[i][j] == '.')
            {
                attron(COLOR_PAIR(1)); //blanc
            }
            else if(terrain[i][j] == point)
            {
                attron(COLOR_PAIR(3)); //vert
            }
            else
            {
                attron(COLOR_PAIR(4)); //bleu
            }

            printw("%c", terrain[i][j]); //On affiche le terrain

        }

        attron(COLOR_PAIR(2)); //jaune
        if(i==10){printw("        score : %d", score);};
        if(i==12){printw("        vies : %d", vies);};

        printw("\n");
    }

    attron(COLOR_PAIR(3)); //vert

    if(bonus)
    {
        printw("========== BONUS ACTIVE %d ==========", 50 - frame);
    }

    attron(COLOR_PAIR(1)); //blanc

    refresh();

    Sleep(200); //On fait une pause entre chaque frame pour contrôler la vitesse du jeu
}
