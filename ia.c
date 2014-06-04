#include "structures.h"

int ia(coordonees pacman, coordonees fantome, char terrain[20][38])
{
    int direction=0; // on a 1=Bas, 2=Gauche, 3=Haut, 4=Droite

    if (pacman.j < fantome.j)  //test pour savoir si le fantôme est à gauche du pacman
    {
        if (pacman.i < fantome.i) //test pour savoir si le pacman est en haut du fantôme
        {
            if (terrain[fantome.i-1][fantome.j]==' ') //si il y a pas de mur devant le fantôme alors ...

            {
                direction = 3;
            }
            else if (terrain[fantome.i][fantome.j-1]==' ')
            {
                direction = 2;
            }
        }
        else
        {
            if (terrain[fantome.i-1][fantome.j]==' ') //si il y a pas de mur devant le fantôme alors ...
            {
                direction = 3;
            }
            else if (terrain[fantome.i][fantome.j+1]==' ')
            {
                direction = 4;
            }
        }
    }
    else
    {
        if (pacman.i < fantome.i)
        {
            if (terrain[fantome.i-1][fantome.j]==' ')
            {
                direction = 3;
            }
            else
            {
                direction = 4;
            }
        }
        else
        {
            if (terrain[fantome.i+1][fantome.j]==' ')
            {
                direction = 1;
            }
            else
            {
                direction = 4;
            }
        }
    }
    return direction;
}
