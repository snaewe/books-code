/* cppbuch/loesungen/k9/1_bis_4/ratioop.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// Klasse für rationale Zahlen mit überladenen Operatoren
#ifndef RATIOOP_H
#define RATIOOP_H
#include<iostream>

class Rational {
   public:
     Rational();
     Rational(long);             // Typumwandlungskonstruktor

     // Abfragen
     long getZaehler() const;
     long getNenner()  const;

     // arithmetische Methoden
     Rational& operator+=(const Rational&);
     Rational& operator-=(const Rational&);
     Rational& operator*=(const Rational&);
     Rational& operator/=(const Rational&);

     // weitere Methoden
     void set(long zaehler, long nenner);
     void kehrwert();
     void kuerzen();

   private:
     long zaehler, nenner;
};

// inline Methoden
inline Rational::Rational()
: zaehler(1), nenner(1)   {}

inline Rational::Rational(long ganzeZahl)
: zaehler(ganzeZahl), nenner(1)   {}

inline long Rational::getZaehler() const {return zaehler;}
inline long Rational::getNenner()  const {return nenner;}

// globale Operatoren
const Rational operator+(const Rational&, const Rational&);
const Rational operator-(const Rational&, const Rational&);
const Rational operator*(const Rational&, const Rational&);
const Rational operator/(const Rational&, const Rational&);
bool operator==(const Rational&, const Rational&);

// globale Funktionen zur Ein- und Ausgabe
std::ostream& operator<<(std::ostream&, const Rational&);
std::istream& operator>>(std::istream&, Rational&);


#endif
