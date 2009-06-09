/* cppbuch/loesungen/k3/3.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<vector>
using namespace std;

// Mit Ausgabe der Scheiben-Nr.
void bewegen(int n, int quell, int arbeit, int ziel) {
   vector<int> stab(3);
   stab[0] = quell;
   stab[1] = ziel;
   stab[2] = arbeit;

   size_t gesamtZahlDerBewegungen = (1 << n) -1 ; // 2**n - 1 berechnen

   for(size_t bewegung = 1; bewegung <= gesamtZahlDerBewegungen; 
       ++bewegung) {
      int k = bewegung;
      // Die zu bewegende Scheibe ist 1 + die höchste 
      // Potenz von 2, die bewegung teilt 
      int scheibe = 1;
      while ((k & 1) == 0) {   // gerade
         k >>= 1;              // /2
         ++scheibe;
      }
      int bewegungenDerScheibe = k / 2;

      // Eine Scheibe macht entweder einen einfachen oder
      // einen doppelten Schritt im Zyklus 1231.., abhängig
      // von der Parität von (n+scheibe). Der doppelte Schritt
      // kann bei drei zyklisch angeordneten Stäben auch als ein 
      // Schritt rückwärts angesehen werden bzw. entgegen der 
      // Uhrzeigerrichtung.
      // Jedes zweite Mal wird die erste Scheibe bewegt.
      // Jedes andere zweite Mal wird kann es nur eine mögliche
      // Bewegung geben, nämlich die kleinere der beiden anderen
      // obenliegenden Scheiben auf die größere zu legen.

      int schritt = 2 - (n + scheibe) % 2;
      int von = (bewegungenDerScheibe * schritt) % 3;
      int nach = (von + schritt) % 3;
      cout << "Bringe Scheibe " << scheibe << " von " << stab[von]
           << " nach " << stab[nach] << endl;
   }
}

/*
Eine Internet-Recherche ergab eine Variante [Rho00], die die Nummer 
der gerade zu bewegenden Scheibe nicht ermittelt, aber sehr kompakt
ist. Außerdem sind bei ungeradem  n im Vergleich zur obigen 
Funktion in der Ausgabe die Rollen des Arbeits- und Zielstapels vertauscht, 
weswegen hier am Anfang eine Korrektur eingebaut wurde.
Found on the web, and then improved by Glenn C. Rhoads, siehe
http://hanoitower.mkolar.org/shortestTHalgo.html
 */
void bewegen(int n) {
   vector<int> stab(3);
   stab[0] = 1;
   stab[1] = (n % 2 == 0) ? 2 : 3;
   stab[2] = (n % 2 == 0) ? 3 : 2;
   size_t gesamtZahlDerBewegungen = (1 << n) -1 ; // 2**n - 1 berechnen
   for (size_t i=1; i <= gesamtZahlDerBewegungen; ++i) {
      cout << "Bringe Scheibe von " <<  stab[(i&(i-1))%3]
           << " nach " << stab[((i|(i-1))+1)%3]  << endl;
   }
}

int main() {
   cout << "Türme von Hanoi! Anzahl der Scheiben: ";
   int scheiben;
   cin >> scheiben;
   bewegen(scheiben, 1, 2 ,3);
   cout << "2. Lösung : " << endl;
   bewegen(scheiben);
}
