#include "structures.h"

int ia(coordonees pacman, coordonees fantome, char terrain[20][38])
{
    int direction=0; // on a 1=Bas, 2=Gauche, 3=Haut, 4=Droite

    if (pacman.j < fantome.j)  //test pour savoir si le fantôme est à gauche du pacman
    {
        if (pacman.i < fantome.i) //test pour savoir si le pacman est à gauche du fantôme
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
