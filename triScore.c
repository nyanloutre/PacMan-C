void triScore(char *pseudo[100], int score[100])
{
    int i, j=0, new_score;
    char *new_pseudo, *temp_pseudo;
    for (i = 1; i < 100; i++)
    {
        new_score = score[i];
        new_pseudo = pseudo[i];
        j=i;
        while (j > 0 && score[j-1] > new_score)
        {
            score[j] = score[j-1];
            temp_pseudo = pseudo[j-1];
            pseudo[j] = temp_pseudo;
            j--;
        }
        score[j] = new_score;
        pseudo[j] = new_pseudo;
    }
    printf("Le meilleur score est %d detenu par %s\n", score[99], pseudo[99]);

}
