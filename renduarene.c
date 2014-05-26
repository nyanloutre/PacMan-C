#include "symboles.h"


//Le but de cette fonction est de remplacer les dièses initialements générés par des symboles

void renduarene(char terrain[20][38])
{
    int i,j;
    char betterterrain [20][38];


    //On vide les rectangles
    for(i=0; i<20; i++)
    {
        for(j=0; j<38; j++)
        {

            if(terrain[i][j] == '#' && terrain[i-1][j+1] == '#' && terrain[i+1][j+1] == '#' && terrain[i+1][j-1] == '#' && terrain[i-1][j-1] == '#')
            {
                terrain[i][j] = ' ';
                betterterrain[i][j] = ' ';
            }

        }
    }


    for(i=0; i<20; i++)
    {
        for(j=0; j<38; j++)
        {

            switch(terrain[i][j])
            {
            case '#':


                /* on verifie pour la case courante ce qu'il y a à:
                         en haut                    à droite              en bas                       à gauche
                puis en fonction de ça, on remplace par le symbole correspondant*/

                if(terrain[i-1][j] != '#' && terrain[i][j+1] == '#' && terrain[i+1][j] == '#' &&  terrain[i][j-1] != '#')
                {
                    betterterrain[i][j] = coin_hg;
                }

                if(terrain[i-1][j] != '#' && terrain[i][j+1] != '#' && terrain[i+1][j] == '#' &&  terrain[i][j-1] == '#')
                {
                    betterterrain[i][j] = coin_hd;
                }

                if(terrain[i-1][j] == '#' && terrain[i][j+1] == '#' && terrain[i+1][j] != '#' &&  terrain[i][j-1] != '#')
                {
                    betterterrain[i][j] = coin_bg;
                }

                if(terrain[i-1][j] == '#' && terrain[i][j+1] != '#' && terrain[i+1][j] != '#' &&  terrain[i][j-1] == '#')
                {
                    betterterrain[i][j] = coin_bd;
                }

                if(terrain[i-1][j] != '#' && terrain[i][j+1] == '#' && terrain[i+1][j] != '#' &&  terrain[i][j-1] == '#')
                {
                    betterterrain[i][j] = bar_hor;
                }

                if(terrain[i-1][j] == '#' && terrain[i][j+1] != '#' && terrain[i+1][j] == '#' &&  terrain[i][j-1] != '#')
                {
                    betterterrain[i][j] = bar_ver;
                }

                if(terrain[i-1][j] == '#' && terrain[i][j+1] != '#' && terrain[i+1][j] == '#' &&  terrain[i][j-1] == '#')
                {
                    betterterrain[i][j] = t_gau;
                }

                if(terrain[i-1][j] == '#' && terrain[i][j+1] == '#' && terrain[i+1][j] != '#' &&  terrain[i][j-1] == '#')
                {
                    betterterrain[i][j] = t_hau;
                }

                if(terrain[i-1][j] != '#' && terrain[i][j+1] == '#' && terrain[i+1][j] == '#' &&  terrain[i][j-1] == '#')
                {
                    betterterrain[i][j] = t_bas;
                }
                if(terrain[i-1][j] == '#' && terrain[i][j+1] == '#' && terrain[i+1][j] == '#' &&  terrain[i][j-1] != '#')
                {
                    betterterrain[i][j] = t_dro;
                }
                if(terrain[i-1][j] == '#' && terrain[i][j+1] == '#' && terrain[i+1][j] == '#' &&  terrain[i][j-1] == '#')
                {
                    betterterrain[i][j] = croix;
                }

                //Les bouts de lignes
                if(terrain[i-1][j] != '#' && terrain[i][j+1] != '#' && terrain[i+1][j] != '#' &&  terrain[i][j-1] == '#')
                {
                    betterterrain[i][j] = bar_hor;
                }
                if(terrain[i-1][j] != '#' && terrain[i][j+1] == '#' && terrain[i+1][j] != '#' &&  terrain[i][j-1] != '#')
                {
                    betterterrain[i][j] = bar_hor;
                }
                if(terrain[i-1][j] != '#' && terrain[i][j+1] != '#' && terrain[i+1][j] == '#' &&  terrain[i][j-1] != '#')
                {
                    betterterrain[i][j] = bar_ver;
                }
                if(terrain[i-1][j] == '#' && terrain[i][j+1] != '#' && terrain[i+1][j] != '#' &&  terrain[i][j-1] != '#')
                {
                    betterterrain[i][j] = bar_ver;
                }

                break;

            case '.':

                   betterterrain[i][j] = '.';
                   break;


            case 'C':

                    betterterrain[i][j] = 'C';
                    break;


            case 'M':

                    betterterrain[i][j] = 'M';
                    break;

            case 'B':

                    betterterrain[i][j] = 'B';
                    break;

            }

                /*Ces test sert à corriger un bug qui fait que quand on arrive
                  à la dernière case d'une ligne d'un tableau et que l'on veut
                  lire la case suivante (qui ne devrait pas exister en théorie)
                  le programme lit la première case de la ligne suivante*/

                if((j == 0 || j == 37) && (i != 0 && i != 19))
                {
                    betterterrain[i][j] = bar_ver;
                }
                if(j == 0 && i == 19)
                {
                    betterterrain[i][j] = coin_bg;
                }
                if(j == 37 && i == 0)
                {
                    betterterrain[i][j] = coin_hd;
                }
                if(j == 0 && (i == 6 || i == 7 || i == 9 || i == 11 || i == 15))
                {
                    betterterrain[i][j] = t_dro;
                }
                if(j == 37 && (i == 6 || i == 7 || i == 9 || i == 11 || i == 13 || i == 15))
                {
                    betterterrain[i][j] = t_gau;
                }

        }
    }

    //On remplace ensuite par le nouveau terrain, on ne peut pas le mettre dans la première boucle car cela fausserai les calculs.
    for(i=0; i<20; i++)
    {
        for(j=0; j<38; j++)
        {

            terrain[i][j] = betterterrain[i][j];

        }
    }

}
