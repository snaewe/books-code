/* cppbuch/k18/tdd/ungueltigesdatumexception.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef UNGUELTIGESDATUMEXCEPTION_H
#define UNGUELTIGESDATUMEXCEPTION_H
#include<stdexcept>

namespace {
    char buf[] = "tt.mm.jjjj ist ein ungültiges Datum!";
}

class UngueltigesDatumException : public std::runtime_error {
 public:
   UngueltigesDatumException(int t, int m, int j) 
      : std::runtime_error(toCString(t, m, j)) {
   }
 private:
   static const char * toCString(int tag, int monat, int jahr) {
      buf[0] = tag/10 +'0';   buf[1] = tag%10 +'0';
      buf[3] = monat/10 +'0'; buf[4] = monat%10 +'0';
      int pos = 9;                 // letzte Jahresziffer
      int j = jahr;
      while(j > 0) {
         buf[pos--] = j % 10 + '0';  // letzte Ziffer
         j = j/10;                  // letzte Ziffer abtrennen
      }
      return buf;
   }
};
#endif
