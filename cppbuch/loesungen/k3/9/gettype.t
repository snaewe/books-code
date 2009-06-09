/* cppbuch/loesungen/k3/9/gettype.t
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef GETTYPE_T
#define GETTYPE_T
#include<string>
using std::string;  

// Template
template<typename T>
string getType(T t) { return "unbekannter Typ";}

// Template-Spezialisierungen
template<> string getType(int t) { return "int";}
template<> string getType(unsigned int t) { return "unsigned int";}
template<> string getType(double t) { return "double";}
template<> string getType(char t) { return "char";}
template<> string getType(bool t) { return "bool";}

#endif
