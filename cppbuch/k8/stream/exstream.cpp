/* cppbuch/k8/stream/exstream.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;  

class DateiEnde : public exception {};       // Hilfsklasse (siehe unten)

int liesZahl(std::istream& ein) throw(DateiEnde, const char*) {
    int i;
    ein >> i;

    if (ein.eof())  throw DateiEnde();
    if (ein.fail()) throw  "Syntaxfehler";
    if (ein.bad())  throw;           // nicht behebbarer Fehler
    return i;
} // {\tt liesZahl()}

void zahlen_lesen_und_ausgeben() {
    int zahl;
    while(true) {
        cout << "Zahl eingeben: ";

        bool erfolgreich = true;
        // Versuchsblock
        try {
              //  Zahl von der Standardeingabe lesen:
              zahl = liesZahl(cin);
        }

        // Fehlerbehandlung
        catch (const DateiEnde& e) {
             cout << "Ende der Datei erreicht!\n" 
                  << "e.what() liefert: " << e.what() << endl;
             cin.clear();    // Fehlerbits rücksetzen
             break;          // Schleife verlassen
        }

        catch(const char* z) {
             cerr << z << endl;
             erfolgreich = false;
             cin.clear();         // Fehlerbits rücksetzen
             cin.get();           // fehlerhaftes Zeichen entfernen
        }

        // Fortsetzung des Programms nach der Fehlerbehandlung
        if (erfolgreich)
            cout << "Zahl =  " << zahl << endl;
    }
}

int main() {
    zahlen_lesen_und_ausgeben();
}


