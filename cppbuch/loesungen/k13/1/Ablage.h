/* cppbuch/loesungen/k13/1/Ablage.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef ABLAGE_H
#define ABLAGE_H
#include <boost/thread.hpp>

namespace {
   boost::mutex ausgabeMutex;
}

class Ablage {
public:
   Ablage(int platz) 
      : beendet(false), kapazitaet(platz), inhalt(new int[platz]), 
        anzahl(0), lesePos(-1), schreibPos(0) {
   }
   int get() {
      boost::unique_lock<boost::mutex> lock(monitorMutex);
      while(anzahl == 0) {   // leer
         cond.wait(lock);
         if(beendet) {
            throw "get()-wait beendet";
         }
      }
      --anzahl;
      cond.notify_all();
      lesePos = (lesePos + 1) % kapazitaet;
      return inhalt[lesePos];
   }
   void put(int wert) {
      boost::unique_lock<boost::mutex> lock(monitorMutex);
      while(anzahl == kapazitaet) {   // voll
         cond.wait(lock);
         if(beendet) {
            throw "put()-wait beendet";
         }
      }
      inhalt[schreibPos] = wert;
      ++anzahl;
      schreibPos = (schreibPos + 1) % kapazitaet;
      cond.notify_all();
   }
   void beenden() {  // Alle waits zwangsläufig beenden
      beendet = true;
      cond.notify_all();
   }
private:
   bool beendet;
   int kapazitaet;
   int* const inhalt;
   int anzahl; 
   // Aufbau als Ringpuffer (FIFO)
   int lesePos;     // letzte gelesene Pos
   int schreibPos;  // nächste zu schreibende Pos
   boost::mutex monitorMutex;
   boost::condition_variable cond;
};

#endif
