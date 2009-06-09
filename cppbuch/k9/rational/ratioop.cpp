/* cppbuch/k9/rational/ratioop.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"ratioop.h"
#include<stdexcept>

void nichtNull(long nenner) {
   if(nenner == 0) {
      throw std::invalid_argument("Nenner darf nicht null sein!");
   }
}

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

Rational::Rational(long z, long n) 
   : zaehler(z), nenner(n) {
     nichtNull(nenner);
     kuerzen();
}

void Rational::set(long z, long n) {
     zaehler = z;
     nenner  = n;
     nichtNull(nenner);
     kuerzen();
}

void Rational::kehrwert() {
     long temp = zaehler;
     zaehler = nenner;
     nenner  = temp;
     nichtNull(nenner);
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

// ******* globale Operator + ******** -, * und / siehe Übungsaufgabe

const Rational operator+(const Rational& a, const Rational& b) {
    return Rational(a) += b; // Rückgabe von {\tt temp.operator+=(b)}
}

// ******* weiterer globaler Operator
bool operator==(const Rational& a, const Rational& b)
{   return   a.getZaehler() == b.getZaehler()
          && a.getNenner()  == b.getNenner();
}

std::ostream& operator<<(std::ostream& ausgabe, const Rational& r) {
     ausgabe << r.getZaehler() << "/" << r.getNenner();
     return ausgabe;
}

std::istream& operator>>(std::istream& eingabe, Rational& r)
{    // cerr wird gewählt, damit die Abfragen auch dann
     // auf dem Bildschirm erscheinen, wenn die Standard-
     // ausgabe in eine Datei zur Dokumentation geleitet wird.
     int z, n;
     std::cerr << "Zähler :";
     eingabe >> z;
     std::cerr << "Nenner :";
     eingabe >> n;
     nichtNull(n);    // nicht sehr benutzungsfreundlich...
     r.set(z, n);
     r.kuerzen();
     return eingabe;
}
