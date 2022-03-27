#ifndef arrayutils_H
#define arrayutils_H

void clear_1d_array(short int *array_param);

void clear_2d_array(char *array_param);

void geser_array_ke_depan(short int *access_column, short int *access_line, short int *element_column, short int *element_line, char *main_Board);

void geser_array_ke_belakang(short int *access_column, short int *access_line, short int *element_column, short int *element_line, char *main_Board);

#endif