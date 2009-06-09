/* cppbuch/k4/ort1/ort1.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef ORT1_H
#define ORT1_H

class Ort1 {                               // 1. Version
    public:
      int getX() const;
      int getY() const;
      void aendern(int x, int y); // x,y = neue Werte
    private:
      int xKoordinate,
          yKoordinate;
};
#endif     //  ORT1_H
