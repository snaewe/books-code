/* cppbuch/k24/strings/kleingross.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include"localeutils.t"
using namespace std;

int main() {
   locale::global(locale("de_DE")); // deDE global setzen
   string text("Falsches Üben von Xylophonmusik quält jeden größeren Zwerg.");
   cout << "anfangs:" << text << endl; 
   gross(text);
   cout << "gross: " << text << endl; 
   klein(text);
   cout << "klein: " << text << endl; 
}

