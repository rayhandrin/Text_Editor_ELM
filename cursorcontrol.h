#ifndef cursorcontrol_H
#define cursorcontrol_H

/* Geser kursor ke atas */
bool is_move_cursor_up(char input_buffer);

void move_cursor_up(short int *cursor_column, short int *cursor_line, short int *column_memory);

/* Geser kursor ke bawah */
bool is_move_cursor_down(char input_buffer);

void move_cursor_down(short int *cursor_column, short int *cursor_line, short int *column_memory, short int *line_maximum);

/* Geser kursor ke kiri */
bool is_move_cursor_left(char input_buffer);

void move_cursor_left(short int *cursor_column, short int *cursor_line, short int *column_memory);

/* Geser kursor ke kanan */
bool is_move_cursor_right(char input_buffer);

void move_cursor_right(short int *cursor_column, short int *cursor_line, short int *column_memory, short int *maximum_line);

/* Geser kursor ke awal teks */
bool is_begining_of_text(char input_buffer);

void begining_of_text(short int *cursor_column, short int *cursor_line);

/* Geser kursor ke akhir teks */
bool is_end_of_text(char input_buffer);

void end_of_text(short int *cursor_column, short int *cursor_line, short int *column_memory, short int *line_maximum);

/* Geser kursor ke awal baris */
bool is_begining_of_line(char input_buffer);

void begining_of_line(short int *cursor_column, short int *cursor_line);

/* Geser kursor ke akhir baris */
bool is_end_of_line(char input_buffer);

void end_of_line(short int *cursor_column, short int *cursor_line, short int *column_memory);

/* Keluar mode cursor */
void stop_cursor(short int *element_column, short *element_line, short int *cursor_column, short int *cursor_line, bool *cursor_mode);

/* Baris terakhir maksimal */
void maximum_line_picker(short int *element_line, short int *line_memory, short int *maximum_line);

/* Reset nilai cursor ke default */
void reset_all_curvars_to_default(short int *cursor_column, short int *cursor_line, bool *cursor_mode);

#endif

