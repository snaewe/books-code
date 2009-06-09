/* cppbuch/loesungen/k7/3/prof.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef PROF_H
#define PROF_H
#include"person.h"
#include<string>
using std::string;

class ProfessorIn : public Person {
 public:
   ProfessorIn(const string& nachname, const string& vorname,
               const string& lgb)
      : Person(nachname, vorname), lehrgebiet(lgb) {
   }
   const string& getLehrgebiet() const { 
      return lehrgebiet;
   }
   virtual string toString() const { 
      return "Prof. " + Person::toString()
         + ", Lehrgebiet: " + lehrgebiet;
   }
   virtual ~ProfessorIn(){}
 private:
   string lehrgebiet;
};
#endif
