/* cppbuch/k28/list/identify/identif.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef IDENTIF_H
#define IDENTIF_H
#include<iostream>
#include<string>

class Identifier {
  public:
   const std::string& toString() const { return theIdentifier;}
   friend std::istream& operator>>(std::istream&, Identifier&);
  private:
   std::string theIdentifier;
};

inline bool operator==(const Identifier& N1, const Identifier& N2) {
    return N1.toString() == N2.toString();
}

inline bool operator<(const Identifier& N1, const Identifier& N2) {
    return N1.toString() < N2.toString();
}

std::ostream& operator<<(std::ostream&, const Identifier&);

#endif
