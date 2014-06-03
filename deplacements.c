#include <windows.h>
#include <stdio.h>
#include <conio.h>

#include "structures.h"
#include "score.h"
#include "ia.h"
#include "affichage.h"
#include "deplacementfantomes.h"

void deplacements(char terrain[20][38], coordonees *PacMan, coordonees *fantomeA, coordonees *fantomeB, coordonees *fantomeC, coordonees *fantomeD)
{
    char entree, pointA = '.', pointB = '.', pointC = '.', pointD = '.';
    int score=0, bonus = 0, frame = 0;
    int c;




    //Le PacMan se déplace à l'aide des touches z,q,s et d. Le jeu peut être quitté avec Esc

    entree = getch(); //Cette commande permet au jeu de ne pas démarer tout de suite, mais d'attendre que le joueur soit pret

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

                if(terrain[PacMan->i + 1][PacMan->j] == '.') //Si PacMan se dirige vers un point on supprime le point et on incrémente le score
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
                else if(terrain[PacMan->i + 1][PacMan->j] == 'M' && !bonus) //Si c'est un fantôme et que le bonus n'est pas activé c'est perdu
                {
                    entree = 'Q';
                }
                else if(terrain[PacMan->i + 1][PacMan->j] == 'M' && bonus) //Si c'est un fantôme et que le bonus est activé, PacMan mange le fantôme et gagne 10 points
                {
                    terrain[PacMan->i][PacMan->j] = ' '; //La réaparition de PacMan est gérée plus loin car il y a plusieurs fantômes et qu'il faut les gérer au cas par cas
                    PacMan->i = PacMan->i + 1;
                    score += 10;
                }
                else if(terrain[PacMan->i + 1][PacMan->j] == 'B') //Si la case est un bonus on active le bonus
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
                else if(terrain[PacMan->i][PacMan->j - 1]=='M' && !bonus)
                {
                    entree = 'Q';
                }
                else if(terrain[PacMan->i][PacMan->j - 1]=='M' && bonus)
                {
                    terrain[PacMan->i][PacMan->j] = ' ';
                    PacMan->j = PacMan->j - 1;
                    score += 10;
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
                else if(terrain[PacMan->i - 1][PacMan->j] == 'M' && !bonus)
                {
                    entree = 'Q';
                }
                else if(terrain[PacMan->i - 1][PacMan->j] == 'M' && bonus)
                {
                    terrain[PacMan->i][PacMan->j] = ' ';
                    PacMan->i = PacMan->i - 1;
                    score += 10;
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
                else if(terrain[PacMan->i][PacMan->j + 1]=='M' && !bonus)
                {
                    entree = 'Q';
                }
                else if(terrain[PacMan->i][PacMan->j + 1]=='M' && bonus)
                {
                    terrain[PacMan->i][PacMan->j] = ' ';
                    PacMan->j = PacMan->j + 1;
                    score += 10;
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

        /*On gère les fantômes au cas par cas, il n'y a pas de condition bonus car le seul moyen
          pour que les coordonées de PacMan soient identiques à celle d'un fantôme est que le bonus soit activé*/

        if(PacMan->i == fantomeA->i && PacMan->j == fantomeA->j)
        {
            terrain[fantomeA->i][fantomeA->j] = 'C';
            fantomeA->i = 13;
            fantomeA->j = 15;
            pointA = ' ';
            terrain[fantomeA->i][fantomeA->j] = 'M';
        }
        else if(PacMan->i == fantomeB->i && PacMan->j == fantomeB->j)
        {
            terrain[fantomeB->i][fantomeB->j] = 'C';
            fantomeB->i = 13;
            fantomeB->j = 17;
            pointB = ' ';
            terrain[fantomeB->i][fantomeB->j] = 'M';
        }
        else if(PacMan->i == fantomeC->i && PacMan->j == fantomeC->j)
        {
            terrain[fantomeC->i][fantomeC->j] = 'C';
            fantomeC->i = 13;
            fantomeC->j = 19;
            pointC = ' ';
            terrain[fantomeC->i][fantomeC->j] = 'M';
        }
        else if(PacMan->i == fantomeD->i && PacMan->j == fantomeD->j)
        {
            terrain[fantomeD->i][fantomeD->j] = 'C';
            fantomeD->i = 13;
            fantomeD->j = 21;
            pointD = ' ';
            terrain[fantomeD->i][fantomeD->j] = 'M';
        }

        //Deplacement des fantomes

        pointA = deplacementFantome(ia(*PacMan, *fantomeA, terrain), fantomeA, pointA, terrain, &entree, bonus);
        pointB = deplacementFantome(ia(*PacMan, *fantomeB, terrain), fantomeB, pointB, terrain, &entree, bonus);
        pointC = deplacementFantome(ia(*PacMan, *fantomeC, terrain), fantomeC, pointC, terrain, &entree, bonus);
        pointD = deplacementFantome(ia(*PacMan, *fantomeD, terrain), fantomeD, pointD, terrain, &entree, bonus);

        //On affiche la nouvelle frame ainsi générée
        affichage(terrain, score, bonus, frame);

        //compteur de frame
        if(bonus)
        {
            frame++;
        }

        //On réinitialise le bonus après 50 frames
        if(frame>50)
        {
            bonus=0;
            frame=0;
        }

    }while(entree != 'Q');



    //On vide le buffer clavier car la fonction GetKeyState garde toutes les entrées en mémoire et les ressorts au getch suivant


   do {

        printf("Vous avez perdu pour sauvegarder et afficher votre score appuyer sur la touche espace");
        c = getch();
        system("CLS");

    } while (c != ' '); //On valide par espace

    fscore(score);
}
