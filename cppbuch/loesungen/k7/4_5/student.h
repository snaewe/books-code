/* cppbuch/loesungen/k7/4_5/student.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef STUDENT_H
#define STUDENT_H
#include"person.h"
#include<string>
using std::string;

class StudentIn : public Person {
 public:
   StudentIn(const string& name, const string& vorname,
             const string& matnr)
      : Person(name, vorname), matrikelnummer(matnr) {
   }
   const string& getMatrikelnummer() const { 
      return matrikelnummer;
   }
   virtual string toString() const { 
      return "Student/in " + Person::toString()
         + ", Mat.Nr.: " + matrikelnummer;
   }
   virtual ~StudentIn(){}
 private:
   string matrikelnummer;
};
#endif
