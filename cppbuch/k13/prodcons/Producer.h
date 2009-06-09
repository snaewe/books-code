/* cppbuch/k13/prodcons/Producer.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef PRODUCER_H
#define PRODUCER_H
#include <iostream>
#include<Random.h>
#include"Ablage.h"

class Producer {
public:
   Producer(Ablage& a, int i)
      : ablage(a), id(i), zufall(500) {
   }
   void operator()() {
      for(int i = 0; i < 5; ++i) {
         int wert = id*10 + i;
         boost::this_thread::sleep(
                      boost::posix_time::millisec(200 + zufall()));
         try {
            ablage.put(wert);
            boost::lock_guard<boost::mutex> lock(ausgabeMutex);
            std::cout << "Producer Nr. " << id 
                      << "  legt ab: " << wert << std::endl;
         } catch(...) {
              break; //  Producer ist beendet
         }
      }
      boost::lock_guard<boost::mutex> lock(ausgabeMutex);
      std::cout << "Producer " << id << " beendet sich." << std::endl; 
   }
private:
   Ablage& ablage;
   int id;
   Random zufall;
};


#endif
