#include "structures.h"

//Pour avoir une idée de ce que génère cette fonction voir cette page de mon site : http://trehiou.no-ip.info/wordpress/index.php/pacman-en-c-2

void initialisation(char terrain[20][38], coordonees* PacMan, coordonees* fantomeA, coordonees* fantomeB, coordonees* fantomeC, coordonees* fantomeD)
{

    /*Le fonctionnement est le suivant

        i correspond aux lignes
        j correspond aux collonnes

        Chaque test "dessine" une forme du terrain à l'aide de ses coordonnées

    */

    int i, j;

    for(i=0; i<20; i++)
    {
        for(j=0; j<38; j++)
        {
        //Remplissage de l'arene par des points

            terrain[i][j] = '.';

        //Génération du pourtour

            if(i == 0 || j == 0 || i == 19 || j== 37)
            {
                terrain[i][j] = '#';

            }

        //Petite barre au milieu

            if(i < 5 && j == 18)
            {

                terrain[i][j] = '#';

            }

        //Rectangles

            //Première ligne de rectangle

            if(i > 1 && j > 1 && i < 5 && j < 8)
            {

                terrain[i][j] = '#';

            }

            if(i > 1 && j > 8 && i < 5 && j < 17)
            {

                terrain[i][j] = '#';

            }

            if(i > 1 && j > 19 && i < 5 && j < 28)
            {

                terrain[i][j] = '#';

            }

            if(i > 1 && j > 28 && i < 5 && j < 36)
            {

                terrain[i][j] = '#';

            }

            //Deuxieme ligne de rectangles

            if(i > 5 && j > 0 && i < 8 && j < 8)
            {

                terrain[i][j] = '#';

            }


            if(i > 5 && j > 28 && i < 8 && j <= 37)
            {

                terrain[i][j] = '#';

            }

            //Troisieme ligne de rectangles

            if(i > 8 && j >= 0 && i < 12 && j < 8)
            {

                terrain[i][j] = '#';

            }

            if(i > 8 && j > 28 && i < 12 && j < 37)
            {

                terrain[i][j] = '#';

            }

            //Rectangle où les fantomes aparaissent

            if(i > 11 && j > 13 && i < 15 && j < 23)
            {

                terrain[i][j] = '#';

            }

            //Il faut vider ce rectangle && laisser deux passages

            if(i == 13 && j > 14 && j < 22)
            {

                terrain[i][j] = '.';

            }

            if((i == 12 && j == 18) || (i == 14 && j == 17))
            {

                terrain[i][j] = '.';

            }

            //Quatrième ligne de rectangles

            if(i > 11 && j > 10 && i < 14 && j < 13)
            {

                terrain[i][j] = '#';

            }

            if(i > 11 && j > 23 && i < 14 && j < 26)
            {

                terrain[i][j] = '#';

            }

            //Rectangle en bas au milieu

            if(i > 15 && j > 13 && i < 18 && j < 23)
            {

                terrain[i][j] = '#';

            }

            //Rectangles du bas

            if(i > 16 && j > 1 && i < 19 && j < 13)
            {

                terrain[i][j] = '#';

            }
            if(i > 16 && j > 23 && i < 19 && j < 36)
            {

                terrain[i][j] = '#';

            }

        // Différentes lignes

            //D||ble T au milieu

            if((i == 6 || i == 10) && j > 10 && j < 26)
            {

                terrain[i][j] = '#';

            }

            if(i > 6 && i < 10 && j == 18)
            {

                terrain[i][j] = '#';

            }

        //Les T qui s'imbriquent dans le précédent

            if(i > 5 && i < 10 && (j == 9 || j == 27))
            {

                terrain[i][j] = '#';

            }

            if(i == 8 && ((j > 8 && j < 17) || (j > 19 && j < 28)))
            {

                terrain[i][j] = '#';

            }

        //Différents traits dans la partie basse

            //Cinq barres verticales
            if(i > 10 && i < 14 && (j == 9 || j == 27))
            {

                terrain[i][j] = '#';

            }

            if(i > 12 && i < 16 && j == 5)
            {

                terrain[i][j] = '#';

            }

            if(i > 14 && i < 18 && (j == 7 || j == 30))
            {

                terrain[i][j] = '#';

            }

            //Sept barres horizontales

            if(i == 13 && ((j > 1 && j < 6) || (j > 6 && j < 10) || (j > 28 && j < 37)))
            {

                terrain[i][j] = '#';

            }

            if(i == 15 && ((j > 0 && j < 4) || (j > 6 && j < 13) || (j > 23 && j < 31) || (j > 31 && j < 37)))
            {

                terrain[i][j] = '#';

            }

        }
    }

    //Initialisation de PacMan

    terrain[1][1] = 'C';
    PacMan->i = 1;
    PacMan->j = 1;

    //Initialisation des fantomes

    terrain[13][15] = 'M';
    fantomeA->i = 13;
    fantomeA->j = 15;

    terrain[13][17] = 'M';
    fantomeB->i = 13;
    fantomeB->j = 17;

    terrain[13][19] = 'M';
    fantomeC->i = 13;
    fantomeC->j = 19;

    terrain[13][21] = 'M';
    fantomeD->i = 13;
    fantomeD->j = 21;

    //Initialisation des bonus

    terrain[18][1] = 'B';
    terrain[1][36] = 'B';


}
