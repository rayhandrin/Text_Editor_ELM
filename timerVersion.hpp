#ifndef timerVersion_hpp
#define timerVersion_hpp
#include <iostream>
#include <windows.h>

using namespace std;
/* Fatur */
int splashScreen()
{
    int a = 0;
    cout << "\t\t\t"
         << "ELM TEXT EDITOR" << endl
         << "\t\t\t\t"
         << "v0.1";

    for (int s = 2;; s--)
    {
        if (s == 0)
        {
            break;
        }
        Sleep(1000);
    }
    system("cls");
    
    return a;
}

#endif