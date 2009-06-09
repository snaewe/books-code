/* cppbuch/k33/sharedptr/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<vector>
#include<memory>
using namespace std;

class Ressource {
public:
   Ressource(int i) 
      : id(i){
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
   cout << "Zeiger auf dynamische Objekte:" << endl;
   cout << "Konstruktoraufruf" << endl;
   shared_ptr<Ressource> p1(new Ressource(1));

   cout << "Operator ->  ";
   p1->hi();
   cout << "Operator *   ";
   (*p1).hi();

   cout << "Benutzungszähler: " << p1.use_count() << endl; // 1

   { // Blockanfang
      // zweiter {\tt shared_ptr} für dasselbe Objekt
      shared_ptr<Ressource> p2(p1);
      cout << "Benutzungszähler p1: " << p1.use_count() << endl; // 2
      cout << "Benutzungszähler p2: " << p2.use_count() << endl; // 2
      p2->hi();
   } // p2 wird zerstört
   cout << "Benutzungszähler p1: " << p1.use_count() << endl; // 1
   cout << " Objekt existiert noch: ";
   p1->hi();
   // Zuweisung
   shared_ptr<Ressource> p3(new Ressource(3));
   p3 = p1;  // Ressource 3 wird freigegeben (delete), danach
             // verweisen beide auf das Objekt {\tt *p1}
   p1->hi();
   p3->hi();
   //  Null-Zeiger
   shared_ptr<Ressource> nullp((Ressource*)0);
   // nullp->hi();   // Speicherzugriffsfehler!

   // STL-Container mit shared_ptr
   vector<shared_ptr<Ressource> > vec(10);
   vec.push_back(p3);
   vec[0] =  shared_ptr<Ressource>(new Ressource(4));
   vec[0]->hi();
}
