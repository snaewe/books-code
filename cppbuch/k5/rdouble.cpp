/* cppbuch/k5/rdouble.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// Lesen einer Datei double.dat mit {\tt double}-Zahlen
#include<cstdlib>
#include<fstream>
#include<iostream>

using namespace std;

int main( ) {
    ifstream quelle;
    quelle.open("double.dat", ios::binary|ios::in);

    if (!quelle)   {// muss existieren
        cerr << "Datei kann nicht geöffnet werden!\n";
        exit(-1);
    }

    double d;
    while (quelle.read(reinterpret_cast<char*>(&d), sizeof(d)))   // lesen
         cout << "  " << d << '\n';
}  // {\tt quelle.close()} wird vom Destruktor durchgeführt
