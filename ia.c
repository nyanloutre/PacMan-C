#include <math.h>

#include "structures.h"


int ia(coordonees pacman, coordonees fantome, char terrain[20][38], int olDirection)
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
        if (pacman.j<=fantome.j)
        {
            if (olDirection != 1 && (terrain[fantome.i-1][fantome.j]==' ' || terrain[fantome.i-1][fantome.j]=='.')) //si il y a pas de mur devant le fantôme alors on avance vers le haut
            {
                direction = 3;
            }
            else if (olDirection != 4 && (terrain[fantome.i][fantome.j-1]==' ' || terrain[fantome.i][fantome.j-1]=='.'))
            {
                direction = 2;
            }
            else if (olDirection != 3 && (terrain[fantome.i+1][fantome.j]==' ' || terrain[fantome.i+1][fantome.j]=='.'))
            {
                direction = 1;
            }
            else if (olDirection != 2 && (terrain[fantome.i][fantome.j+1]==' ' || terrain[fantome.i][fantome.j+1]=='.'))
            {
                direction = 4;
            }
        }
        else
        {
            if (olDirection != 1 && (terrain[fantome.i-1][fantome.j]==' ' || terrain[fantome.i-1][fantome.j]=='.')) //si il y a pas de mur devant le fantôme alors on avance vers le haut
            {
                direction = 3;
            }
            else if (olDirection != 3 && (terrain[fantome.i+1][fantome.j]==' ' || terrain[fantome.i+1][fantome.j]=='.'))
            {
                direction = 1;
            }
            else if (olDirection != 4 && (terrain[fantome.i][fantome.j-1]==' ' || terrain[fantome.i][fantome.j-1]=='.'))
            {
                direction = 2;
            }
            else if(olDirection != 2 && (terrain[fantome.i][fantome.j+1]==' ' || terrain[fantome.i][fantome.j+1]=='.'))
            {
                direction = 4;
            }
        }
    }
    else if (pacman.i>=fantome.i)
    {
        if (pacman.j<=fantome.j)
        {
            if (olDirection != 3 && (terrain[fantome.i+1][fantome.j]==' ' || terrain[fantome.i+1][fantome.j]=='.'))
            {
                direction = 1;
            }
            else if (olDirection != 4 && (terrain[fantome.i][fantome.j-1]==' ' || terrain[fantome.i][fantome.j-1]=='.'))
            {
                direction = 2;
            }
            else if (olDirection != 2 && (terrain[fantome.i][fantome.j+1]==' ' || terrain[fantome.i][fantome.j+1]=='.'))
            {
                direction = 4;
            }
            else if(olDirection != 1 && (terrain[fantome.i-1][fantome.j]==' ' || terrain[fantome.i-1][fantome.j]=='.'))
            {
                direction = 3;
            }
        }
        else
        {
            if (olDirection != 3 && (terrain[fantome.i+1][fantome.j]==' ' || terrain[fantome.i+1][fantome.j]=='.'))
            {
                direction = 1;
            }
            else if (olDirection != 2 && (terrain[fantome.i][fantome.j+1]==' ' || terrain[fantome.i][fantome.j+1]=='.'))
            {
                direction = 4;
            }
            else if (olDirection != 4 && (terrain[fantome.i][fantome.j-1]==' ' || terrain[fantome.i][fantome.j-1]=='.'))
            {
                direction = 2;
            }
            else if(olDirection != 1 && (terrain[fantome.i-1][fantome.j]==' ' || terrain[fantome.i-1][fantome.j]=='.'))
            {
                direction = 3;
            }
        }
    }
    return direction;
}
