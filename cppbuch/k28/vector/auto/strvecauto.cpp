/* cppbuch/k28/vector/auto/strvecauto.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<vector>
#include<iostream>
#include<string>
using namespace std;

int main() {
     vector<string> stringVec(4);
    stringVec[0] = "First";
    stringVec[1] = "Second";
    stringVec[2] = "Third";
    stringVec[3] = "Fourth";

    // for-Schleife mit auto
    for(auto it = stringVec.begin();
        it != stringVec.end(); ++it) {
       cout << *it << endl;
    }
}
