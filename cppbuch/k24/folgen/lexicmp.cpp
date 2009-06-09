/* cppbuch/k24/folgen/lexicmp.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<iostream>
#include<functional>
using namespace std;

char text1[] = "Arthur";
int length1  = sizeof(text1);
char text2[] = "Vera";
int length2  = sizeof(text2);

int main () {
  if(lexicographical_compare(
            text1, text1 + length1,
            text2, text2 + length2)) {
    cout << text1 << " kommt vor " << text2 << endl;
  }
  else {
    cout << text2 << " kommt vor " << text1 << endl;
  }
  if(lexicographical_compare(
            text1, text1 + length1,
            text2, text2 + length2,
            greater<char>())) {     // umgekehrte Reihenfolge
    cout << text1 << "  kommt nach " << text2 << endl;
  }
  else {
    cout << text2 << "  kommt nach " << text1 << endl;
  }
}
