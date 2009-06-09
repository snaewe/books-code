/* cppbuch/k9/vektor/vekmain.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// Beispiel zur Vektor-Klasse
#include <iostream>

using namespace std;

#define PRINT(X) cout << (#X) << " = " << (X) << endl
#include"vektor.t"

// globaler Operator für int-Vektoren
ostream& operator<<(ostream& os, const Vektor<int>& v) {
   // Verbesserungen im Ausgabelayout sind möglich!
   for(size_t i = 0; i < v.size(); ++i) {
      os << v[i] << '\t';
      if ((i+1)%8==0 || i==v.size()-1) os << endl;
   }
   return os;
}

int main() {
   Vektor<int> v(3, 7);
   PRINT(v);
   PRINT(v.size());
   v[0] = 1000;
   PRINT(v);

   const size_t ANZ = 16;
   cout << "Vektor bedarfsweise vergrößern:\n";
   for (size_t i = 0; i < ANZ; ++i) {
      if (i == v.size()) {   // Platz verbraucht
         v.groesseAendern(i+10);
         cout << "neu: "; PRINT(v.size());
      }
      v[i] = i * i;
   }

   cout << "nur die ersten " << ANZ
        << " Elemente sind definiert:\n";
   cout << "Ausgabeoperator: cout << v:" << endl;
   cout << v << endl;

   cout << "Vektor auf " << ANZ
        << " Elemente reduzieren:\n";
   v.groesseAendern(ANZ);
   PRINT(v);
   PRINT(v.size());
   cout << "\nProgrammabbruch mit Indexfehler provozieren:"
        << endl;
   try {
      v[v.size()] = 8;   // v.size() ist zuviel! korrekt wäre 0..(v.size()-1)
   } catch(const out_of_range& ex) {
      cout << "Exception gefangen: " << ex.what() << endl;
   }
   cout << "\nconst-Vektor erzeugen\n";
   const  Vektor<int> vc(v);
   cout << vc << endl;
   // vc[0] = 1; // nicht erlaubt für const Vektor
}



