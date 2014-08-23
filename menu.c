#include <stdio.h>
#include <stdlib.h>

void menu(int *entree)
{
    char saisie;

    system("CLS");

    printw("\n");

    attron(COLOR_PAIR(2)); //jaune
    printw(" /$$$$$$$   ");
    attron(COLOR_PAIR(4)); //bleu
    printw("/$$$$$$   ");
    attron(COLOR_PAIR(5)); //rouge
    printw("/$$$$$$        ");
    attron(COLOR_PAIR(4)); //bleu
    printw("/$$      /$$  ");
    attron(COLOR_PAIR(3)); //vert
    printw("/$$$$$$  ");
    attron(COLOR_PAIR(2)); //jaune
    printw("/$$   /$$\n");


    printw("| $$__  $$ ");
    attron(COLOR_PAIR(4)); //bleu
    printw("/$$__  $$ ");
    attron(COLOR_PAIR(5)); //rouge
    printw("/$$__  $$      ");
    attron(COLOR_PAIR(4)); //bleu
    printw("| $$$    /$$$");
    attron(COLOR_PAIR(3)); //vert
    printw(" /$$__  $$");
    attron(COLOR_PAIR(2)); //jaune
    printw("| $$$ | $$\n");


    printw("| $$  \\ $$");
    attron(COLOR_PAIR(4)); //bleu
    printw("| $$  \\ $$");
    attron(COLOR_PAIR(5)); //rouge
    printw("| $$  \\__/      ");
    attron(COLOR_PAIR(4)); //bleu
    printw("| $$$$  /$$$$");
    attron(COLOR_PAIR(3)); //vert
    printw("| $$  \\ $$");
    attron(COLOR_PAIR(2)); //jaune
    printw("| $$$$| $$\n");


    printw("| $$$$$$$/");
    attron(COLOR_PAIR(4)); //bleu
    printw("| $$$$$$$$");
    attron(COLOR_PAIR(5)); //rouge
    printw("| $$            ");
    attron(COLOR_PAIR(4)); //bleu
    printw("| $$ $$/$$ $$");
    attron(COLOR_PAIR(3)); //vert
    printw("| $$$$$$$$");
    attron(COLOR_PAIR(2)); //jaune
    printw("| $$ $$ $$\n");


    printw("| $$____/ ");
    attron(COLOR_PAIR(4)); //bleu
    printw("| $$__  $$");
    attron(COLOR_PAIR(5)); //rouge
    printw("| $$            ");
    attron(COLOR_PAIR(4)); //bleu
    printw("| $$  $$$| $$");
    attron(COLOR_PAIR(3)); //vert
    printw("| $$__  $$");
    attron(COLOR_PAIR(2)); //jaune
    printw("| $$  $$$$\n");

    printw("| $$      ");
    attron(COLOR_PAIR(4)); //bleu
    printw("| $$  | $$");
    attron(COLOR_PAIR(5)); //rouge
    printw("| $$    $$      ");
    attron(COLOR_PAIR(4)); //bleu
    printw("| $$\\  $ | $$");
    attron(COLOR_PAIR(3)); //vert
    printw("| $$  | $$");
    attron(COLOR_PAIR(2)); //jaune
    printw("| $$\\  $$$\n");

    printw("| $$      ");
    attron(COLOR_PAIR(4)); //bleu
    printw("| $$  | $$");
    attron(COLOR_PAIR(5)); //rouge
    printw("|  $$$$$$/      ");
    attron(COLOR_PAIR(4)); //bleu
    printw("| $$ \\/  | $$");
    attron(COLOR_PAIR(3)); //vert
    printw("| $$  | $$");
    attron(COLOR_PAIR(2)); //jaune
    printw("| $$ \\  $$\n");

    printw("|__/      ");
    attron(COLOR_PAIR(4)); //bleu
    printw("|__/  |__/ ");
    attron(COLOR_PAIR(5)); //rouge
    printw("\\______/       ");
    attron(COLOR_PAIR(4)); //bleu
    printw("|__/     |__/");
    attron(COLOR_PAIR(3)); //vert
    printw("|__/  |__/");
    attron(COLOR_PAIR(2)); //jaune
    printw("|__/  \\__/\n");

    attron(COLOR_PAIR(1)); //blanc
    printw("                                       Par Paul TREHIOU et Victor SENE\n");

    printw("\n\n\n");
    attron(COLOR_PAIR(2)); //jaune
    printw("                          1.JOUER\n\n");
    printw("                          2.MEILLEURS SCORES\n\n");
    printw("                          3.QUITTER\n\n");

    do
    {
        saisie = getch();

    }while((saisie>'3') || (saisie<'1'));

    *entree = saisie - 48;


}
