/* cppbuch/k13/rw/Reader.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef READER_H
#define READER_H
#include"ReaderWriter.h"

class Reader : public ReaderWriter {
public:
   Reader(Ressource& r, const std::string&  i) 
      : ReaderWriter(r, std::string("Reader ") + i) {
   }
   void operator()() {
      Random zufall(1000);
      while(!ende) {
         std::string inhalt = ressource.read(id); // hier nicht weiter verwendet,
         // es geht nur um den reinen Lesevorgang.
         // Den nächsten Lesevorgang zufällig verzögern:
         boost::this_thread::sleep(boost::posix_time::millisec(zufall()));
      }
      Ressource::println(id + " beendet sich.");
   }
};


#endif
