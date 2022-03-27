#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <windows.h>

#include "mainfunctions.h"
#include "extrafeatures.h"

using namespace std;

/* Fatur */
bool is_same_filename_exits(char *filename)
{
    /* Kamus Lokal */
    FILE *myFile;
    myFile = fopen(filename, "rt");

    /* Algoritma */
    if (myFile == NULL)
    {
        fclose(myFile);
        return false;
    }
    else
    {
        fclose(myFile);
        return true;
    }
}

/* Adilla */
void save_file(short int *arrayColumnMemory, char *array_main, short int maximumLine, char *filename)
{
    /* Kamus Lokal */
    short int column, line;
    FILE *myFile;

    /* Algoritma */
    myFile = fopen(filename, "wt");

    for (line = 0; line <= maximumLine; line += 1)
    {
        if (line < maximumLine)
        {
            for (column = 0; column <= arrayColumnMemory[line]; column += 1)
            {
                fprintf(myFile, "%c", array_main[line * 80 + column]);
            }
        }
        else if (line == maximumLine)
        {
            for (column = 0; column < arrayColumnMemory[line]; column += 1)
            {
                fprintf(myFile, "%c", array_main[line * 80 + column]);
            }
        }
    }

    fclose(myFile);
}

/* Fatur */
void save_as(char *destinationFilename, char *sourceFilename)
{
    /* Kamus Lokal */
    fstream sourceFile;
    fstream destinationFile;
    string charBuffer;

    /* Algoritma */
    sourceFile.open(sourceFilename, ios::in);
    destinationFile.open(destinationFilename, ios::out);

    while (getline(sourceFile, charBuffer))
    {
        destinationFile << charBuffer << endl;
    }

    sourceFile.close();
    destinationFile.close();
}

/* Devina */
void print_save_info()
{
    /* Kursor pindah ke baris 0 dan kolom 0 */
    printf("\u001b[0;0H");

    /* Baris 0 dibersihkan seluruhnya */
    printf("\u001b[2K");

    /* Mengembalikan posisi kursor ke baris 0   */
    /* menggeser kursor ke atas sebanyak 2 kali */
    printf("\u001b[2A");

    /* Mencetak bagian pengisian nama file baru */
    printf("SAVE - Masukan nama file (termasuk .txt) [                         ]");

    /* Memosisikan kursor supaya berada pada awal kotak (pengisian nama file) */
    printf("\u001b[0;43H");
}

/* Devina */
void print_save_confirmation()
{
    /* Kursor pindah ke baris 0 dan kolom 0 */
    printf("\u001b[0;0H");

    /* Baris 0 dibersihkan seluruhnya */
    printf("\u001b[2K");

    /* Mengembalikan posisi kursor ke baris 0   */
    /* menggeser kursor ke atas sebanyak 2 kali */
    printf("\u001b[2A");

    printf("File dengan nama yang sama ditemukan. Anda yakin akan menimpanya? [ ]");

    /* Mengembalikan posisi kursor 2 kolom ke belakang */
    printf("\u001b[2D");
}

/* Fatur */
void clear_first_line()
{
    /* Kursor pindah ke baris 0 dan kolom 0 */
    printf("\u001b[0;0H");

    /* Baris 0 dibersihkan seluruhnya */
    printf("\u001b[2K");

    /* Mengembalikan posisi kursor ke baris 0   */
    /* menggeser kursor ke atas sebanyak 2 kali */
    printf("\u001b[2A");
}

/* Devina */
void copy_file(string fileSource, string fileDest)
{
    ifstream mySource;
    ofstream myDest;

    mySource.open(fileSource);
    string line;

    if (!mySource.is_open())
    {
        cout << "File cannot be found!" << endl;
        Sleep(1000);
    }
    else
    {
        myDest.open(fileDest);
        while (getline(mySource, line))
        {
            myDest << line << endl;
        }
        cout << endl
             << "File copied successfully!"
			 <<endl;
        Sleep(1000);
    }
    mySource.close();
    myDest.close();

}

/* Devina */
void delete_file(char *fileName)
{
    int status;

    status = remove(fileName);

    if (status == 0)
    {
        cout << endl
             << "File deleted successfully!"
			 << endl;
    }
    else
    {
        cout << endl
             << "File deletion failed!"
			 << endl;
    }
    cout << endl;
}

/* Aldrin */
void open_file(char *input_Buffer, short int *access_column, short int *access_line, short int *element_column, short int *element_line, short int *indicator_column, short int *indicator_line, char *main_Board, short int *maximum_line, short int *column_memory, char *namaFileOpen, char *namaFileBaru, bool *new_file)
{
    FILE *myFile;

    /* Kursor pindah ke baris 0 dan kolom 0 */
    printf("\u001b[0;0H");

    /* Baris 0 dibersihkan seluruhnya */
    printf("\u001b[2K");

    /* Mengembalikan posisi kursor ke baris 0   */
    /* menggeser kursor ke atas sebanyak 2 kali */
    printf("\u001b[2A");

    /* Mencetak bagian pengisian nama file baru */
    printf("OPEN - Masukan nama file (termasuk .txt) [                         ]");

    /* Memosisikan kursor supaya berada pada awal kotak (pengisian nama file) */
    printf("\u001b[0;43H");

    gets(namaFileOpen);

    myFile = fopen(namaFileOpen, "rt+");

    if (myFile == NULL)
    {
        clear_first_line();
        perror("File yang dibuka tidak ada!");
        fclose(myFile);
        Sleep(1000);
        clear_first_line();
        printf("[NEW FILE] - Unsaved\n");

        /* Mengembalikan kursor ke baris 0 */
        printf("\u001b[10;7H");
    }
    else
    {
        /* Agar diperbarui text editor baru kembali */
        system("cls");

        upperRibbon(element_column, element_line);

        /* Show working line */
        show_working_line(element_line);

        clear_first_line();

        /* Mencetak informasi bahwa file sudah disimpan */
        printf("[%20s] - OPENED", namaFileOpen);

        while (!feof(myFile))
        {
            *input_Buffer = fgetc(myFile);
            if (*input_Buffer == '\n')
            {
                main_Board[*element_line * 80 + *element_column] = '\n';
                *maximum_line += 1;
                *element_line += 1;
                *element_column = 0;
            }
            else if (isprint(*input_Buffer))
            {
                main_Board[*element_line * 80 + *element_column] = *input_Buffer;
                *element_column += 1;
                column_memory[*element_line] += 1;
            }
        }

        fclose(myFile);

        /* Mengembalikan kursor ke baris 0 */
        printf("\u001b[10;7H");

        /* Menghapus baris */
        printf("\u001b[2K");

        /* Menggeser cursor ke kiri sebanyak 6 kali */
        printf("\u001b[6D");
        for (*access_line = 0; *access_line <= *maximum_line; *access_line += 1)
        {
            show_working_line(access_line);
            for (*access_column = 0; *access_column <= column_memory[*access_line]; *access_column += 1)
            {
                if (isprint(main_Board[*access_line * 80 + *access_column]))
                {
                    putchar(main_Board[*access_line * 80 + *access_column]);
                }
                else if (main_Board[*access_line * 80 + *access_column] == '\n')
                {
                    putchar('\n');
                }
            }
        }
        line_column_indicator(indicator_column, indicator_line, element_column, element_line);

        /* Nama file yang baru disalin ke variabel save supaya */
        strcpy(namaFileBaru, namaFileOpen);

        *new_file = false;
    }
}
