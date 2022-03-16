#ifndef saveAs_HPP
#define saveAs_HPP

#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

/* Fatur */
void saveAsFile(char *destinationFilename, char *sourceFilename)
{
    fstream sourceFile;
    sourceFile.open(sourceFilename, ios::in);
    fstream destinationFile;
    destinationFile.open(destinationFilename, ios::out);

    int i, j;
    string charBuffer;

    while (getline(sourceFile, charBuffer))
    {
        destinationFile << charBuffer << endl;
    }

    sourceFile.close();
    destinationFile.close();
}

#endif