/* cppbuch/k13/prodcons/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <boost/thread.hpp>
#include"Ablage.h"
#include"Producer.h"
#include"Consumer.h"
using namespace std;

int main() {
   Ablage ablage;
   Producer p1(ablage, 1);
   Producer p2(ablage, 2);
   Consumer c(ablage);

   boost::thread tp1(p1);
   boost::thread tp2(p2);
   boost::thread tc(c);

   tp1.join();
   tp2.join();
   // warten, bis alles abgeholt ist
   boost::this_thread::sleep(boost::posix_time::seconds(1));
   ablage.beenden();
   tc.join();
}
