#include "structures.h"

char deplacementFantome(int direction, coordonees *fantome, char point, char terrain[20][38], char *entree)
{

    //Cette fonction fonctionne exactement de la même manière que pour PacMan : voir deplacement.c

    switch(direction)
    {
    case 1:
        if(terrain[fantome->i + 1][fantome->j]=='.')
        {
            terrain[fantome->i][fantome->j] = point;
            fantome->i = fantome->i + 1;
            terrain[fantome->i][fantome->j] = 'M';
            point = '.';
        }
        else if(terrain[fantome->i + 1][fantome->j]==' ')
        {
            terrain[fantome->i][fantome->j] = point;
            fantome->i = fantome->i + 1;
            terrain[fantome->i][fantome->j] = 'M';
            point = ' ';
        }
        else if(terrain[fantome->i + 1][fantome->j]=='C')
        {
            *entree = 'Q';
        }
        break;

    case 2:
        if(terrain[fantome->i][fantome->j - 1]=='.')
        {
            terrain[fantome->i][fantome->j] = point;
            fantome->j = fantome->j - 1;
            terrain[fantome->i][fantome->j] = 'M';
            point = '.';
        }
        else if(terrain[fantome->i][fantome->j - 1]==' ')
        {
            terrain[fantome->i][fantome->j] = point;
            fantome->j = fantome->j - 1;
            terrain[fantome->i][fantome->j] = 'M';
            point = ' ';
        }
        else if(terrain[fantome->i][fantome->j - 1]=='C')
        {
            *entree = 'Q';
        }
        break;

    case 3:
        if(terrain[fantome->i - 1][fantome->j]=='.')
        {
            terrain[fantome->i][fantome->j] = point;
            fantome->i = fantome->i - 1;
            terrain[fantome->i][fantome->j] = 'M';
            point = '.';
        }
        else if(terrain[fantome->i - 1][fantome->j]==' ')
        {
            terrain[fantome->i][fantome->j] = point;
            fantome->i = fantome->i - 1;
            terrain[fantome->i][fantome->j] = 'M';
            point = ' ';
        }
        else if(terrain[fantome->i - 1][fantome->j]=='C')
        {
            *entree = 'Q';
        }
        break;

    case 4:
        if(terrain[fantome->i][fantome->j + 1]=='.')
        {
            terrain[fantome->i][fantome->j] = point;
            fantome->j = fantome->j + 1;
            terrain[fantome->i][fantome->j] = 'M';
            point = '.';
        }
        else if(terrain[fantome->i][fantome->j + 1]==' ')
        {
            terrain[fantome->i][fantome->j] = point;
            fantome->j = fantome->j + 1;
            terrain[fantome->i][fantome->j] = 'M';
            point = ' ';
        }
        else if(terrain[fantome->i][fantome->j + 1]=='C')
        {
            *entree = 'Q';
        }
        break;

    }

    return point;
}
