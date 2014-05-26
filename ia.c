#include "structures.h"

int ia(coordonees pacman, coordonees fantome)
{
    int direction=0;

    if (pacman.j < fantome.j)  //test pour savoir si le fantôme est à gauche ou à droite du pacman
    {
        if (pacman.i < fantome.i)
        {
            direction = rand()%2+2;
        }
        else
        {
            direction = rand()%2+1;
        }
    }
    else
    {
        if (pacman.i < fantome.i)
        {
            direction = rand()%5+3;
        }
        else
        {
            switch(rand()%2)
            {
                case 0 :
                    direction = 1;
                    break;
                case 1 :
                    direction = 4;
                    break;
            }
        }
    }
    return direction;
}
