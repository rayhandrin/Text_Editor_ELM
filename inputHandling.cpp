#include "extrafeatures.h"
#include "arrayutils.h"
#include "inputhandling.h"
#include "setCursorPosition.h"

#include <stdio.h>

/* DESKRIPSI FUNGSI */

/* Aldrin */
void setArray(char *myArray, char myInput)
{
    *myArray = myInput;
}

/* Aldrin */
void setLastColumn(short int *myArray, short int myInput)
{
    *myArray = myInput;
}

/* Aldrin */
void resetValue(short int *myVariable)
{
    *myVariable = 0;
}

/* Adilla */
void resetConsoleCursor(short int *x, short int *y)
{
    *x = 0;
    *y = 0;
}

/* Adilla */
bool isStandardChar(char myBuffer)
{
    if (myBuffer >= 32 && myBuffer <= 126)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Devina */
bool isEnter(char myBuffer)
{
    if (myBuffer == 0x0d)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Devina */
bool isBackspace(char myBuffer)
{
    if (myBuffer == 0x08)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Devina */
bool isTab(char myBuffer)
{
    if (myBuffer == 0x09)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Adilla */
bool isHelp(char myBuffer)
{
    if (myBuffer == 0x02)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Adilla */
bool isEndWriting(char myBuffer)
{
    if (myBuffer == 0x15)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Adilla */
bool isCursor(char myBuffer)
{
    if (myBuffer == 0x07)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Adilla */
bool isSave(char myBuffer)
{
    if (myBuffer == 0x13)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Fatur */
bool isSaveAs(char myBuffer)
{
    if (myBuffer == 0x1C) /* CTRL + \ */
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Rofi */
bool isArrowDown(char myBuffer)
{
    if (myBuffer == 0x50)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Rofi */
bool isArrowUp(char myBuffer)
{
    if (myBuffer == 0x48)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Rofi */
bool isArrowLeft(char myBuffer)
{
    if (myBuffer == 0x4B)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Rofi */
bool isArrowRight(char myBuffer)
{
    if (myBuffer == 0x4D)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Aldrin */
bool isFind(char myBuffer)
{
    if (myBuffer == 0x6)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Adilla */
bool isOpen(char myBuffer)
{
    if (myBuffer == 0xF)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void backspace_kondisi1(short int *element_column, short int *element_line, char *main_Board)
{
    /* Posisi kursor menjadi tetap */
    setCursorPosition((*element_column + 6), (*element_line + 9));

    /* Array yang diakses diisi oleh terminating character */
    main_Board[*element_line * 40 + *element_column] = '\0';
}

void backspace_kondisi2(short int *element_column, short int *element_line, char *main_Board, short int *column_memory, short int *indicator_column, short int *indicator_line)
{
    *element_column -= 1;
    *main_Board = '\0';

    /* Update line and column indicator */
    line_column_indicator(&(*indicator_column), &(*indicator_line), &(*element_column), &(*element_line));

    /* Moving cursor back and forth */
    setCursorPosition((*element_column + 7), (*element_line + 9));
    putchar(32);
    setCursorPosition((*element_column + 6), (*element_line + 9));
    putchar(32);
    setCursorPosition((*element_column + 6), (*element_line + 9));

    /* Array column memory decreased */
    *column_memory -= 1;
}

void backspace_kondisi3(short int *element_column, short int *element_line, char *main_Board, short int *column_memory, short int *indicator_column, short int *indicator_line, short int *maximumLine)
{
    printf("\u001b[2K");
    *element_line -= 1;
    *main_Board = '\0';
    *element_column = column_memory[*element_line];
    line_column_indicator(&(*indicator_column), &(*indicator_line), &(*element_column), &(*element_line));
    *maximumLine -= 1;
}

void standard_input_kondisi1(char *input_buffer, short int *access_column, short int *access_line, short int *element_column, short int *element_line, short int *elementIndicator_column, short int *elementIndicator_line, char *main_board, short int *column_memory, short int *max_line)
{
    /* Show the input to user */
    putchar(*input_buffer);

    /* Store the input into array element */
    *main_board = *input_buffer;

    /* Move on element forward after inserting a value into an array element */
    *element_column += 1;

    /* Update line and_column indicator */
    line_column_indicator(&(*elementIndicator_column), &(*elementIndicator_line), &(*element_column), &(*element_line));

    /* Update last_column position with array position */
    column_memory[*element_line] += 1;
}

void standard_input_kondisi2(char *input_buffer, short int *access_column, short int *access_line, short int *element_column, short int *element_line, short int *elementIndicator_column, short int *elementIndicator_line, char *main_board, short int *column_memory, short int *line_memory, short int *max_line)
{
    /* Show the input to user */
    putchar('\n');

    /* Store the input into array element */
    *main_board = '\n';

    /* Reset the value of array element column */
    *element_column = 0;

    /* Add array element line by one */
    *element_line += 1;

    /* Add maximum line by one */
    *max_line += 1;

    /* Show working line */
    show_working_line(element_line);

    /* Update line and column indicator */
    line_column_indicator(&(*elementIndicator_column), &(*elementIndicator_line), &(*element_column), &(*element_line));

    /* Update last column position with array position */
    column_memory[*element_line] += 1;

    /* Update last line memory for cursor positioning need later */
    if (*element_line > *line_memory)
    {
        *line_memory += 1;
    }
    else if (*element_line <= *line_memory)
    {
        *line_memory = *element_line;
    }
}

void standard_input_kondisi3(char *main_board, char *input_buffer, short int *element_line, short int *element_column, short int *column_memory)
{
    if (*main_board != NULL)
    {
        *main_board = *input_buffer;
    }
    else
    {
        *main_board = *input_buffer;
        column_memory[*element_line] = *element_column;
    }
}