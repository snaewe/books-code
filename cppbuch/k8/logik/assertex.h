/* cppbuch/k8/logik/assertex.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef ASSERTEX_H
#define ASSERTEX_H

  #ifdef NDEBUG
    #define Assert(bedingung, ausnahme) ; // Leeranweisung
  #else
    #define Assert(bedingung, ausnahme) \
          if (!(bedingung)) throw ausnahme
  #endif
#endif
