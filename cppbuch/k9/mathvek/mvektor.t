/* cppbuch/k9/mathvek/mvektor.t
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef MVEKTOR_T
#define MVEKTOR_T
#include<iostream>
#include"../vektor/vektor.t"

template<typename T>
class MathVektor : public Vektor<T> {
   public:
      typedef Vektor<T> super; // Abkürzung für Oberklassentyp

      MathVektor(size_t=0);
      MathVektor(size_t n, T wert);
      void init(const T&);  // alle Elemente setzen

      // Operatoren
      MathVektor& operator*=(const T&); // Operator {\tt *=}
      // weitere Operatoren und Funktionen ...
};

/*************** Implementation *********************/

template<typename T>
MathVektor<T>::MathVektor(size_t x)
: Vektor<T>(x) {
}

template<typename T>
MathVektor<T>::MathVektor(size_t n, T wert)
: Vektor<T>(n, wert) {
}

template<typename T>
void MathVektor<T>::init(const T& wert) {
    for(size_t i = 0; i < super::size(); ++i) {
       super::operator[](i) = wert;
    }
}

template<typename T>
MathVektor<T>& MathVektor<T>::operator*=(const T& zahl) {
    for(size_t i = 0; i < super::size(); ++i) {
       super::operator[](i) *= zahl; // elementweise Multiplikation
    }
    return *this;
}

// {\tt *} Operator für den Fall  {\tt v1 = zahl*v2;}
template<typename T>
MathVektor<T> operator*(const T& zahl, const MathVektor<T> &v) {
    MathVektor<T> temp = v;
    return temp *= zahl;  // Aufruf von {\tt operator*=()}
}

// {\tt *} Operator für den Fall  {\tt v1 = v2*zahl;}
// (vertauschte Reihenfolge der Argumente)
template<typename T>
MathVektor<T> operator*(const MathVektor<T> &v, const T& zahl) {
    return zahl*v;  // Aufruf des obigen {\tt operator*()}
}

/* Weil MathVektor nur mit mathematisch sinnvolle Datentypen
    instantiiert wird, für die der Standardausgabeoperator definiert
    ist, ist es sinnvoll, einen Operator für die Ausgabe eines
    MathVektor-Objekts zu definieren:
*/

template<typename T>
std::ostream& operator<<(std::ostream& os, const MathVektor<T>& v) {
    // Verbesserungen im Ausgabelayout sind möglich!
    for(size_t i = 0; i < v.size(); ++i)  {
        os << v[i] << '\t';
        if ((i+1)%8==0 || i==v.size()-1) os << std::endl;
    }
    return os;
}
#endif

