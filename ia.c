#include <math.h>

#include "structures.h"


int ia(coordonees pacman, coordonees fantome, char terrain[20][38])
{
    int direction=0; // on a 1=Bas, 2=Gauche, 3=Haut, 4=Droite

    /*if (terrain[fantome.i-1][fantome.j]==' ' || terrain[fantome.i-1][fantome.j]=='.')                       //libre devant
    {
        if (terrain[fantome.i][fantome.j-1]==' ' || terrain[fantome.i][fantome.j-1]=='.')                       //libre à devant,gauche
        {
            if (terrain[fantome.i+1][fantome.j]==' ' || terrain[fantome.i+1][fantome.j]=='.')                       //libre devant,gauche,bas
            {

            }
            else if (terrain[fantome.i][fantome.j+1]==' ' || terrain[fantome.i+1][fantome.j+1]=='.')                //libre à devant,gauche,droite
            {

            }
        }
        else if (terrain[fantome.i][fantome.j+1]==' ' || terrain[fantome.i+1][fantome.j+1]=='.')                //libre à devant, droite
        {
            if (terrain[fantome.i+1][fantome.j]==' ' || terrain[fantome.i+1][fantome.j]=='.')                       //libre devant,droite,bas
            {

            }
            else if (terrain[fantome.i][fantome.j+1]==' ' || terrain[fantome.i+1][fantome.j+1]=='.')                //libre à devant,droite,
            {

            }
        }
        else if ()
        {

        }

    }*/

    if (pacman.i<=fantome.i)
    {
        if (terrain[fantome.i-1][fantome.j]==' ' || terrain[fantome.i-1][fantome.j]=='.') //si il y a pas de mur devant le fantôme alors on avance vers le haut
        {
            direction = 3;
        }
        else if (terrain[fantome.i][fantome.j-1]==' ' || terrain[fantome.i][fantome.j-1]=='.')
        {
            direction = 2;
        }
        else if (terrain[fantome.i+1][fantome.j]==' ' || terrain[fantome.i+1][fantome.j]=='.')
        {
            direction = 1;
        }
        else
        {
            direction = 4;
        }
    }
    else if (pacman.j>=fantome.j)
    {
        if (terrain[fantome.i+1][fantome.j]==' ' || terrain[fantome.i+1][fantome.j]=='.')
        {
            direction = 1;
        }
        else if (terrain[fantome.i][fantome.j+1]==' ' || terrain[fantome.i][fantome.j+1]=='.')
        {
            direction = 4;
        }
        else if (terrain[fantome.i][fantome.j-1]==' ' || terrain[fantome.i][fantome.j-1]=='.')
        {
            direction = 2;
        }
        else
        {
            direction = 3;
        }
    }



    /*if (pacman.j < fantome.j)  //test pour savoir si le fantôme est à gauche du pacman
    {
        if (pacman.i < fantome.i) //test pour savoir si le pacman est en haut du fantôme
        {
            if (terrain[fantome.i-1][fantome.j]==' ' || terrain[fantome.i-1][fantome.j]=='.') //si il y a pas de mur devant le fantôme alors ...
            {
                direction = 3;
            }
            else if (terrain[fantome.i][fantome.j-1]==' ' || terrain[fantome.i][fantome.j-1]=='.')
            {
                direction = 2;
            }
        }
        else
        {
            if (terrain[fantome.i-1][fantome.j]==' ' || terrain[fantome.i-1][fantome.j]=='.') //si il y a pas de mur devant le fantôme alors ...
            {
                direction = 3;
            }
            else if (terrain[fantome.i][fantome.j+1]==' ' || terrain[fantome.i][fantome.j+1]=='.')
            {
                direction = 4;
            }
        }
    }
    else
    {
        if (pacman.i < fantome.i)
        {
            if (terrain[fantome.i-1][fantome.j]==' ' || terrain[fantome.i-1][fantome.j]=='.')
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
            if (terrain[fantome.i+1][fantome.j]==' ' || terrain[fantome.i+1][fantome.j]=='.')
            {
                direction = 1;
            }
            else
            {
                direction = 4;
            }
        }
    }*/
    return direction;
}
