#ifndef mainfunctions_H
#define mainfunctions_H
#include <iostream>
#include <cstdio>

typedef char* infoFile;

using namespace std;

bool is_same_filename_exits(char *filename);

void save_file(short int *arrayColumnMemory, char *array_main, short int maximumLine, char *filename);

void save_as(char *destinationFilename, char *sourceFilename);

void print_save_info();

void print_save_confirmation();

void clear_first_line();

void copy_file(string fileSource, string fileDest);

void delete_file(char *fileName);

void open_file(char *input_Buffer, short int *access_column, short int *access_line, short int *element_column, short int *element_line, short int *indicator_column, short int *indicator_line, char *main_Board, short int *maximum_line, short int *column_memory, char *namaFileOpen, char *namaFileBaru, bool *new_file);

#endif