#include <windows.h>

//Fonction utilisant les API Windows afin de dimentionner la fenêtre

void SetWindow(int Largeur, int Hauteur)
{
    SMALL_RECT Rect; //On crée une variable définissant un rectangle puis on l'initialise
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Hauteur - 1;
    Rect.Right = Largeur - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      //On récupère plusieurs informations sur l'état actuel de la fenêtre

    SetConsoleWindowInfo(Handle, TRUE, &Rect);            //On applique la taille du rectangle à la fenêtre
}
