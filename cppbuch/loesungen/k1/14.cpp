/* cppbuch/loesungen/k1/14.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<string>
using namespace std;

struct Person {             // Person-Typ anlegen
   string nachname;
   string vorname;
   int alter;
};

int main() {
   Person diePerson;        // Person-Objekt anlegen
   cout << "Nachnamen eingeben: ";
   cin >> diePerson.nachname;
   cout << "Vornamen eingeben: ";
   cin >> diePerson.vorname;
   cout << "Alter eingeben: ";
   cin >> diePerson.alter;
   cout << "Die Person hat folgende Daten:" << endl;
   cout << "Nachname    : " << diePerson.nachname << endl;
   cout << "Vorname     : " << diePerson.vorname << endl;
   cout << "Alter       : " << diePerson.alter << endl;
}

