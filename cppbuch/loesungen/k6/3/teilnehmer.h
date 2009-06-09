/* cppbuch/loesungen/k6/3/teilnehmer.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef TEILNEHMER_H
#define TEILNEHMER_H
#include<string>
#include<vector>
using std::string;
using std::vector;

class Teilnehmer {
 public:
   Teilnehmer(const string& name);
   void lerntKennen(Teilnehmer& tn);
   bool kennt(const Teilnehmer& tn) const;
   void druckeBekannte() const;
   const string& gibNamen() const;
 private:
   string name;
   vector<string> dieBekannten;
};
#endif
