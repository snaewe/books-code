/* cppbuch/k14/thread/thread.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<QThread>
#include <iostream>

class MyThread : public QThread {
public:
   MyThread(int t)
      :  dauer(t)  {
   }
   void run() {
      sleep(dauer);
      std::cout << "Thread beendet! Laufzeit = " << dauer << " s" << std::endl;
   }
private:
   int dauer;
};

using namespace std;

int main() {
   MyThread t1(4);
   MyThread t2(6);
   MyThread t3(2);
   t1.start();
   t2.start();
   t3.start();
   cout << "t1.isRunning(): " << t1.isRunning() << endl;
   cout << "t2.isRunning(): " << t2.isRunning() << endl;
   cout << "t3.isRunning(): " << t3.isRunning() << endl;
   t1.wait();  // warten auf Beendigung
   t2.wait();  // warten auf Beendigung
   t3.wait();  // warten auf Beendigung
   cout << "t1.isRunning(): " << t1.isRunning() << endl;
   cout << "main() ist beendet" << endl;
}
