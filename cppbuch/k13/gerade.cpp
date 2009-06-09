/* cppbuch/k13/gerade.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <boost/thread.hpp>
#include <iostream>
using namespace std;

namespace {
   boost::mutex mtx;
}

class Gerade {
public:
   Gerade() 
      : n(0) {
   }
   int next() {
      // Kommentarzeichen in der Folgezeile fuer korrekte Funktion entfernen!
      //boost::lock_guard<boost::mutex> lock(mtx);
      ++n;
      ++n;
      return n;
   }
private:
   int n;
};

Gerade g;

void testeGerade() {
   for(int i=0; i < 10000; ++i) {
      int wert = g.next();
      if(wert % 2 != 0) {
         cout << wert << " ist ungerade! Thread beendet."<< endl;
         break;
      }
   }
}

int main() {
   boost::thread_group threads;
   for (int i = 0; i < 20; ++i) {
      threads.create_thread(testeGerade);
   }
   threads.join_all();
}
