#ifndef copyFile_hpp
#define copyFile_hpp

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* Devina */
void CopyFile(string fileSource, string fileDest)
{
    ifstream mySource;
    ofstream myDest;

    mySource.open(fileSource);
    string line;

    // read file
    if (!mySource.is_open())
    {
        cout << "File cannot be found!"; // freeze for a moment
        exit(1);                         // ubah
    }
    myDest.open(fileDest);
    while (getline(mySource, line))
    {
        myDest << line << endl;
    }
    cout << endl
         << "File copied successfully!"; // freeze for a moment

    mySource.close();
    myDest.close();
}

#endif