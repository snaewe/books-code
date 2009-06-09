/* cppbuch/loesungen/k5/8.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<cstring>
using namespace std;

void leerzeichenEntfernen(char* s) {
   char* q = s;
   do  {
      if(*s != ' ') {
         *q++ = *s;
      }
   } while(*s++);
}

int main() {
   char str[] = "Leerzeichen  aus einer    Zeichenkette"
                " entfernen  ";
   cout << str << endl
        << "Länge: " << strlen(str) << endl;
   leerzeichenEntfernen(str);
   cout << str << endl
        << "Länge: " << strlen(str) << endl;
}

