#include "colorfulterminal.h"
#include <stdio.h>
#include <windows.h>

// Green Disp
void green_disp(char ch)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);
    printf("%c", ch);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
}

void yellow_disp(char ch)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN|BACKGROUND_RED);
    printf("%c", ch);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
}

void grey_disp(char ch)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY);
    printf("%c", ch);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
}

void makenormal()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
}