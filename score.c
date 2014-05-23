void fscore(int scorePlayer)
{
    int score[100]={0};
    char name[12];
    char *pseudo[50];

    printf("Votre Pseudo : ");
    gets(name);

    printf("\nVotre score : %d\n", scorePlayer);
    inscriptionScore(name, scorePlayer);
    //lectureScore(pseudo, score);

}
