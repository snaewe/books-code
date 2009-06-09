/* cppbuch/k13/workerthread/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <boost/thread.hpp>
#include"WorkerThread.h"
using namespace std;

int main() {
   WorkerThread workerThread;
   workerThread.start();
   int stunde = 8;
   while(!workerThread.istBeendet()) {
      boost::this_thread::sleep(boost::posix_time::seconds(1));
      cout << ++stunde << " Uhr: ";
      switch(stunde) {
      case 10 : workerThread.warten(); break;   // Pause
      case 13 : workerThread.weiter(); break;   // Fortsetzung
      case 16:  workerThread.beenden(); break;  // Ende
      default: if(stunde > 16) 
            throw "Fehler!";
      } 
   } 
}
