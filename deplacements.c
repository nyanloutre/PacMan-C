#include "structures.h"
#include "score.h"

#include <windows.h>

void deplacements(char terrain[20][38], coordonees *PacMan, coordonees *fantomeA, coordonees *fantomeB, coordonees *fantomeC, coordonees *fantomeD)
{
    const int MAX = 4, MIN = 1;
    char entree, pointA = '.', pointB = '.', pointC = '.', pointD = '.';
    int score=0, bonus = 0;
    int c;




    //Le PacMan se déplace à l'aide des touches z,q,s et d. Le jeu peut être quitté avec Esc

    entree = getch();

    do
    {

        /*On récupère les entrées au clavier grace à la fonction GetKeyState qui est dans windows.h
          Les tests empèchent le joueur de diriger PacMan vers un mur (cela ralentirai le jeu)*/
        if(GetKeyState(0x5A) < 0 && (terrain[PacMan->i - 1][PacMan->j] == ' ' || terrain[PacMan->i - 1][PacMan->j] == '.' || terrain[PacMan->i - 1][PacMan->j] == 'M'))
        {
            entree = 'z';
        }

        if(GetKeyState(0x51) < 0 && (terrain[PacMan->i][PacMan->j - 1] == ' ' || terrain[PacMan->i][PacMan->j - 1] == '.' || terrain[PacMan->i][PacMan->j - 1] == 'M'))
        {
            entree = 'q';
        }

        if(GetKeyState(0x53) < 0 && (terrain[PacMan->i + 1][PacMan->j] == ' ' || terrain[PacMan->i + 1][PacMan->j] == '.' || terrain[PacMan->i + 1][PacMan->j] == 'M'))
        {
            entree = 's';
        }

        if(GetKeyState(0x44) < 0 && (terrain[PacMan->i][PacMan->j + 1] == ' ' || terrain[PacMan->i][PacMan->j + 1] == '.' || terrain[PacMan->i][PacMan->j + 1] == 'M'))
        {
            entree = 'd';
        }

        if(GetKeyState(VK_ESCAPE) < 0)
        {
            entree = 'Q';
        }


        //En fonction de la touche appuiée on déplace le PacMan

        switch(entree)
        {

            case 's':

                if(terrain[PacMan->i + 1][PacMan->j] == '.') //Si PacMan se dirige vers un point on supprime le point et on incrémente un compteur
                {
                    terrain[PacMan->i][PacMan->j] = ' ';
                    PacMan->i = PacMan->i + 1;
                    terrain[PacMan->i][PacMan->j] = 'C';
                    score = score + 1;
                }
                else if(terrain[PacMan->i + 1][PacMan->j] == ' ') //Si il n'y a rien on déplace juste PacMan
                {
                    terrain[PacMan->i][PacMan->j] = ' ';
                    PacMan->i = PacMan->i + 1;
                    terrain[PacMan->i][PacMan->j] = 'C';

                }
                else if(terrain[PacMan->i + 1][PacMan->j] == 'M') //Si c'est un fantome c'est perdu
                {
                    entree = 'Q';
                }
                else if(terrain[PacMan->i + 1][PacMan->j] == 'B') //Si il n'y a rien on déplace juste PacMan
                {
                    terrain[PacMan->i][PacMan->j] = ' ';
                    PacMan->i = PacMan->i + 1;
                    terrain[PacMan->i][PacMan->j] = 'C';
                    bonus = 1;
                }
                break;

            case 'q':

                if(terrain[PacMan->i][PacMan->j - 1]=='.')
                {
                    terrain[PacMan->i][PacMan->j] = ' ';
                    PacMan->j = PacMan->j - 1;
                    terrain[PacMan->i][PacMan->j] = 'C';
                    score = score + 1;
                }
                else if(terrain[PacMan->i][PacMan->j - 1]==' ')
                {
                    terrain[PacMan->i][PacMan->j] = ' ';
                    PacMan->j = PacMan->j - 1;
                    terrain[PacMan->i][PacMan->j] = 'C';

                }
                else if(terrain[PacMan->i][PacMan->j - 1]=='M')
                {
                    entree = 'Q';
                }
                else if(terrain[PacMan->i][PacMan->j - 1]=='B')
                {
                    terrain[PacMan->i][PacMan->j] = ' ';
                    PacMan->j = PacMan->j - 1;
                    terrain[PacMan->i][PacMan->j] = 'C';
                    bonus = 1;
                }
                break;

            case 'z':

                if(terrain[PacMan->i - 1][PacMan->j] == '.')
                {
                    terrain[PacMan->i][PacMan->j] = ' ';
                    PacMan->i = PacMan->i - 1;
                    terrain[PacMan->i][PacMan->j] = 'C';
                    score = score + 1;
                }
                else if(terrain[PacMan->i - 1][PacMan->j] == ' ')
                {
                    terrain[PacMan->i][PacMan->j] = ' ';
                    PacMan->i = PacMan->i - 1;
                    terrain[PacMan->i][PacMan->j] = 'C';

                }
                else if(terrain[PacMan->i - 1][PacMan->j] == 'M')
                {
                    entree = 'Q';
                }
                else if(terrain[PacMan->i - 1][PacMan->j] == 'B')
                {
                    terrain[PacMan->i][PacMan->j] = ' ';
                    PacMan->i = PacMan->i - 1;
                    terrain[PacMan->i][PacMan->j] = 'C';
                    bonus = 1;
                }
                break;

            case 'd':

                if(terrain[PacMan->i][PacMan->j + 1]=='.')
                {
                    terrain[PacMan->i][PacMan->j] = ' ';
                    PacMan->j = PacMan->j + 1;
                    terrain[PacMan->i][PacMan->j] = 'C';
                    score = score + 1;
                }
                else if(terrain[PacMan->i][PacMan->j + 1]==' ')
                {
                    terrain[PacMan->i][PacMan->j] = ' ';
                    PacMan->j = PacMan->j + 1;
                    terrain[PacMan->i][PacMan->j] = 'C';

                }
                else if(terrain[PacMan->i][PacMan->j + 1]=='M')
                {
                    entree = 'Q';
                }
                else if(terrain[PacMan->i][PacMan->j + 1]=='B')
                {
                    terrain[PacMan->i][PacMan->j] = ' ';
                    PacMan->j = PacMan->j + 1;
                    terrain[PacMan->i][PacMan->j] = 'C';
                    bonus = 1;
                }
                break;


        }

        //Deplacement des fantomes

        pointA = deplacementFantome(ia(*PacMan, *fantomeA), fantomeA, pointA, terrain, &entree);
        pointB = deplacementFantome(ia(*PacMan, *fantomeB), fantomeB, pointB, terrain, &entree);
        pointC = deplacementFantome(ia(*PacMan, *fantomeC), fantomeC, pointC, terrain, &entree);
        pointD = deplacementFantome(ia(*PacMan, *fantomeD), fantomeD, pointD, terrain, &entree);

        //On affiche la nouvelle frame
        affichage(terrain, score);

    }while(entree != 'Q');



    //On vide le buffer clavier car la fonction GetKeyState garde toutes les entrées en mémoire et les ressorts au getch suivant


   do {

        printf("Vous avez perdu pour sauvegarder et afficher votre score appuyer sur la touche espace");
        c = getch();
        system("CLS");

    } while (c != ' '); //On valide par espace

    fscore(score);
}
