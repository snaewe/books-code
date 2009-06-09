/* cppbuch/k12/regextester/RegexTester.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <iostream>
#include "RegexTester.h"

RegexTester::RegexTester(const char* regEx, const char* teststr) 
      : rgx(regEx), teststring(teststr) {
}

void RegexTester::run() {
   boost::sregex_iterator erster(teststring.begin(), teststring.end(), rgx), 
      letzter;
   std::cout << "Regex: " << rgx  
             << "  Teststring: " << teststring << std::endl;
   if (erster == letzter) {
      std::cout << "nichts gefunden" << std::endl;
   }
   else {
      while(erster != letzter) {
         boost::match_results<std::string::const_iterator> 
            ergebnis = *erster++;
         for(size_t i = 0; i < ergebnis.size(); ++i) {
            if(i > 0) {
               std::cout << "Capturing Group " << i << ": ";
            }
            std::cout << "\"" << ergebnis.str(i) << "\" gefunden. Position "   
                      << ergebnis.position(i);
            if(ergebnis.length(i) > 1) {
               std::cout << " bis " 
                         << ergebnis.position(i) + ergebnis.length(i)-1;
            }
            std::cout << std::endl;
         }
      }
   }
}

