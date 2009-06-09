/* cppbuch/k24/strings/boost/boostlexicalcast.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<cstdlib>
#include<boost/lexical_cast.hpp>

using namespace std;

int main() {
   try {
      cout << "Bitte Zahl eingeben (wird als char[] gespeichert): ";
      char eingabe[80];
      cin >> eingabe;
      cout << "Umwandlung von char[] -> double: " <<
         boost::lexical_cast<double>(eingabe) << endl;
      string s(eingabe);
      cout << "Umwandlung von string -> double: " <<
         boost::lexical_cast<double>(s) << endl;
      cout << "Bitte Zahl eingeben (wird als double gespeichert): ";
      double z;
      cin >> z;
      cout << "Umwandlung von double ->  string: " <<
         boost::lexical_cast<string>(z) << endl;
   }
   catch(boost::bad_lexical_cast & blc) {
      cerr << blc.what() << endl;
   }
}
