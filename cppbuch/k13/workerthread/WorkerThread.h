/* cppbuch/k13/workerthread/WorkerThread.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef WORKER_H
#define WORKER_H
#include <boost/thread.hpp>
#include <iostream>
#include <functional>            // \tt{ref()}

using std::cout;
using std::endl;

class WorkerThread  {
public:
   WorkerThread()
      : pause(false), beendet(false) {
   }
   void operator()() {
      while(!beendet) {
         cout << "WorkerThread bei der Arbeit!" << endl;
         pauseOderNicht();
         boost::this_thread::sleep(boost::posix_time::seconds(1));
      }
      cout << "WorkerThread macht Feierabend!" << endl;
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
      derThread.join();
   }
   bool istBeendet() {
      return beendet; 
   }
   void start() {
      derThread = boost::thread(std::ref(*this));
   }
private:
   bool pause;
   bool beendet;
   boost::thread derThread;
   boost::mutex mtxPause;
   boost::condition_variable cond;

   void pauseOderNicht() {
      boost::mutex mtx;
      boost::unique_lock<boost::mutex> lock(mtx);
      while(pause && !beendet) {
         cout << "WorkerThread pausiert!" << endl;
         cond.wait(lock);
         cout << "WorkerThread macht weiter!" << endl;
      }
   }
};



#endif
