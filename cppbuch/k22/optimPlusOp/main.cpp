/* cppbuch/k22/optimPlusOp/main.cpp
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
   cout << "\n Fall 5 : MeinString neu = b + c;" << endl;
   MeinString neu = b + c;
   cout << "\n Fall 6 :  neu = a + \"eins\" + \"zwei\" + \"drei\";" << endl;
   neu = a+ "eins" + "zwei" + "drei";
   cout << "\na  = " << a << endl;
   cout << "b  = " << b << endl;
   cout << "c  = " << c << endl;
   cout << "neu= " << neu << endl;
   cout << "\n Fall 7 : neu = a + b + c + neu;" << endl;
   neu = a + b + c + neu;
   cout << "a  = " << a << endl;
   cout << "b  = " << b << endl;
   cout << "c  = " << c << endl;
   cout << "neu= " << neu << endl;
   neu.verketten(a, b);
   cout << "neu nach verketten= " << neu << endl;
   neu = a + b + c;
}
