/* cppbuch/include/ort.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef ORT_H
#define ORT_H
#include<string>
#include<cmath>                 // wegen {\tt sqrt()}
#include<cassert>
#include<iostream>

#include<cstdlib>
#include<cctype>

class Ort {
    public:
      // Typumwandlungskonstruktor
      // Format: 2 Folgen von Ziffern
      explicit Ort(const std::string& str) {
         unsigned int pos = 0;         // Position einer Ziffer
         for(int j = 0; j < 2; j++)  {// für jede Koordinate
            // erste Ziffer suchen
            while(pos < str.size()) {
               if(isdigit(str.at(pos)))
                 break;
               else ++pos;
            }

            assert(pos < str.size()); // Ziffer gefunden?
            // Zahl bilden
            int koordinate = 0;
            while(pos < str.size() && isdigit(str.at(pos))) {
              koordinate = 10*koordinate + str.at(pos) - '0';
              ++pos;
            }
            switch(j) {
              case 0: xKoordinate = koordinate; break;
              case 1: yKoordinate = koordinate;
            }
         }
      }
      Ort(int einX = 0, int einY = 0)
      : xKoordinate(einX), yKoordinate(einY) {
      }

      int getX() const { return xKoordinate;}
      int getY() const { return yKoordinate;}
      void aendern(int x, int y) {
          xKoordinate = x;
          yKoordinate = y;
      }
    private:
      int xKoordinate;
      int yKoordinate;
};

// globale Funktionen

 // Berechnung der Entfernung zwischen zwei Orten
inline double entfernung(const Ort& ort1, const Ort& ort2) {
    double dx = static_cast<double>(ort1.getX() - ort2.getX());
    double dy = static_cast<double>(ort1.getY() - ort2.getY());
    return std::sqrt(dx*dx + dy*dy);
}


// Anzeige auf der Standardausgabe
inline void anzeigen(const Ort& O) {
    std::cout << '(' << O.getX() << ", " << O.getY() << ')';
}

// Gleichheitsoperator
inline bool operator==(const Ort& ort1, const Ort& ort2) {
  return  (ort1.getX() == ort2.getX()
        && ort1.getY() == ort2.getY());
}

// Überladen des Ausgabeoperators zur Ausgabe eines Ortes
inline std::ostream& operator<<(std::ostream& os, const Ort& einOrt) {
    os << " (" << einOrt.getX() << ", " << einOrt.getY() << ')';
    return os;
}
#endif 
