#include <windows.h>

void SetWindow(int Largeur, int Hauteur)
{
    SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Hauteur - 1;
    Rect.Right = Largeur - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle

    SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
}
