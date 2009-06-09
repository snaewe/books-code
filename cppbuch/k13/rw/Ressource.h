/* cppbuch/k13/rw/Ressource.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef RESSOURCE_H
#define RESSOURCE_H
#include <string>
#include <boost/thread.hpp>
#include<boost/lexical_cast.hpp>
#include <iostream>
#include<Random.h>

namespace {
   boost::mutex ausgabeMutex;
   Random derZufall(500);
}

class Ressource {
public:
   Ressource() 
      : inhalt("nichts"), nreader(0), nwriter(0) {
   }

   std::string read(const std::string& id) {
      boost::shared_lock<boost::shared_mutex> lock(rwMutex); // Lock für geteilten Zugriff
      ++nreader;
      println(id  + "  liest " + inhalt  + rwprotokoll());
      boost::this_thread::sleep(boost::posix_time::millisec(2000 + derZufall()));  // lesen dauert ..
      --nreader;
      return inhalt;
   }

   void write(const std::string& neu, const std::string& id) {
      boost::unique_lock<boost::shared_mutex> lock(rwMutex); // Lock für exklusiven Zugriff
      ++nwriter;
      println(id  + " schreibt " + neu  + rwprotokoll());
      boost::this_thread::sleep(boost::posix_time::millisec(1000 + derZufall()));// schreiben auch ..
      --nwriter;
      inhalt = neu;
   }

   static void println(const std::string& was) {
      boost::lock_guard<boost::mutex> lock(ausgabeMutex);
      std::cout << was << std::endl;
   }
private:
   std::string rwprotokoll() {
      std::string msg(" Anzahl Aktiver:  R=");
      // lexical_cast wandelt die Zahl in einen string um, siehe Seite \pageref{lexicalcast}
      msg += boost::lexical_cast<std::string>(nreader) + "  W="
          +  boost::lexical_cast<std::string>(nwriter);
      return msg;
   }
   std::string inhalt;
   boost::shared_mutex rwMutex;
   int nreader;
   int nwriter;
};

#endif
