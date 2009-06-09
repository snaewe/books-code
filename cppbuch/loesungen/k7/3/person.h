/* cppbuch/loesungen/k7/3/person.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef PERSON_H
#define PERSON_H
#include<string>
using std::string;

class Person {
 public:
   Person(const string& n, const string& v)
      : nachname(n), vorname(v) {
   }
   const string& getNachname() const { return nachname;}
   const string& getVorname() const { return vorname;}
   virtual string toString() const = 0;
   virtual ~Person(){}
 private:
   string nachname;
   string vorname;
};

// Die Standardimplementierung einer rein virtuellen Methode 
// muss nach [ISO98] auﬂerhalb der Klassendefinition stehen:
inline string Person::toString() const { 
      return vorname + " " + nachname;
}
#endif
