/* cppbuch/k13/rwp/Writer.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef WRITER_H
#define WRITER_H
#include"ReaderWriter.h"

class Writer : public ReaderWriter {
public:
   Writer(Ressource& r, const std::string&  i)
   : ReaderWriter(r, std::string("Writer ") + i) {
   }
   void operator()() {
      int nr = 0;
      Random zufall(200);
      while(!ende) {
         std::string nachricht("Nachricht Nr.");
         // lexical_cast wandelt die Zahl in einen string um, siehe Seite \pageref{lexicalcast}
         nachricht +=  boost::lexical_cast<std::string>(++nr);
         ressource.write(nachricht, id);
         // Den nächsten Schreibvorgang zufällig verzögern:
         boost::this_thread::sleep(boost::posix_time::millisec(2000+zufall()));
      }
      Ressource::println(id + " beendet sich.");
   }
};


#endif
