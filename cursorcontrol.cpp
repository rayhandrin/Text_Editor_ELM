#include "setCursorPosition.h"
#include "cursorcontrol.h"

/* Geser kursor ke atas */
bool is_move_cursor_up(char input_buffer)
{
    if (input_buffer == 'I')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void move_cursor_up(short int *cursor_column, short int *cursor_line, short int *column_memory)
{
    if (*cursor_line <= 9)
    {
        *cursor_line = 9;
        setCursorPosition(*cursor_column, *cursor_line);
    }
    else if (*cursor_line > 9)
    {
        if (*cursor_column >= column_memory[(*cursor_line - 9) - 1])
        {
            *cursor_line -= 1;
            *cursor_column = column_memory[*cursor_line] + 6;
            setCursorPosition(*cursor_column, *cursor_line);
        }
        else if (*cursor_column < column_memory[(*cursor_line - 9) - 1])
        {
            *cursor_line -= 1;
            setCursorPosition(*cursor_column, *cursor_line);
        }
    }
}
/* END Geser kursor ke atas */

/** Geser kursor ke bawah **/
bool is_move_cursor_down(char input_buffer)
{
    if (input_buffer == 'K')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void move_cursor_down(short int *cursor_column, short int *cursor_line, short int *column_memory, short int *line_maximum)
{
    if ((*cursor_line - 9) == *line_maximum)
    {
        setCursorPosition(*cursor_column, *cursor_line);
    }
    else if ((*cursor_line - 9) < *line_maximum)
    {
        if ((*cursor_column - 6) > column_memory[(*cursor_line - 9) + 1])
        {
            *cursor_line += 1;
            *cursor_column = column_memory[*cursor_line - 9] + 6;
            setCursorPosition(*cursor_column, *cursor_line);
        }
        else if ((*cursor_column - 6) <= column_memory[(*cursor_line - 9) + 1])
        {
            *cursor_line += 1;
            setCursorPosition(*cursor_column, *cursor_line);
        }
    }
}
/* END Geser kursor ke bawah */

/** Geser kursor ke kiri **/
bool is_move_cursor_left(char input_buffer)
{
    if (input_buffer == 'J')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void move_cursor_left(short int *cursor_column, short int *cursor_line, short int *column_memory)
{
    if (*cursor_column == 6)
    {
        if (*cursor_line > 9)
        {
            *cursor_line -= 1;
            *cursor_column = column_memory[*cursor_line - 9] + 6;
            setCursorPosition(*cursor_column, *cursor_line);
        }
        else if (*cursor_line == 9)
        {
            *cursor_column = 6;
            setCursorPosition(*cursor_column, *cursor_line);
        }
    }
    else if (*cursor_column >= 6)
    {
        *cursor_column -= 1;
        setCursorPosition(*cursor_column, *cursor_line);
    }
}

/** Geser kursor ke kanan **/
bool is_move_cursor_right(char input_buffer)
{
    if (input_buffer == 'L')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void move_cursor_right(short int *cursor_column, short int *cursor_line, short int *column_memory, short int *maximum_line)
{
    if ((*cursor_column - 6) == column_memory[*cursor_line - 9])
    {
        if ((*cursor_line - 9) < *maximum_line)
        {
            *cursor_line += 1;
            *cursor_column = 6;
            setCursorPosition(*cursor_column, *cursor_line);
        }
        else if ((*cursor_line - 9) == *maximum_line)
        {
            setCursorPosition(*cursor_column, *cursor_line);
        }
    }
    else if ((*cursor_column - 6) < column_memory[*cursor_line - 9])
    {
        *cursor_column += 1;
        setCursorPosition(*cursor_column, *cursor_line);
    }
}

/* Geser kursor ke awal teks */
bool is_begining_of_text(char input_buffer)
{
    if (input_buffer == 'N')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void begining_of_text(short int *cursor_column, short int *cursor_line)
{
    *cursor_column = 6;
    *cursor_line = 9;
    setCursorPosition(*cursor_column, *cursor_line);
}

/* Geser kursor ke akhir teks */
bool is_end_of_text(char input_buffer)
{
    if (input_buffer == 'M')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void end_of_text(short int *cursor_column, short int *cursor_line, short int *column_memory, short int *line_maximum)
{
    *cursor_column = column_memory[*line_maximum] + 6;
    *cursor_line = *line_maximum + 9;
    setCursorPosition(*cursor_column, *cursor_line);
}

/* Geser kursor ke awal baris */
bool is_begining_of_line(char input_buffer)
{
    if (input_buffer == 'O')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void begining_of_line(short int *cursor_column, short int *cursor_line)
{
    *cursor_column = 6;
    setCursorPosition(*cursor_column, *cursor_line);
}

/* Geser kursor ke akhir baris */
bool is_end_of_line(char input_buffer)
{
    if (input_buffer == 'P')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void end_of_line(short int *cursor_column, short int *cursor_line, short int *column_memory)
{
    *cursor_column = column_memory[*cursor_line - 9] + 6;
    setCursorPosition(*cursor_column, *cursor_line);
}

/* Keluar mode cursor */
void stop_cursor(short int *element_column, short *element_line, short int *cursor_column, short int *cursor_line, bool *cursor_mode)
{
    *element_line = *cursor_line - 9;
    *element_column = *cursor_column - 6;
    *cursor_mode = true;
}

/* Baris terakhir maksimal */
void maximum_line_picker(short int *element_line, short int *line_memory, short int *maximum_line)
{
    if (*element_line <= *line_memory)
    {
        *maximum_line = *line_memory;
    }
    else if (*element_line > *line_memory)
    {
        *maximum_line = *line_memory;
    }
}

/* Reset nilai cursor ke default */
void reset_all_curvars_to_default(short int *cursor_column, short int *cursor_line, bool *cursor_mode)
{
    *cursor_mode = false;
    *cursor_column = 6;
    *cursor_line = 9;
}
