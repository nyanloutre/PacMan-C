#include <stdio.h>
#include <stdlib.h>

void menu(int *entree)
{
    char saisie;

    system("CLS");

    printw("\n");

    textcolor(14);
    printw(" /$$$$$$$   ");
    textcolor(9);
    printw("/$$$$$$   ");
    textcolor(12);
    printw("/$$$$$$        ");
    textcolor(11);
    printw("/$$      /$$  ");
    textcolor(10);
    printw("/$$$$$$  ");
    textcolor(14);
    printw("/$$   /$$\n");


    printw("| $$__  $$ ");
    textcolor(9);
    printw("/$$__  $$ ");
    textcolor(12);
    printw("/$$__  $$      ");
    textcolor(11);
    printw("| $$$    /$$$");
    textcolor(10);
    printw(" /$$__  $$");
    textcolor(14);
    printw("| $$$ | $$\n");


    printw("| $$  \\ $$");
    textcolor(9);
    printw("| $$  \\ $$");
    textcolor(12);
    printw("| $$  \\__/      ");
    textcolor(11);
    printw("| $$$$  /$$$$");
    textcolor(10);
    printw("| $$  \\ $$");
    textcolor(14);
    printw("| $$$$| $$\n");


    printw("| $$$$$$$/");
    textcolor(9);
    printw("| $$$$$$$$");
    textcolor(12);
    printw("| $$            ");
    textcolor(11);
    printw("| $$ $$/$$ $$");
    textcolor(10);
    printw("| $$$$$$$$");
    textcolor(14);
    printw("| $$ $$ $$\n");


    printw("| $$____/ ");
    textcolor(9);
    printw("| $$__  $$");
    textcolor(12);
    printw("| $$            ");
    textcolor(11);
    printw("| $$  $$$| $$");
    textcolor(10);
    printw("| $$__  $$");
    textcolor(14);
    printw("| $$  $$$$\n");

    printw("| $$      ");
    textcolor(9);
    printw("| $$  | $$");
    textcolor(12);
    printw("| $$    $$      ");
    textcolor(11);
    printw("| $$\\  $ | $$");
    textcolor(10);
    printw("| $$  | $$");
    textcolor(14);
    printw("| $$\\  $$$\n");

    printw("| $$      ");
    textcolor(9);
    printw("| $$  | $$");
    textcolor(12);
    printw("|  $$$$$$/      ");
    textcolor(11);
    printw("| $$ \\/  | $$");
    textcolor(10);
    printw("| $$  | $$");
    textcolor(14);
    printw("| $$ \\  $$\n");

    printw("|__/      ");
    textcolor(9);
    printw("|__/  |__/ ");
    textcolor(12);
    printw("\\______/       ");
    textcolor(11);
    printw("|__/     |__/");
    textcolor(10);
    printw("|__/  |__/");
    textcolor(14);
    printw("|__/  \\__/\n");

    textcolor(15);
    printw("                                       Par Paul TREHIOU et Victor SENE\n");

    printw("\n\n\n");
    textcolor(14);
    printw("                          1.JOUER\n\n");
    printw("                          2.MEILLEURS SCORES\n\n");
    printw("                          3.QUITTER\n\n");

    do
    {
        saisie = getch();

    }while((saisie>'3') || (saisie<'1'));

    *entree = saisie - 48;


}
