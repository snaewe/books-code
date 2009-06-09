/* cppbuch/k10/fstream1.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<fstream>
#include<iostream>

using namespace std;

// Benutzen *eines* Datei-Objekts nacheinander zum schreiben und lesen
int main() {
    fstream fileStream;
    int i;

    // schreiben
    fileStream.open("fstream1.dat", ios::out);
    // fileStream << "X" << endl;  // Lesefehler provozieren
    for(i = 0; i < 9; ++i)
      fileStream << i << endl;
    fileStream.close();

    // lesen
    fileStream.open("fstream1.dat", ios::in);
    while(fileStream.good()) {
       fileStream >> i;
       if(fileStream.good())
          cout << i << ' ';
       else
          cout << endl << "Dateiende erreicht oder Lesefehler";
    }
    cout << endl;
}

