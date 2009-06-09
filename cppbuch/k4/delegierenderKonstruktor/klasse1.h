/* cppbuch/k4/delegierenderKonstruktor/klasse1.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef KLASSE1_H
#define KLASSE1_H

class Klasse {
   public:
   Klasse(int a, int b)        // Konstruktor 1
      : attr1(a), attr2(b) {
      weitereInitialisierungen();
      }
      Klasse()                 // Konstruktor 2
      : attr1(1), attr2(42) {
      weitereInitialisierungen();
      }
   private:
     void weitereInitialisierungen() {
       // Code für weitere Initialisierungen
     }
     int attr1;
     int attr2;
};
#endif 
