/* cppbuch/k13/prodcons/Consumer.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef CONSUMER_H
#define CONSUMER_H
#include <iostream>
#include"Ablage.h"


class Consumer {
public:
   Consumer(Ablage& a)
      : ablage(a) {
   }
   void operator()() {
      try {
         while(true) {                // Abbruch mit Exception
            int wert = ablage.get();
            boost::lock_guard<boost::mutex> lock(ausgabeMutex);
            std::cout << "Consumer hat " 
                      << wert << " geholt." << std::endl;
         }
      } catch(...) {
         boost::lock_guard<boost::mutex> lock(ausgabeMutex);
         std::cout << "Consumer beendet sich." << std::endl; 
      }
   }
private:
   Ablage& ablage;
};


#endif
