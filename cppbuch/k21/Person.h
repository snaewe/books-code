/* cppbuch/k21/Person.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef PERSON_H_
#define PERSON_H_
#include<iostream>
#include<set>
#include<string>

class Person {
public:
   Person(const std::string& name) :
      name_(name) {
   }
   virtual ~Person() {
   }
   const std::string& getName() const {
      return name_;
   }
   void lerntkennen(Person& p) {
     bool nichtvorhanden = bekannte.insert(p.getName()).second;
      if (nichtvorhanden) { // falls unbekannt, auch bei p eintragen
         p.lerntkennen(*this);
      }
   }
   void bekannteZeigen() const {
      std::cout << "Die Bekannten von " << getName() << " sind:" << std::endl;
      for (std::set<std::string>::iterator iter = bekannte.begin(); iter
            != bekannte.end(); ++iter) {
         std::cout << *iter << std::endl;
      }
   }
private:
   std::string name_;
   std::set<std::string> bekannte;
};

#endif /*PERSON_H_*/
