void menu(int *entree)
{

    int lol;

    printf("\n");

    textcolor(14);
    printf(" /$$$$$$$   ");
    textcolor(9);
    printf("/$$$$$$   ");
    textcolor(12);
    printf("/$$$$$$        ");
    textcolor(11);
    printf("/$$      /$$  ");
    textcolor(10);
    printf("/$$$$$$  ");
    textcolor(14);
    printf("/$$   /$$\n");


    printf("| $$__  $$ ");
    textcolor(9);
    printf("/$$__  $$ ");
    textcolor(12);
    printf("/$$__  $$      ");
    textcolor(11);
    printf("| $$$    /$$$");
    textcolor(10);
    printf(" /$$__  $$");
    textcolor(14);
    printf("| $$$ | $$\n");


    printf("| $$  \\ $$");
    textcolor(9);
    printf("| $$  \\ $$");
    textcolor(12);
    printf("| $$  \\__/      ");
    textcolor(11);
    printf("| $$$$  /$$$$");
    textcolor(10);
    printf("| $$  \\ $$");
    textcolor(14);
    printf("| $$$$| $$\n");


    printf("| $$$$$$$/");
    textcolor(9);
    printf("| $$$$$$$$");
    textcolor(12);
    printf("| $$            ");
    textcolor(11);
    printf("| $$ $$/$$ $$");
    textcolor(10);
    printf("| $$$$$$$$");
    textcolor(14);
    printf("| $$ $$ $$\n");


    printf("| $$____/ ");
    textcolor(9);
    printf("| $$__  $$");
    textcolor(12);
    printf("| $$            ");
    textcolor(11);
    printf("| $$  $$$| $$");
    textcolor(10);
    printf("| $$__  $$");
    textcolor(14);
    printf("| $$  $$$$\n");

    printf("| $$      ");
    textcolor(9);
    printf("| $$  | $$");
    textcolor(12);
    printf("| $$    $$      ");
    textcolor(11);
    printf("| $$\\  $ | $$");
    textcolor(10);
    printf("| $$  | $$");
    textcolor(14);
    printf("| $$\\  $$$\n");

    printf("| $$      ");
    textcolor(9);
    printf("| $$  | $$");
    textcolor(12);
    printf("|  $$$$$$/      ");
    textcolor(11);
    printf("| $$ \\/  | $$");
    textcolor(10);
    printf("| $$  | $$");
    textcolor(14);
    printf("| $$ \\  $$\n");

    printf("|__/      ");
    textcolor(9);
    printf("|__/  |__/ ");
    textcolor(12);
    printf("\\______/       ");
    textcolor(11);
    printf("|__/     |__/");
    textcolor(10);
    printf("|__/  |__/");
    textcolor(14);
    printf("|__/  \\__/\n");

    textcolor(15);
    printf("                                       Par Paul TREHIOU et Victor SENE\n");

    printf("\n\n\n");
    textcolor(14);
    printf("                          1.JOUER\n\n");
    printf("                          2.MEILLEURS SCORES\n\n");
    printf("                          3.QUITTER\n\n");

    do
    {
        scanf("%d", entree);
    }while(*entree>3 || *entree<1);


}
