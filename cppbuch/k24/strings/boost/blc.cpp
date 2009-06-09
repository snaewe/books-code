/* cppbuch/k24/strings/boost/blc.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<string>
#include<boost/lexical_cast.hpp>

using namespace std;

int main() {
   try {
      cout << "Bitte Zahl eingeben (Zeile wird als String gespeichert): ";
      string eingabe;
      getline(cin, eingabe);
      cout << "Umwandlung von string -> double: " <<
         boost::lexical_cast<double>(eingabe) << endl;
   }
   catch(boost::bad_lexical_cast & blc) {
      cerr << blc.what() << endl;
   }
}
