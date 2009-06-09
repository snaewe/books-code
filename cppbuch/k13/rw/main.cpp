/* cppbuch/k13/rw/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<boost/thread.hpp>
#include<functional>  // ref()
#include"Ressource.h"
#include"Writer.h"
#include"Reader.h"

using namespace std;

int main() {
   Ressource ressource;
   Writer w1(ressource, "w1");
   Writer w2(ressource, "w2");
   Reader r1(ressource, "r1");
   Reader r2(ressource, "r2");
   Reader r3(ressource, "r3");
   Reader r4(ressource, "r4");

   boost::thread_group threads;
   threads.create_thread(std::ref(w1));
   threads.create_thread(std::ref(r1));
   threads.create_thread(std::ref(r2));
   threads.create_thread(std::ref(r3));
   threads.create_thread(std::ref(r4));
   boost::this_thread::sleep(boost::posix_time::seconds(1));
   threads.create_thread(std::ref(w2));

   // Threads eine Zeit lang laufen lassen
   boost::this_thread::sleep(boost::posix_time::seconds(30));
   w1.beenden();
   w2.beenden();
   r1.beenden();
   r2.beenden();
   r3.beenden();
   r4.beenden();
   threads.join_all();   // warten, bis alles beendet ist
}
