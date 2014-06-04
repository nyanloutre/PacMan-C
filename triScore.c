void triScore(char pseudo[100][4], int score[100], int maxi)
{
    int i, j, new_score;
    char new_pseudo[4], temp_pseudo[4];
    for (i = 1; i < maxi; i++)      // tri score du plus petit au plus grand
    {
        new_score = score[i];
        strcpy(new_pseudo, pseudo[i]);
        j=i;
        while (j > 0 && score[j-1] > new_score)
        {
            score[j] = score[j-1];
            strcpy(pseudo[j], pseudo[j-1]);
            j--;
        }
        score[j] = new_score;
        strcpy(pseudo[j], new_pseudo);
    }
    printf("Le meilleur score est %d detenu par %s\n", score[maxi-1], pseudo[maxi-1]);


    //Affichage tableau des scores
    printf("TOP 10\n");
    printf("\nPseudo\t|\tScore\n");
    printf("----------------------\n");
    for (i=maxi-1; i>=maxi-10;i--)
    {
        printf("%s\t|\t%d\n", pseudo[i], score[i]);
    }

}
