/* cppbuch/k24/strings/wkleingrossutf8.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<cstdlib> // wcstombs()
#include"localeutils.t"

// Diese Datei ist UTF-8 codiert!

void wstringAusgabe(const std::wstring& wstr) {
   const size_t MAXBYTES = 200;
   static char aus[MAXBYTES];
   std::wcstombs(aus, wstr.c_str(),MAXBYTES);
   std::cout << aus << std::endl;
}

using namespace std;

int main() {
   // wstring
   wstring wtext(L"Falsches Üben von Xylophonmusik quält jeden größeren Zwerg.");
   locale deutsch("de_DE.utf-8");
   locale::global(deutsch); // deDE.utf-8 fuer alles setzen
   cout << "anfangs:"; 
   wstringAusgabe(wtext);
   gross(wtext);
   cout << "gross: ";
   wstringAusgabe(wtext);
   klein(wtext);
   cout << "klein: ";
   wstringAusgabe(wtext);
}


