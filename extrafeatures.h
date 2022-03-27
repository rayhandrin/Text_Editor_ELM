#ifndef extrafeatures_H
#define extrafeatures_H

void show_working_line(short int *current_element_line);

int word_counter(char myCanvas[][80], int lineMaximum, int columnMaximum);

int char_counter(char myCanvas[][80], int lineMaximum, int columnMaximum);

void line_column_indicator(short int *indicator_column, short int *indicator_line, short int *element_column, short int *element_line);

void upperRibbon(short int *element_column, short int *element_line);

int splashScreen();

#endif