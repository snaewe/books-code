/* cppbuch/k24/textverarbeitung/crossref.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<cctype>
#include<fstream>
#include<iostream>
#include<set>
#include<locale>
#include<map>
#include<string>
#include<showSequence.h>

// Um eine unterschiedliche Sortierung für Groß- und Kleinschreibung
// zu vermeiden, wird die Klasse \tt{Vergleich} eingesetzt, die die zu
// vergleichenden Strings vorher auf Kleinschreibung normiert.

struct Vergleich {
   bool operator()(std::string a, std::string b) const { // per Wert
      for(size_t i=0; i< a.length(); ++i) a[i]=std::tolower(a[i]);
      for(size_t i=0; i< b.length(); ++i) b[i]=std::tolower(b[i]);
      return a < b;  // Stringvergleich berücksichtigt Locale
   }
};

using namespace std;
int main(int argc, char* argv[]) {
   ifstream quelle(argv[1]);
   if(argc < 2 || !quelle.good()) {
      if(!quelle.good()) {
         cout << argv[1] << " nicht gefunden!\n";
      }
      cout << "Gebrauch: " << argv[0] << " Dateiname [locale]\n"
         " Beispiele (vorgegebene Locale: C)\n"
           << argv[0] << " crossref.cpp de_DE\n"
           << argv[0] << " crossref.cpp" << endl;
      return 1;
   }

   if(argc == 3) {
      locale::global(locale(argv[2])); // ggf. global setzen
   }
   // Test für Locale: Mucke Mücke Süßholz Süsse
   typedef map<string, set<int>, Vergleich> BezeichnerZeilenMap;
   BezeichnerZeilenMap bezeichnerZeilenMap;

   int zeilennr = 1;
   while(quelle.good()) {
      char c = '\0';
      // Anfang des Bezeichners finden
      while(quelle.good() && !(isalpha(c) || '_' == c)) {
         quelle.get(c);
         if(c == '\n') {
            ++zeilennr;
         }
      }
      if(quelle.good()) {
         string bezeichner(1,c);
         // Rest des Bezeichners einsammeln
         while(quelle.good() && (isalnum(c) || '_' == c)) {
            quelle.get(c);
            if(isalnum(c) || '_' == c)
               bezeichner += c;
         }
         quelle.putback(c);   // zurück an den Eingabestrom
         if(c) {   // Bezeichner gefunden?
            bezeichnerZeilenMap[bezeichner].insert(zeilennr);  // Eintrag
         }
      }
   } 
   BezeichnerZeilenMap::const_iterator iter = bezeichnerZeilenMap.begin();
   while(iter != bezeichnerZeilenMap.end()) {
      cout << (*iter).first;           // Bezeichner
      cout.width(20 - (*iter).first.length()); // Position bis : einstellen
      cout << ": ";
      showSequence((*iter++).second);  // Zeilennummern
   }
}
