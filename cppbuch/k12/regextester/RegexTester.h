/* cppbuch/k12/regextester/RegexTester.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef REGEX_TESTER
#define REGEX_TESTER
#include<boost/regex.hpp>
#include<string>

class RegexTester {
 public:
   RegexTester(const char* regEx, const char* teststr);
   void run();
 private:
   boost::regex rgx;
   std::string teststring;
};
#endif
