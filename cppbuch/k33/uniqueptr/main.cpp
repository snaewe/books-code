/* cppbuch/k33/uniqueptr/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#if  __GNUC__*10+__GNUC_MINOR__ < 44 
#error Die Uebersetzung dieses Programms verlangt mindestens G++ 4.4
#else
#include<iostream>
#include<memory>
using namespace std;

class Ressource {
public:
   Ressource(int i) 
      : id(i){
   cout << "Konstruktor Ressource()" << endl;
   }
   void hi() {
      cout << "hier ist Ressource::hi(), Id=" << id << endl;
   }

   ~Ressource() {
      cout << "Ressource::Destruktor, Id=" << id << endl;
   }
private:
   int id;
};

int main() {
   cout << "Zeiger auf dynamisches Objekt:" << endl;
   unique_ptr<Ressource> p1(new Ressource(1));
   cout << "Operator ->  ";
   p1->hi();
   cout << "Operator *   ";
   (*p1).hi();

   //  Null-Zeiger
   unique_ptr<Ressource> nullp((Ressource*)0);
   //nullp->hi();   // ok, Speicherzugriffsfehler!
   //cout << "release()" << endl;
   //p1.release();  // verhindert Destruktor-Aufruf
   p1.reset(0);  //  Destruktor-Aufruf ok
   cout << "Ende von main()" << endl;
}
#endif
