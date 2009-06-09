/* cppbuch/k9/poly/ober.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef OBER_H
#define OBER_H
#include<iostream>

class Ober {
  public:
    Ober(int io)
    : iO(io) {
    }
    virtual ~Ober() {}

    virtual int get() const {  return iO;}

    virtual Ober& assign(const Ober& rs) {
       std::cout << "Ober::this = " << (unsigned)this
                 << "       &rs = " << (unsigned)(&rs) << std::endl;
       if(this != &rs) {
          lokaleZuweisung(rs);
       }
       return *this;
    }
    Ober& operator=(const Ober& rs) { return assign(rs); }

  protected:
    void lokaleZuweisung(const Ober& rs) {
       iO = rs.iO;
    }

  private:
    int iO;   // Daten speziell für Ober
};
#endif
