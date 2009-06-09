/* cppbuch/k9/new/zaehlend/ZaehlendesObjekt.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef ZAEHLENDESOBJEKT_H
#define ZAEHLENDESOBJEKT_H
#include<iostream>
#include<string>
#include<set>

class ZaehlendesObjekt {
public:
   ZaehlendesObjekt() {
      ++gesamt;
      istHeapObjekt = (1 == objekte.count(this));
      std::cout << (istHeapObjekt ? "Heap" : "Stack") 
                << "-Objekt " << this << " erzeugt." << std::endl;
   }
   virtual ~ZaehlendesObjekt() {
      --gesamt;
      std::cout << (istHeapObjekt ? "Heap" : "Stack") 
                << "-Objekt " << this << " zerstört." << std::endl;
   }
   static void status() {
      std::cout << "Es gibt " << gesamt << " Objekt(e), davon "
                << objekte.size() << " Heap-Objekt(e)" << std::endl;
   }
   static void *operator new(size_t size) {
      void* ptr = ::operator new(size);
      objekte.insert(ptr);
      return ptr;
   }
   static void operator delete(void *ptr) {
      objekte.erase(ptr);
      ::operator delete(ptr);
   }
private:
   bool istHeapObjekt;
   static std::set<void*> objekte;
   static int gesamt;
};

#endif 
