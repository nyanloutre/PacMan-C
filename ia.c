#include <math.h>
#include <time.h>

#include "structures.h"
//Peut-être faudra-t-il supprimer dans les if principaux le old Direction et l'insérer dans la détermination de la direction (if le plus imbriqué)

int ia(coordonees pacman, coordonees fantome, char terrain[20][38], int olDirection)
{
    int direction=0; // on a 1=Bas, 2=Gauche, 3=Haut, 4=Droite
    srand(time(NULL));

    if (terrain[fantome.i-1][fantome.j]==' ' || terrain[fantome.i-1][fantome.j]=='.')         //libre haut
    {
        if (terrain[fantome.i][fantome.j-1]==' ' || terrain[fantome.i][fantome.j-1]=='.')          //libre à haut,gauche
        {
            if (terrain[fantome.i+1][fantome.j]==' ' || terrain[fantome.i+1][fantome.j]=='.')                                //libre haut,gauche,bas
            {

                if (pacman.i-fantome.i<=0) //SI pacman en haut
                {
                    if (pacman.j-fantome.j<=0) //SI pacman à gauche
                    {
                        //le pacman ce trouve en haut à gauche du fantôme
                        if (pacman.i-fantome.i==0)
                        {
                            direction = 2;
                        }
                        else if (pacman.j-fantome.j==0)
                        {
                            direction = 3;
                        }
                        else
                        {
                            direction = rand()%2+2;
                        }
                    }
                    else
                    {
                        direction = 3;
                    }
                }
                else //SI pacman en bas
                {
                    if (pacman.j-fantome.j<=0) //SI pacman à gauche
                    {
                        //le pacman ce trouve en bas à gauche du fantôme
                        if (pacman.i-fantome.i==0)
                        {
                            direction = 2;
                        }
                        else if (pacman.j-fantome.j==0)
                        {
                            direction = 3;
                        }
                        else
                        {
                            direction = rand()%2+1;
                        }
                    }
                    else
                    {
                        direction = 1;
                    }
                }

            }
            else if (terrain[fantome.i][fantome.j+1]==' ' || terrain[fantome.i][fantome.j+1]=='.')   //libre à haut,gauche,droite
            {

            }
            else
            {
                direction = rand()%2+2;
            }
        }
        else if (terrain[fantome.i][fantome.j+1]==' ' || terrain[fantome.i][fantome.j+1]=='.')          //libre à haut, droite
        {
            if (terrain[fantome.i+1][fantome.j]==' ' || terrain[fantome.i+1][fantome.j]=='.')              //libre haut,droite,bas
            {
                // A VOIR
            }
            else
            {
                direction = rand()%2+3;
            }
        }
        else if (terrain[fantome.i+1][fantome.j]==' ' || terrain[fantome.i+1][fantome.j]=='.') //libre en haut, bas
        {

        }
        else
        {
            direction = 3;
        }

    }//FIN LIBRE HAUT
    else if (terrain[fantome.i+1][fantome.j]==' ' || terrain[fantome.i+1][fantome.j]=='.')      //libre bas
    {
        if (terrain[fantome.i][fantome.j-1]==' ' || terrain[fantome.i][fantome.j-1]=='.') //libre bas, gauche
        {
            if (terrain[fantome.i][fantome.j+1]==' ' || terrain[fantome.i][fantome.j+1]=='.') //libre bas, gauche, droite
            {
                //A VOIR
            }
            else
            {
                direction = rand()%2+1;
            }
        }
        else
        {
            direction = 1;
        }

    }//FIN LIBRE BAS
    else if (terrain[fantome.i][fantome.j-1]==' ' || terrain[fantome.i][fantome.j-1]=='.')      //Libre gauche
    {
        if (terrain[fantome.i][fantome.j+1]==' ' || terrain[fantome.i][fantome.j+1]=='.')
        {
            if (pacman.j-fantome.j<=0) //SI pacman à gauche
            {
                direction = 2;
            }
            else
            {
                direction = 2;
            }
        }
        else
        {
            direction = 2;
        }

    }
    else if (terrain[fantome.i][fantome.j+1]==' ' || terrain[fantome.i][fantome.j+1]=='.')        //Libre droite
    {
        direction = 4;
    }
    /*---------------------------------------------------------

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
    }*/
    return direction;
}
