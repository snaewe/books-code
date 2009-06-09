/* cppbuch/k29/algorithmenwahl.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
/* Es soll das mittlere Element eines Containers zurückgegeben
werden. Bei einer Liste müssen dazu N/2 Elemente abgeklappert
werden.
Bei einem Vektor nimmt man einfach das Element [N/2]. Die Auswahl des
passenden Algorithmus geschieht zur Compilationszeit.
 */
#include<iostream>
#include<list>
#include<vector>
#include<iterator>

/* Aufrufende Funktion.
 Diese Funktion ruft nun die korrespondierende überladene
  Variante, wobei die Auswahl zur Compilierzeit durch den
  Parameter {\tt typeobject} geschieht.
   */
template<class Iterator>
int mittleresElement(Iterator anfang, size_t n) {
   typename std::iterator_traits<Iterator>::iterator_category typeobject;
   return holeMittleres(anfang, n, typeobject);
}
// Erste überladene Funktion
template<class Iterator>
int holeMittleres(Iterator anfang, size_t n,
                     std::bidirectional_iterator_tag) {
   for(size_t i=0; i < n/2; ++i) {
      ++anfang;
   }
   return *anfang;
}
/* Der bidirektionale Iterator läßt keine wahlfreien Zugriffe und damit
keine Itera\-tor\-arith\-metik zu. Zur Bewegung sind nur die Operatoren {\tt
++} und {\tt -\relax-} erlaubt. .
Ein Random-Access-Iterator erlaubt Arithmetik, sodass die
Implementation für diesen Fall etwas einfacher ist: */

// Zweite überladene Funktion
template<class Iterator>
int holeMittleres(Iterator anfang, size_t n,
                      std::random_access_iterator_tag) {
   return *(anfang + n/2);     // Arithmetik
}

// Hauptprogramm
using namespace std;

int main( ) {
    list<int> lis;               // list
    for(size_t i=0; i < 10; ++i) {          // mit Werten füllen
        lis.push_back(i);
    }
    vector<int> vec(10);                  // vector
    for(size_t i = 0; i < vec.size(); ++i) {  // mit Werten füllen
       vec[i] = 10*i;
    }
    // Aufruf der ersten Implementierung
    cout << mittleresElement(lis.begin(), lis.size()) << endl;

    // Aufruf der zweiten Implementierung
    cout << mittleresElement(vec.begin(), vec.size()) << endl;
}
