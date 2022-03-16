#ifndef deleteFile_hpp
#define deleteFile_hpp
#include <cstdio>
#include <iostream>
using namespace std;

/* Devina */
void deleteFile(char *fileName)
{
    int status;

    status = remove(fileName);

    if (status == 0)
    {
        cout << endl
             << "File deleted successfully!";
    }
    else
    {
        cout << endl
             << "File deletion failed!";
    }
    cout << endl;
}

#endif