/* cppbuch/k12/regextester/testRegex.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <iostream>
#include "RegexTester.h"


void testfaelle() {
   const char* testfaelle[][2] = 
      {{"^\\D+([0-9]+) \\1", "Sommer 2009 2009"},
       {"[a-c]+", "zcbaaxcadey"},
       {"\\t", "enthaelt	Tabulator"},
       {"[a-c]*", "z"},                       // greedy
       {"[^aeiou]+", "hallo"},
       {"/\\*.*\\*/", "xyz /* hallo */ abc */ 123"},  // greedy
       {"/\\*.*?\\*/", "xyz /* hallo */ abc */ 123"}  // nicht greedy
      };
   for (size_t i = 0; i < sizeof testfaelle/sizeof testfaelle[0]; ++i) {
      RegexTester rt(testfaelle[i][0], testfaelle[i][1]);
      rt.run();
      std::cout << std::endl;

   }
}

using namespace std;

int main(int argc, char* argv[])  {
   if(3 != argc) {
      testfaelle();
      cout << "Gebrauch: testRegex.exe \"regex\" \"teststring\"" << endl
           << "ansonsten werden eingebaute Testfälle ausgegeben." << endl;
   }
   else {
      try {
         RegexTester rt(argv[1], argv[2]);
         rt.run();
      } catch(boost::regex_error& re) {
         std::cerr << "Fehler: " << re.what() << std::endl;
      }
   }
}
