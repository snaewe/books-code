/* cppbuch/loesungen/k6/2/format.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef FORMAT_H
#define FORMAT_H
#include<string>
using std::string;

class Format {
 public:
   Format(int weite, int nachk);
   string toString(double d) const;
 private:
   int weite;
   int nachkommastellen;
};
#endif
