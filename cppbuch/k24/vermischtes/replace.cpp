/* cppbuch/k24/vermischtes/replace.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<string>
#include<vector>
#include<showSequence.h>

// Unäres Prädikat als Funktor
class Zitrusfrucht {
    public:
       bool operator()(const std::string& a) {
            return  a == "Zitrone" 
                 || a == "Apfelsine"
                 || a == "Limone";
       }
};

using namespace std;

int main() {
    vector<string> obstkorb(3), kiste(3);
    obstkorb[0] = "Apfel";
    obstkorb[1] = "Apfelsine";
    obstkorb[2] = "Zitrone";
    showSequence(obstkorb); // Apfel Apfelsine Zitrone

    cout << "replace: Apfel durch Quitte ersetzen:\n";
    replace(obstkorb.begin(), obstkorb.end(),
            string("Apfel"), string("Quitte"));
    showSequence(obstkorb); // Quitte Apfelsine Zitrone

    cout << "replace_if: Zitrusfrüchte durch Pflaumen ersetzen:\n";
    replace_if(obstkorb.begin(), obstkorb.end(),
            Zitrusfrucht(), string("Pflaume"));
    showSequence(obstkorb); // Quitte Pflaume Pflaume

    cout << "replace_copy: kopieren und ersetzen der Pflaumen "
            "durch Limonen:\n";
    replace_copy(obstkorb.begin(), obstkorb.end(),
            kiste.begin(), string("Pflaume"), string("Limone"));
    showSequence(kiste);       // Quitte Limone Limone

    cout << "replace_copy_if: kopieren und ersetzen "
            "der Zitrusfrüchte durch Tomaten:\n";
    replace_copy_if(kiste.begin(), kiste.end(),
            obstkorb.begin(), Zitrusfrucht(), string("Tomate"));
    showSequence(obstkorb); // Quitte Tomate Tomate
}
