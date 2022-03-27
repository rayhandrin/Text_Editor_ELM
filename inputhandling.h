#ifndef inputhandling_H
#define inputhandling_H

void setArray(char *myArray, char myInput);

void setLastColumn(short int *myArray, short int myInput);

void resetValue(short int *myVariable);

void resetConsoleCursor(short int *x, short int *y);

bool isStandardChar(char myBuffer);

bool isEnter(char myBuffer);

bool isBackspace(char myBuffer);

bool isTab(char myBuffer);

bool isHelp(char myBuffer);

bool isEndWriting(char myBuffer);

bool isCursor(char myBuffer);

bool isSave(char myBuffer);

bool isSaveAs(char myBuffer);

bool isArrowDown(char myBuffer);

bool isArrowUp(char myBuffer);

bool isArrowLeft(char myBuffer);

bool isArrowRight(char myBuffer);

bool isFind(char myBuffer);

bool isOpen(char myBuffer);

void backspace_kondisi1(short int *element_column, short int *element_line, char *main_Board);

void backspace_kondisi2(short int *element_column, short int *element_line, char *main_Board, short int *column_memory, short int *indicator_column, short int *indicator_line);

void backspace_kondisi3(short int *element_column, short int *element_line, char *main_Board, short int *column_memory, short int *indicator_column, short int *indicator_line, short int *maximumLine);

void standard_input_kondisi1(char *input_buffer, short int *access_column, short int *access_line, short int *element_column, short int *element_line, short int *elementIndicator_column, short int *elementIndicator_line, char *main_board, short int *column_memory, short int *max_line);

void standard_input_kondisi2(char *input_buffer, short int *access_column, short int *access_line, short int *element_column, short int *element_line, short int *elementIndicator_column, short int *elementIndicator_line, char *main_board, short int *column_memory, short int *line_memory, short int *max_line);

void standard_input_kondisi3(char *main_board, char *input_buffer, short int *element_line, short int *element_column, short int *column_memory);

#endif 