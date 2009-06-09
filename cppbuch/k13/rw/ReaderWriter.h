/* cppbuch/k13/rw/ReaderWriter.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef READERWRITER_H
#define READERWRITER_H
#include"Ressource.h"

class ReaderWriter {
public:
   virtual void operator()() = 0;
   void beenden() {
      ende = true;
   }
protected:
   ReaderWriter(Ressource& r, const std::string&  i)
      : ende(false), ressource(r), id(i) {
   }
   virtual ~ReaderWriter() {}
   bool ende;
   Ressource& ressource;
   std::string id;
};

#endif
