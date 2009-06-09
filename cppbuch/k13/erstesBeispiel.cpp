/* cppbuch/k13/erstesBeispiel.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <boost/thread.hpp>
#include <iostream>
using namespace std;

void f(int t) {
   boost::this_thread::sleep(boost::posix_time::seconds(t));
   cout << "Thread " << boost::this_thread::get_id()
        << " : Funktion beendet! Laufzeit = " << t << " s" << endl;
}

int main() {
   boost::thread t1(f, 4);
   boost::thread t2(f, 6);
   boost::thread t3(f, 2);
   cout << "t1.get_id(): " << t1.get_id() << endl;
   cout << "t2.get_id(): " << t2.get_id() << endl;
   cout << "t3.get_id(): " << t3.get_id() << endl;
   t1.join();  // warten auf Beendigung
   t2.join();  // warten auf Beendigung
   t3.join();  // warten auf Beendigung
   cout << "t1.get_id(): " << t1.get_id() << endl;
   cout << "main() ist beendet" << endl;
}
