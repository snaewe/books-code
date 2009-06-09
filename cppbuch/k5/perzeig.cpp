/* cppbuch/k5/perzeig.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

void upcase(char *);     // Prototyp

int main( ) {
    char str[] = "gross 123";
    cout << str << endl;
    upcase(str);
    cout << str << endl;  // GROSS 123
}

void upcase(char* s) {
   // In der ASCII-Tabelle sind die Platznummern der
   // Kleinbuchstaben um 'a'-'A' = 32 gegenüber den
   // Großbuchstaben verschoben.
   const int DIFFERENZ = 'a' - 'A';

   while(*s) {
      if (*s >= 'a' && *s <= 'z') {
         *s -= DIFFERENZ;
      }
      else {
         switch(*s) {
         // Lesbar, aber nicht auf jedem System:  Umlaute sind nicht portabel
         // Weitere Informationen finden Sie im Teil 5, Kapitel "Nationale Besonderheiten"
         case 'ä' : *s = 'Ä'; break;
         case 'ö' : *s = 'Ö'; break;
         case 'ü' : *s = 'Ü'; break;
         default:;
         }
      }
      ++s;
   }
}
