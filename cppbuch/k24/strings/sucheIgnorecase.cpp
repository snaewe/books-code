/* cppbuch/k24/strings/sucheIgnorecase.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<iostream>
#include"localeutils.t"

size_t findeSuchstringIgnoreCase1(std::string text, std::string such,
                                  const std::locale& loc = std::locale("de_DE")) {
   gross(text, loc);
   gross(such, loc);
   return text.find(such);
}

size_t findeSuchstringIgnoreCase2(const std::string& text,const std::string& such,
                                  const std::locale& loc = std::locale("de_DE")) {
   std::string::const_iterator pos = std::search(text.begin(), text.end(),
                                           such.begin(), such.end(), 
                                           EqualIgnoreCase<char>(loc));
   return pos == text.end() ? std::string::npos : (pos-text.begin());
}

using namespace std;

int main() {
   locale::global(locale("de_DE")); // deDE global setzen
   string text("Quer über den großen Sylter Deich");
   string suchstring("sYlt");
   size_t pos = findeSuchstringIgnoreCase2(text, suchstring);
   if(pos != string::npos) {
      cout << suchstring << " ist ab Position " << pos
           << " in " << text 
           << " enthalten (Groß-/Kleinschreibung ignoriert)." << endl; 
   }
   else {
      cout << suchstring << " ist nicht in " << text 
           << " enthalten." << endl; 
   }   
}

