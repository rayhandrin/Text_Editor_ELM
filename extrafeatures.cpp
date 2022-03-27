#include "setCursorPosition.h"
#include "extrafeatures.h"
#include "inputhandling.h"

#include <cstdio>
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

/* Aldrin */
void show_working_line(short int *current_element_line)
{
    printf("%2d |  ", *current_element_line);
}

/* Adilla */
void line_column_indicator(short int *indicator_column, short int *indicator_line, short int *element_column, short int *element_line)
{
    setCursorPosition(*indicator_column, *indicator_line);
    printf("Ln %2d, Col %2d", *element_line, *element_column);
    setCursorPosition((*element_column + 6), (*element_line + 9));
}

/* Devina */
int word_counter(char myCanvas[][80], int lineMaximum, int columnMaximum)
{
    bool wordEnd = false;
    int line,
        column,
        charRead = 0,
        wordCounted = 0;

    for (line = 0; line < lineMaximum; line++)
    {
        for (column = 0; column < columnMaximum; column++)
        {
            if (myCanvas[line][column] == ' ' || myCanvas[line][column] == 0x0d || myCanvas[line][column] == '\t') /* 0x0d = Line Feed */
            {
                wordEnd = true;
                if (charRead > 1 && wordEnd == true)
                {
                    wordCounted++;
                    wordEnd = false;
                }
                charRead = 0;
            }
            else
            {
                charRead++;
            }
        }
    }

    return wordCounted;
}

/* Rofi */
int char_counter(char myCanvas[][80], int lineMaximum, int columnMaximum)
{
    int charCounted = 0;
    int line, column;

    for (line = 0; line < lineMaximum; line++)
    {
        for (column = 0; columnMaximum < 10; column++)
        {
            if ((myCanvas[line][column] >= 32 && myCanvas[line][column] <= 122) || myCanvas[line][column] == 9 || myCanvas[line][column] == 0x0a)
            {
                charCounted++;
            }
        }
    }

    return charCounted;
}

/* Rofi */
void upperRibbon(short int *element_column, short int *element_line)
{
    printf("[NEW FILE] - Unsaved\n");
    printf("\n");
    printf("Shortcut:\n");
    printf("CTRL + G = Cursor Mode | CTRL + O = Open File        | CTRL + S = Save File\n");
    printf("CTRL + \\ = Save As     | CTRL + U = Quit Text Editor | CTRL + F = Find [!]\n");
    printf("[!] = belum dipasang\n");
    printf("\n");
    printf("Ln %2d, Col %2d ======================================================================\n\n", *element_line, *element_column);
}

/* Fatur */
int splashScreen()
{
    int a = 0;
    cout << "\t\t\t"
         << "ELM TEXT EDITOR" << endl
         << "\t\t\t      "
         << "v0.5";

    for (int s = 2;; s--)
    {
        if (s == 0)
        {
            break;
        }
        Sleep(1000);
    }
    system("cls");

    return a;
}
