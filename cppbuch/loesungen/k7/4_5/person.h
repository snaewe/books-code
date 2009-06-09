/* cppbuch/loesungen/k7/4_5/person.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef PERSON_H
#define PERSON_H
#include<string>
using std::string;

class Person {
 public:
   Person(const string& nachname, const string& vorname)
      : Nachname(nachname), Vorname(vorname) {
   }
   const string& getNachname() const { return Nachname;}
   const string& getVorname() const { return Vorname;}
   virtual string toString() const = 0;
   virtual ~Person(){}
 private:
   string Nachname;
   string Vorname;
};

// Die Standardimplementierung einer rein virtuellen Methode 
// muss nach [ISO98] auﬂerhalb der Klassendefinition stehen:
inline string Person::toString() const { 
      return Vorname + " " + Nachname;
}
#endif
