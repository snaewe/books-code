/* cppbuch/loesungen/k4/6/taschenrechner.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"taschenrechner.h"
#include<cctype>
#include<iostream>

Taschenrechner::Taschenrechner(const std::string& str) 
   : anfrage(str), position(0), ergebnis(0L) {
   char c;
   get(c); // 1. Zeichen lesen
   ergebnis = ausdruck(c);
}
 
const std::string& Taschenrechner::getAnfrage() {
   return anfrage; 
}

long Taschenrechner::getErgebnis() {
   return ergebnis;
}


void Taschenrechner::get(char& c) {
   do {
      if(position >= anfrage.length()) {
         c = '#'; // ungueltiges Zeichen, d.h. Abbruch
      }
      else {
         c = anfrage[position++];
      }
   } while(c == ' '); // Leerzeichen ignorieren
}
                              
long Taschenrechner::ausdruck(char& c) {        // Uebergabe per Referenz!
  long a;                      // Hilfsvariable fuer Ausdruck
  if(c == '-') {
    get(c);              // - im Eingabestrom ueberspringen
    a = -summand(c);         // Rest an summand() uebergeben
  }
  else {
    if(c == '+')
      get(c);          // + ueberspringen
    a = summand(c);
  }
  while(c == '+' || c == '-')
    if(c == '+') {
      get(c);           // + ueberspringen
      a += summand(c);
    }
    else {
      get(c);           // - ueberspringen
      a -= summand(c);
    }
  return a;
}

long Taschenrechner::summand(char& c) {
  long s  = faktor(c);
  while(c == '*' || c == '/')
    if(c == '*') {
      get(c);          // * ueberspringen
      s *= faktor(c);
    }
    else {
      get(c);          // / ueberspringen
      s /= faktor(c);
    }
  return s;
}

long Taschenrechner::faktor(char& c) {
  long f;
  if(c == '(') {
    get(c);                    // ( ueberspringen
    f = ausdruck(c);
    if(c != ')' ) {
       std::cout << "Rechte Klammer fehlt!\n"; 
    }
    else {
        get(c);    // ) ueberspringen
    }           
  }
  else f = zahl(c);
  return f;
}

long Taschenrechner::zahl(char& c) {        
  long z = 0;
  /* isdigit() ist eine Funktion (genauer: ein Makro), das zu
    true ausgewertet wird, falls c ein Zifferzeichen ist. Die
    Verwendung setzt #include<cctype> voraus.*/
  while(isdigit(c))   { // d.h. c >= '0' && c <= '9'
    z = 10*z + static_cast<long>(c-'0');
    get(c);
  }
  return z;
}
