/* cppbuch/loesungen/k13/1/Consumer.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef CONSUMER_H
#define CONSUMER_H
#include <iostream>
#include"Ablage.h"

class Consumer {
public:
   Consumer(Ablage& a, int i)
      : ablage(a), id(i) {
   }
   void operator()() {
      try {
         while(true) {
            int wert = ablage.get();
            boost::lock_guard<boost::mutex> lock(ausgabeMutex);
            std::cout << "Consumer " << id << " hat " 
                      << wert << " geholt." << std::endl;
         }
      } catch(...) {
         boost::lock_guard<boost::mutex> lock(ausgabeMutex);
         std::cout << "Consumer " << id << " beendet sich." << std::endl; 
      }
   }
private:
   Ablage& ablage;
   int id;
   };


#endif
