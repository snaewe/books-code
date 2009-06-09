/* cppbuch/k5/mainpar.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

int main(int argc, char* argv[], char *env[]) {
    cout << "Aufruf des Programms = "
         << argv[0] << endl;

    cout << (argc-1)
         << " weitere Argumente wurden main() übergeben:\n";

    int i = 1;
    while(argv[i]) {
          cout << argv[i++] << endl;
    }

    cout << "\n*** Umgebungs-Variablen: ***\n";
    i = 0;
    while(env[i]) {
          cout << env[i++] << endl;
    }
}
