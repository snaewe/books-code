/* cppbuch/k22/bewegCtor/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"meinstring.h"
#include<iostream>
using namespace std;

int main() {
   MeinString a("einA");
   MeinString b("einB");
   MeinString c("einC");
   cout << " Fall 1 : a = \"Hallo\" + b;" << endl;
   a = "Hallo" + b;
   cout << "\n Fall 2 :  a = b + \" hallo\";" << endl;
   a = b + " hallo";
   cout << "\n Fall 3 : a = MeinString(\"guten\") + \" Tag\";" << endl;
   a = MeinString("guten") + " Tag";
   cout << "\n Fall 4 : a = b + c;" << endl;
   a = b + c;


   

}
