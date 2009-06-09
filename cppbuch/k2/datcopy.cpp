/* cppbuch/k2/datcopy.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<string>
#include<cstdlib> // für exit( )
#include<fstream>
#include<iostream>

using namespace std;

int main( ) {
    // Definieren der Eingangsdatei
    ifstream quelle;            // Datentyp für Eingabestrom 
    string quelldateiname;
    cout << "Quelldatei? ";
    cin >> quelldateiname;

    // Datei öffnen:
    // nicht portabel: quelle.open(quelldateiname.c_str());
    quelle.open(quelldateiname.c_str(), ios::binary|ios::in);
    //quelle.open(quelldateiname, ios::binary|ios::in); // neuer Standard
    // Ohne {\tt ios::binary} sind nur Textdateien kopierbar
    // (gilt nur für MSDOS/Windows)

    if (!quelle) {   // Fehlerabfrage
        cerr << quelldateiname
             << " kann nicht geöffnet werden!\n";
        exit(-1);
    }

    string zieldateiname;
    cout << "Zieldatei? ";
    cin >> zieldateiname;
    // Definieren und Öffnen der Ausgabedatei hier in einem Schritt
    // nicht portabel: ofstream ziel(zieldateiname.c_str());
    ofstream ziel(zieldateiname.c_str(),ios::binary|ios::out);
    if (!ziel) {     // Fehlerabfrage
        cerr << zieldateiname
             << " kann nicht geöffnet werden!\n";
        exit(-1);
    }

    char ch;
    while (quelle.get(ch))
           ziel.put(ch); // zeichenweise kopieren
}  // Dateien werden am Programmende automatisch geschlossen.
