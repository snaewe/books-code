/* cppbuch/loesungen/k3/8/taschenrechner.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"taschenrechner.h"
#include<cctype>
#include<iostream>
using std::cin;
using std::cout;

long ausdruck(char& c) {        // Übergabe per Referenz!
  long a;                      // Hilfsvariable für Ausdruck
  if(c == '-') {
    cin.get(c);              // - im Eingabestrom überspringen
    a = -summand(c);         // Rest an summand() übergeben
  }
  else {
    if(c == '+')
      cin.get(c);          // + überspringen
    a = summand(c);
  }
  while(c == '+' || c == '-')
    if(c == '+') {
      cin.get(c);           // + überspringen
      a += summand(c);
    }
    else {
      cin.get(c);           // - überspringen
      a -= summand(c);
    }
  return a;
}

long summand(char& c) {
  long s  = faktor(c);
  while(c == '*' || c == '/')
    if(c == '*') {
      cin.get(c);          // * überspringen
      s *= faktor(c);
    }
    else {
      cin.get(c);          // / überspringen
      s /= faktor(c);
    }
  return s;
}

long faktor(char& c) {
  long f;
  if(c == '(') {
    cin.get(c);                    // ( überspringen
    f = ausdruck(c);
    if(c != ')' )
      cout << "Rechte Klammer fehlt!\n"; //*** s.u.
        else cin.get(c);               // ) überspringen
  }
  else f = zahl(c);
  return f;
}

long zahl(char& c) {        
  long z = 0;
  /* isdigit() ist eine Funktion (genauer: ein Makro), das zu
    true ausgewertet wird, falls c ein Zifferzeichen ist. Die
    Verwendung setzt #include<cctype> voraus.*/
  while(isdigit(c))   { // d.h. c >= '0' && c <= '9'
    z = 10*z + static_cast<long>(c-'0');
    cin.get(c);
  }
  return z;
}
