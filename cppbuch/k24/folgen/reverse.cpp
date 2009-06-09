/* cppbuch/k24/folgen/reverse.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<showSequence.h>

using namespace std;

int main() {
    char s0[] = "Madam";
    reverse(s0, s0 + strlen(s0));
    cout << s0 << endl;      //  madaM

    string s1("ABCDEFGH");
    reverse(s1.begin(), s1.end());
    cout << s1 << endl;      // HGFEDCBA

    vector<string> vs;
    vs.push_back("eins");
    vs.push_back("zwei");
    vs.push_back("drei");
    showSequence(vs);        // eins zwei drei
    vector<string> kopie(vs.size());
    reverse_copy(vs.begin(), vs.end(), kopie.begin());
    showSequence(kopie);     // drei zwei eins
}
