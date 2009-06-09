/* cppbuch/k13/prodcons/Ablage.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef ABLAGE_H
#define ABLAGE_H
#include <boost/thread.hpp>
#include <iostream>

namespace {
   boost::mutex ausgabeMutex;
}

class Ablage {
public:
   Ablage() 
      : belegt(false), beendet(false) {
   }
   int get() {
      boost::unique_lock<boost::mutex> lock(monitorMutex);
      while(!belegt) {
         cond.wait(lock);
         if(beendet) {
            throw "get()-wait beendet";
         }
      }
      belegt = false;
      cond.notify_one();
      return inhalt;
   }
   void put(int wert) {
      boost::unique_lock<boost::mutex> lock(monitorMutex);
      while(belegt) {
         cond.wait(lock);
         if(beendet) {
            throw "put()-wait beendet";
         }
      }
      belegt = true;
      inhalt = wert;
      cond.notify_one();
   }
   void beenden() {  // Alle waits zwangsläufig beenden
      beendet = true;
      cond.notify_all();
   }
private:
   bool belegt;
   bool beendet;
   int inhalt;
   boost::mutex monitorMutex;
   boost::condition_variable cond;
};

#endif
