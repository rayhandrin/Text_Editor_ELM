#include "extrafeatures.h"

/* All of lastColumnMemory's elements will be initialized with  0 */
void clear_1d_array(short int *array_param)
{
    /* Kamus Lokal */
    int element;

    /* Algoritma */
    for (element = 0; element < 40; element += 1)
    {
        array_param[element] = 0;
    }
}

/* All of main_Board's elements will be initialized with  null terminating character \0 */
void clear_2d_array(char *array_param)
{
    /* Kamus Lokal */
    int line, column;

    /* Algoritma */
    for (line = 0; line < 40; line += 1)
    {
        for (column = 0; column < 80; column += 1)
        {
            array_param[line * 80 + column] = '\0';
        }
    }
}

void geser_array_ke_depan(short int *access_column, short int *access_line, short int *element_column, short int *element_line, char *main_Board)
{
    for (*access_line = 0; *access_line < *element_line; *access_line += 1)
    {
        if (*access_line == (*element_line - 1))
        {
            for (*access_column = 0; *access_column < (*element_column - 1); *access_column += 1)
            {
                main_Board[*access_line * 80 + *access_column] = main_Board[*access_line * 80 + (*access_column + 1)];
            }
        }
        else if (*access_line < (*element_line - 1))
        {
            for (*access_column = 0; *access_column < *element_column; *access_column += 1)
            {
                if (*access_column < (*element_column - 1))
                {
                    main_Board[*access_line * 80 + *access_column] = main_Board[*access_line * 80 + (*access_column + 1)];
                }
                else if (*access_column == (*element_column - 1))
                {
                    main_Board[*access_line * 80 + *access_column] = main_Board[(*access_line + 1) * 80 + 79];
                }
            }
        }
    }
}

void geser_array_ke_belakang(short int *access_column, short int *access_line, short int *element_column, short int *element_line, char *main_Board)
{
    for (*access_line = 39; *access_line >= *element_line; *access_line -= 1)
    {
        if (*access_line == *element_line)
        {
            for (*access_column = 79; *access_column > *element_column; *access_column -= 1)
            {
                main_Board[*access_line * 80 + *access_column] = main_Board[*access_line * 80 + (*access_column - 1)];
            }
        }
        else if (*access_line > *element_line)
        {
            for (*access_column = 79; *access_column >= 0; *access_column -= 1)
            {
                if (*access_column > 0)
                {
                    main_Board[*access_line * 80 + *access_column] = main_Board[*access_line * 80 + (*access_column + 1)];
                }
                else if (*access_column == 0)
                {
                    main_Board[*access_line * 80 + *access_column] = main_Board[(*access_line - 1) * 80 + 79];
                }
            }
        }
    }
}
