/* cppbuch/k24/textverarbeitung/codeformatter.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int main(int argc, char* argv[]) {
   if(argc != 3) {
      cerr << "Gebrauch: codeformatter eingabe.cpp ausgabe.cpp" << endl;
      return 1;
   }
   bool warEOL = true;  // war letztes Zeichen Zeilenende?
   size_t level = 0;
   ifstream is(argv[1]);
   ofstream os(argv[2]);
   char c;
   while(is.good()) {
      do {  // nächstes Zeichen lesen, ggf. Leerzeichen schlucken
         is.get(c);
      } while(is.good() && warEOL && (c == ' ' || c == '\t'));
      if(is.good()) {
         if (c == '}')
            --level;           
         if (warEOL) {
            size_t leveltmp = level+1;
            while (--leveltmp > 0) 
               os.write("   ", 3);                
         }
         os.put(c);
         warEOL = (c == '\n');
         if (c == '{')
            ++level;
      }
   }
}
