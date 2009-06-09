/* cppbuch/loesungen/k6/2/format.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"format.h"
#include<iostream>
using namespace std;

Format::Format(int w, int nk) 
   : weite(w), nachkommastellen(nk) {
   if(nk < 0) nk = 0;
   if(nk > 16) nk = 16;
   if(w < nk)  w  = nk+1;
}


string Format::toString(double d) const {
   string ergebnis;
   bool negativ = false;
   if(d < 0.0) {
      negativ = true;
      d = -d;
   }
   // Rundung
   double rund = 0.5;
   for(int i=0; i < nachkommastellen; ++i)
      rund /= 10.0;
   d += rund;

   // Mit der folgenden Normierung (d.h. Zahl beginnt mit 0,..) wird erreicht, dass die
   // Anzahl der Stellen vor dem Komma bekannt ist (Stellenwert). 
   int stellenwert = 0;
   // Zahl normieren, falls >=1
   while(d >= 1.0) {
      ++stellenwert;
      d /= 10.0;
   }
   if(stellenwert == 0) {
      ergebnis += '0'; // wenigstens eine 0 vor dem Komma
   }

   // Die Zahl wird sukzessive mit 10 multipliziert, die jeweils erste Ziffer zunächst
   //  ermittelt (zif), dann abgetrennt und an den Ergebnis-String gehängt usw.  
   // Zahl abarbeiten
   do {
      if(stellenwert == 0) {
         ergebnis += ',';                  // Komma
      }
      d *= 10.0;
      int zif = (int)d;
      d -= zif;
      ergebnis += (char)zif + (int)'0';
      --stellenwert;
   } while(nachkommastellen + stellenwert > 0);

   if(negativ)
      ergebnis = '-' + ergebnis;;

   int diff = weite - ergebnis.length();
   for(int i=0; i < diff; ++i) {
      ergebnis = " " + ergebnis;
   }
   return ergebnis;
}

