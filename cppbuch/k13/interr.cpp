/* cppbuch/k13/interr.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <boost/thread.hpp>
#include <iostream>
#include <functional>            // ref()
using namespace std;

class Worker {
public:
   Worker()
      : pause(false) {
   }
   void operator()() {
      try {
         while(true) {  // Abbruch mit Interrupt
            cout << "Worker bei der Arbeit!" << endl;
            pauseOderNicht();
            boost::this_thread::sleep(boost::posix_time::seconds(1));
         }
      } catch(const boost::thread_interrupted& e) {
         ; // nichts machen, while-Schleife ist beendet
      }
      cout << "Worker macht Feierabend!" << endl;
   }
   void warten() { 
      boost::lock_guard<boost::mutex> lock(mtxPause);
      pause = true; 
   }
   void weiter() { 
      boost::lock_guard<boost::mutex> lock(mtxPause);
      pause = false; 
      cond.notify_all(); 
   }
private:
   bool pause;
   boost::mutex mtxPause;
   boost::condition_variable cond;

   void pauseOderNicht() {
      boost::mutex mtx;
      boost::unique_lock<boost::mutex> lock(mtx);
      while(pause) {
         cout << "Worker pausiert!" << endl;
         cond.wait(lock);
         // Eine während wait() geworfene Exception durch interrupt()
         // wird an den Aufrufer weitergegeben
         cout << "Worker macht weiter!" << endl;
      }
   }
};

int main() {
   Worker worker;
   boost::thread t(std::ref(worker));
   int stunde = 8;
   boost::thread::id keinThread;
   while(t.get_id() != keinThread) {
      boost::this_thread::sleep(boost::posix_time::seconds(1));
      cout << ++stunde << " Uhr: ";
      switch(stunde) {
      case 10 : worker.warten();
         break;
      case 13 : worker.weiter(); 
         break;
      case 16:  t.interrupt(); 
         t.join(); 
         break;
      default: if(stunde > 16) {
            throw "Fehler!";
         }
      }
   }
}
