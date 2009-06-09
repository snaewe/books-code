/* cppbuch/k9/new/eigene/Person.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef PERSON_H_
#define PERSON_H_
#include<algorithm>   // min()
#include<iostream>
#include<string>
#include<cstring>
#include"Speicherverwaltung.t"

class Person {
public:
   typedef Speicherverwaltung<Person, 100> Speicher;
   Person(const std::string& n = "N.N.") {
      strncpy(name, n.c_str(), sizeof(name)-1);
      size_t ende = std::min(n.length(), sizeof(name)-1);
      name[ende] = '\0'; 
      std::cout << "Person-Konstruktor aufgerufen (" 
                << name << ") this=" << this  << std::endl;
   }
   ~Person() {
      std::cout << "Person-Destruktor aufgerufen (" 
                << name << ") this=" << this << std::endl;
   }
   const std::string getName() const {
      return name;
   }

   static void *operator new(size_t size) {
      std::cout << "new aufgerufen. size=" << size << std::endl;
      return Speicher::getMemory(size);
   }
   static void operator delete(void* ptr) {
      std::cout << "delete aufgerufen. ptr=" << ptr << std::endl;
      Speicher::freeMemory(ptr);
   }
   static int freiePlaetze() {
      return Speicher::freiePlaetze();
   }
private:
   char name[15];
};

#endif 
