/* cppbuch/k24/strings/kleingrosseinfach.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<cstring>
#include<locale>
#include<string>

void kleinEinfach(std::string& str) {
   for(size_t i = 0; i < str.length(); ++i) {
      str[i] = tolower(str[i]);
   }
}
void grossEinfach(std::string& str) {
   for(size_t i = 0; i < str.length(); ++i) {
      str[i] = toupper(str[i]);
   }
}
using namespace std;

int main() {
   locale::global(locale("de_DE")); // deDE global setzen
   string text("Falsches Üben von Xylophonmusik quält jeden größeren Zwerg.");
   cout << "anfangs:" << text << endl; 
   grossEinfach(text);
   cout << "grossEinfach: " << text << endl; 
   kleinEinfach(text);
   cout << "kleinEinfach: " << text << endl; 
}

