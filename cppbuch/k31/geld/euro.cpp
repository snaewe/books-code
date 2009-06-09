/* cppbuch/k31/geld/euro.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <locale>
#include <string>
#include"Geld.h"

typedef std::moneypunct_byname<char,true> MeinMoneypunct; // true für Internationalisierung

class MeinWaehrungsformat : public MeinMoneypunct  {
protected:
   // Überschreiben der virtuellen Funktion {\tt do\_curr\_symbol()}, die von der
   //  {\tt public}-Funktion {\tt curr\_symbol()} der Basisklasse {\tt moneypunct} gerufen wird:
   std::string do_curr_symbol() const { 
      return wsymbol;
   }
public:
   MeinWaehrungsformat(const std::locale& loc, const char* ws) 
      : MeinMoneypunct(loc.name().c_str()), wsymbol(ws) {
   } 
private:
   const char* wsymbol;
};

using namespace std;

int main() { 
   locale locUS("en_US");
   Geld derBetrag;
   cout << "Eingabe in Cent(!), z.B. 123456:?";
   cin >> derBetrag;
   cout << "direkte Abfrage mit voreingestellter locale (" 
        << locale().name() << ") :"
        << derBetrag.getBetrag() << endl;                            // 123456
   cout.imbue(locUS);        // cout auf enUS umschalten
   cout << "Es wurde " << derBetrag << " eingegeben (US-Format).\n"; // USD 1,234.56
   locale deDEeuro("de_DE@euro");
   cout   << "Ausgabe Standard-Währungssymbol EUR und Dezimalkomma statt -punkt :" << endl;
   // Achtung: KEINE Währungsumrechnung!
   cout.imbue(deDEeuro);        // cout auf deDE@euro umschalten
   cout << derBetrag << endl;                            // 1.234,56 EUR
   MeinWaehrungsformat* mwptr = new MeinWaehrungsformat(deDEeuro, "\xA4"); // ISO-8859-15
   cout   << "Ausgabe eigenes Währungssymbol \xA4 und Dezimalkomma statt -punkt :" << endl;
   cout.imbue(locale(deDEeuro, mwptr));
   cout << derBetrag << endl;                            // 1.234,56 \euro
}
