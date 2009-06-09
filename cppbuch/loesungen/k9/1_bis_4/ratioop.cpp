/* cppbuch/loesungen/k9/1_bis_4/ratioop.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"ratioop.h"
#include<cassert>

// globale Hilfsfunktion (größter gemeinsamer Teiler)
long ggt(long x, long y) {
     long rest;
     while (y) {
       rest = x % y;
       x = y; y = rest;
     }
     return x;
}

// ******+ Methodenimplementation ********

void Rational::set(long z, long n) {
     zaehler = z;
     nenner  = n;
     assert(nenner != 0);
     kuerzen();
}

void Rational::kehrwert() {
     long temp = zaehler;
     zaehler = nenner;
     nenner  = temp;
     assert(nenner != 0);
}

void Rational::kuerzen() {
     int sign = 1;
     if (zaehler < 0) { sign = -sign; zaehler = -zaehler;}
     if (nenner  < 0) { sign = -sign; nenner  = -nenner;}
     long teiler = ggt(zaehler, nenner);
     zaehler = sign*zaehler/teiler;
     nenner = nenner/teiler;
}

Rational& Rational::operator+=(const Rational& b) {
     zaehler = zaehler*b.nenner + b.zaehler*nenner;
     nenner  = nenner*b.nenner;
     kuerzen();
     return *this;
}

Rational& Rational::operator-=(const Rational& b) {
     zaehler = zaehler*b.nenner - b.zaehler*nenner;
     nenner  = nenner*b.nenner;
     kuerzen();
     return *this;
}

Rational& Rational::operator*=(const Rational& b) {
     zaehler *= b.zaehler;
     nenner  *= b.nenner;
     kuerzen();
     return *this;
}

Rational& Rational::operator/=(const Rational& b) {
     zaehler *= b.nenner;
     nenner  *= b.zaehler;
     kuerzen();
     return *this;
}

// ******* globale Operatoren ********

const Rational operator+(const Rational& a, const Rational& b) {
    return Rational(a) += b; 
}

const Rational operator-(const Rational& a, const Rational& b) {
    return Rational(a) -= b; 
}

const Rational operator*(const Rational& a, const Rational& b) {
    return Rational(a) *= b; 
}

const Rational operator/(const Rational& a, const Rational& b) {
    return Rational(a) /= b; 
}

bool operator==(const Rational& a, const Rational& b) {   
   /* Es wird hier angenommen, dass beide Zahlen in der gekürzten Darstellung
      vorliegen, weil dies durch die Elementfunktionen erzwungen wird.
      Andernfalls müssten beide Argumente vor dem Vergleich gekürzt werden.
    */
    return   a.getZaehler() == b.getZaehler()
          && a.getNenner()  == b.getNenner();
}

std::ostream& operator<<(std::ostream& ausgabe, const Rational& r) {
     ausgabe << r.getZaehler() << "/" << r.getNenner();
     return ausgabe;
}

std::istream& operator>>(std::istream& eingabe, Rational& r) {
     // cerr wird gewählt, damit die Abfragen auch dann
     // auf dem Bildschirm erscheinen, wenn die Standard-
     // ausgabe in eine Datei zur Dokumentation geleitet wird.
     int z, n;
     std::cerr << "Zähler :";
     eingabe >> z;
     std::cerr << "Nenner :";
     eingabe >> n;
     assert(n != 0);   // nicht sehr benutzungsfreundlich...
     r.set(z, n);
     r.kuerzen();
     return eingabe;
}
