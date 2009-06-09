/* cppbuch/loesungen/k2/4.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
//  Datei-Statistik
#include<iostream>
#include<cstdlib> // für exit()
#include<fstream>
#include<string>
using namespace std;

int main() {
    ifstream quelle;
    cout << "Dateiname :";
    string Quelldateiname;
    cin >> Quelldateiname;
    quelle.open(Quelldateiname.c_str());
    if (!quelle) {   // muss existieren
        cerr << Quelldateiname
             << " kann nicht geöffnet werden!\n";
         exit(-1);
    }

    char c;
    unsigned long zeichenzahl = 0, wortzahl = 0, zeilenzahl = 0;
    bool wort = false;

    while (quelle.get(c)) {
       if (c == '\n')  {
          ++zeilenzahl;
       }
       else {
          ++zeichenzahl;
       }
       // Anpassung auf Umlaute fehlt noch!
       if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
          wort = true;  // Wortanfang, oder {\tt c} ist in einem Wort
       }
       else {
          if(wort) {
             ++wortzahl; // Wortende überschritten
          }
          wort = false;
       }
    }
    cout << "Anzahl der Zeichen (ohne Zeilenendekennung) = " << zeichenzahl << endl;
    cout << "Anzahl der Worte   = " << wortzahl    << endl;
    cout << "Anzahl der Zeilen  = " << zeilenzahl  << endl;
}
