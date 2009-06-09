/* cppbuch/k24/vermischtes/transform.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<cstddef>
#include<cctype>
#include<locale>
#include<string>
#include<vector>
#include<showSequence.h>

std::string upper_case(std::string s) {   // un‰re Operation als Funktion
   for(size_t i = 0; i < s.length(); ++i) 
      s[i] = toupper(s[i]);
   return s;
}

class Verketten {              //  bin‰re Operation als Funktor
public:
   std::string operator()(const std::string& a, const std::string& b) {
      return a + " und " + b;
   }
};

using namespace std;

int main() {
   locale::global(locale("de_DE"));  // falls Umlaute vorkommen
   const size_t ANZAHL  = 3;
   vector<string> maedels(ANZAHL), 
      jungs(ANZAHL),
      paare(ANZAHL);
   maedels[0] = "Annabella";
   maedels[1] = "Scheherazade";
   maedels[2] = "Julia";

   jungs[0]  = "Nikolaus";
   jungs[1]  = "Amadeus";
   jungs[2]  = "Romeo";

   transform(jungs.begin(), jungs.end(),
             jungs.begin(),   // Ziel == Quelle
             upper_case);     // in Groﬂbuchstaben wandeln

   transform(maedels.begin(), maedels.end(),
             jungs.begin(), paare.begin(),
             Verketten());

   showSequence(paare, "", "\n"); // gebildete Paare ausgeben
}
