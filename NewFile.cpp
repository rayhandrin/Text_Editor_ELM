#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

void NewFile();
int main () {
	NewFile();
}

void NewFile() {
  
	  std::ofstream outfile ("untitled.txt");

    outfile << " " << std::endl;

    outfile.close();
	}
	
