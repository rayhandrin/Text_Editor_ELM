/* Nama modul   : showFolder                                 */
/* Fungsi       : Modul ini berfungsi untuk memunculkan nama file dari direktori yang dipilih   */
/* Nama pembuat : M. Fatur Maulidan Azzahra(211511020)       */
/* Kelas        : 1A/D3 Teknik Informatika                   */
#ifndef showFolder_H
#define showFolder_H

#include <dirent.h>
#include <conio.h>
#include <sys\stat.h>
#include <iostream>

using namespace std;
/* Fatur */
void showFolder()
{
    struct dirent *d;
    struct stat dst;

    cout << "You are here" << endl;
    cout << "";

    DIR *dr;
    string path = ".\\";

    dr = opendir(path.c_str());
    if (dr != NULL)
    {
        for (d = readdir(dr); d != NULL; d = readdir(dr))
        {
            string type = d->d_name;
            type = path + type;

            if (stat(type.c_str(), &dst) == 0)
            {
                if (dst.st_mode & S_IFDIR)
                {
                    type = "is a Folder";
                }
                else if (dst.st_mode & S_IFREG)
                {
                    type = "is a File";
                }
            }
            cout << d->d_name << endl;
        }
        closedir(dr);
    }
    else
    {
        cout << "error";
    }
    getch();
}

#endif