#ifndef save_hpp
#define save_hpp

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

/* Fatur */
bool isFileSaveExist(char *fileName)
{
    fstream myFile;
    myFile.open(fileName, ios::in);
    if (myFile)
    {
        return false;
    }
    else
    {
        return true;
    }
    myFile.close();
}

/* Devina */
void saveFile(char *fileName, int arrayColumn[], char arrayMain[40][80], short int line)
{
    int i, j;
    bool check = isFileSaveExist(fileName);
    FILE *myFile;
    if (check == true)
    {
        myFile = fopen(fileName, "wt");
        for (i = 0; i <= line; i++)
        {
            for (j = 0; j <= arrayColumn[i]; j++)
            {
                fprintf(myFile, "%c", arrayMain[i][j]);
            }
        }
    }
    else if (check == false)
    {
        cout << "File sudah ada silahkan untuk memasukkan kembali nama file : ";
    }
}

#endif