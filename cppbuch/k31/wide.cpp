/* cppbuch/k31/wide.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib> // wcstombs()
#include<locale>
using namespace std;

// Diese Datei ist UTF-8 codiert!  //

int main() {
   locale dt("de_DE.utf-8");
   cout << "dt.name()= " << dt.name() << endl;
   locale::global(dt); // dt fuer alles setzen
   // wstring
   wstring ws(L"ÄÖÜäöüß");
   wcout.imbue(dt);
   wcout << "Ausgabe mit wcout: " << ws << endl;
   cout << "Länge=" << ws.length() << endl;
   cout << "sizeof(wchar_t): " << sizeof(wchar_t) << endl; 
   wofstream meinWcout("ausgabe.txt");
   meinWcout << "Ausgabe mit in wofstream: " << ws << endl;
   for(size_t i = 0; i < ws.length(); ++i) {
      meinWcout << "WZeichen " << i << ": "
                << ws[i] << endl; 
   }
   for(size_t i = 0; i < ws.length(); ++i) {
      ws[i] =  toupper(ws[i], dt);
   }
   wcout << ws << " nach toupper()" << endl;  // siehe Text

   size_t anzahlbytes = 2 * ws.length()+1; // reicht für Variable ws
   char * aus = new char[anzahlbytes];
   wcstombs(aus, ws.c_str(),anzahlbytes);
   cout << "nach wcstombs(): " << aus << endl;  // ok 
}

