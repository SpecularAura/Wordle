#include "colorfulterminal.h"
#include <stdio.h>
#include <windows.h>

// Green Disp
void green_disp(const char* str)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);
    printf("%s", str);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
}

void yellow_disp(const char* str)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN|BACKGROUND_RED);
    printf("%s", str);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
}

void grey_disp(const char* str)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY);
    printf("%s", str);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
}

void makenormal()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
}