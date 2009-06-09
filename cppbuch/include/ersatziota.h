/* cppbuch/include/ersatziota.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef IOTA_H
#define IOTA_H

// Diese Datei stellt iota() zur Verfügung, falls es der Compiler
// nicht tut (Header <numeric>. Dies gilt für
// GNU C++ Version 4.3 und kleiner.
template <class ForwardIterator, class T>
void iota(ForwardIterator first, ForwardIterator last, T value) {
   while (first != last) {
      *first++ = value++;
   }
}
#endif
