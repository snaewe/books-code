/* cppbuch/loesungen/k13/1/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <boost/thread.hpp>
#include"Ablage.h"
#include"Producer.h"
#include"Consumer.h"
using namespace std;

int main() {
   Ablage ablage(10);
   Producer p1(ablage, 1);
   Producer p2(ablage, 2);
   Consumer c1(ablage, 1);
   Consumer c2(ablage, 2);

   boost::thread tp1(p1);
   boost::thread tp2(p2);
   boost::thread tc1(c1);
   boost::thread tc2(c2);

   tp1.join();
   tp2.join();
   // warten, bis alle Objekte konsumiert worden sind 
   boost::this_thread::sleep(boost::posix_time::seconds(2));
   ablage.beenden();  // get-waits beenden
   tc1.join();
   tc2.join();
}
