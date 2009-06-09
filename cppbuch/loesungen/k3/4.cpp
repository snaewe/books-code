/* cppbuch/loesungen/k3/4.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

void str_umkehr(string& s);

int main() {
   cout << "Reihenfolge der Zeichen umdrehen. Eingabe einer Zeichenkette:";
   string str;
   cin >> str;
   str_umkehr(str);
   cout << str << endl;
}

void str_umkehr(string& s) { // dreht die Reihenfolge der Zeichen um
    int links  = 0, rechts = s.length() - 1;
    while(links < rechts) {
         char temp = s[links];
         s[links++] = s[rechts];
         s[rechts--] = temp;
    }
}
