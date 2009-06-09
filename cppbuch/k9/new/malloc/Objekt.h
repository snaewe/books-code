/* cppbuch/k9/new/malloc/Objekt.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef OBJEKT_H_
#define OBJEKT_H_
#include<iostream>
#include<cstdlib>  // malloc, free
#include<new>      // bad_alloc

class Objekt {
public:
   virtual ~Objekt() {
      std::cout << "Objekt-Destruktor aufgerufen (" 
                << this << ")" << std::endl;
   }
   static void *operator new(size_t size) {
      std::cout << "new aufgerufen. size=" << size << std::endl;
      void* ptr =  malloc(size);
      if(!ptr) {
         throw std::bad_alloc();
      }
      return ptr;
   }
   static void operator delete(void *ptr, size_t size) {
      std::cout << "delete aufgerufen. size="  << size << std::endl;
      free(ptr);
   }

   static void *operator new[](size_t size) {
      std::cout << "new[] aufgerufen. size=" << size << std::endl;
      void* ptr =  malloc(size);
      if(!ptr) {
         throw std::bad_alloc();
      }
      return ptr;
   }
   static void operator delete[](void *ptr, size_t size) {
      std::cout << "delete[] aufgerufen. size="  << size << std::endl;
      free(ptr);
   }
};

#endif /*OBJEKT_H_*/
