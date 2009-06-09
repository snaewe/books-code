/* cppbuch/k9/new/zaehlend/Person.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef PERSON_H_
#define PERSON_H_
#include<iostream>
#include<string>
#include"ZaehlendesObjekt.h"

class Person : public ZaehlendesObjekt {
public:
   Person(const std::string& n) 
      : name(n) {
   }
   virtual ~Person() {
      std::cout << "Person-Destruktor aufgerufen (" 
                << name << ")" << std::endl;
   }
   const std::string& getName() const {
      return name;
   }
private:
   std::string name;
};

#endif /*PERSON_H_*/
