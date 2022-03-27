#ifndef helpFile_H
#define helpFile_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* Devina */
void OpenFile(string fileName)
{
    fstream myFile;
    myFile.open(fileName);
    string line;

    // read file
    if (!myFile.is_open())
    {
        cout << "file cannot be found";
        exit(1);
    }
    while (getline(myFile, line))
    {
        cout << line << endl;
    }
    myFile.close();
}
/* Devina */
void helpFile()
{
    OpenFile("help.txt");
}

#endif