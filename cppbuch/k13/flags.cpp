/* cppbuch/k13/flags.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <boost/thread.hpp>
#include <iostream>
using namespace std;

// zur Erklärung der Funktion von reference_wrapper, siehe Text
template<class Callee>
class CallWrapper {
public:
   CallWrapper(Callee& c) : callee(c) {}
   void operator()() {
      callee();
   }
private:
   Callee& callee;
};

class Worker {
public:
   Worker()
      : pause(false), beendet(false) {
   }
   void operator()() {
      while(!beendet) {
         cout << "Worker bei der Arbeit!" << endl;
         pauseOderNicht();
         boost::this_thread::sleep(boost::posix_time::seconds(1));
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
      cond.notify_one(); 
   }
   void beenden() {
      beendet = true; 
      cond.notify_one(); // ... falls im Zustand pausierend
   }
   bool istBeendet() {
      return beendet; 
   }
private:
   bool pause;
   bool beendet;
   boost::mutex mtxPause;
   boost::condition_variable cond;

   void pauseOderNicht() {
      boost::mutex mtx;
      boost::unique_lock<boost::mutex> lock(mtx);
      while(pause && !beendet) {
         cout << "Worker pausiert!" << endl;
         cond.wait(lock);
         cout << "Worker macht weiter!" << endl;
      }
   }
};


int main() {
   Worker worker;
   CallWrapper<Worker> aufrufer(worker);
   boost::thread t(aufrufer);
   int stunde = 8;
   while(!worker.istBeendet()) {
      boost::this_thread::sleep(boost::posix_time::seconds(1));
      cout << ++stunde << " Uhr: ";
      switch(stunde) {
      case 10 : worker.warten();          // Pause
         break;
      case 13 : worker.weiter();          // Fortsetzung
         break;
      case 16:  worker.beenden();         // Ende
         t.join();                        // Ende abwarten
         break;
      default: if(stunde > 16) {
            throw "Fehler!";
         }
      } 
   } 
}
