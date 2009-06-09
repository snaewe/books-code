/* cppbuch/k33/placement/placement.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<new>
using namespace std;

class Irgendwas {
  public:
   Irgendwas() : id(++maxid) { }
   void machwas() const  {
     cout << "Id  = " << id  << endl;
   }
  private:
   int id;
   static int maxid;
};

int Irgendwas::maxid = 0;

int main() {
  char vielPlatz[1000*sizeof(Irgendwas)] ={0};

  // Ein Objekt in {\tt vielPlatz} anlegen:
  Irgendwas* p = new (vielPlatz) Irgendwas;
  p->machwas();

  // Weitere 10 Objekte mit Array-Operator anlegen:
  char* naechsteAdresse = (char*)p + sizeof(Irgendwas);
  new (naechsteAdresse) Irgendwas[10];

  // Alle 11 Objekte abfragen
  for(int i = 0; i < 11; ++i) {
     cout << i << ": ";
     p++->machwas();
  }
  // Die nächste Position darf nicht belegt sein, d.h. der
  // Aufruf muss 0 ergeben, weil das Feld so initialisiert wurde.
  p->machwas();
}
