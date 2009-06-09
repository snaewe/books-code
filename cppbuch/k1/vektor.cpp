/* cppbuch/k1/vektor.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<algorithm>  // enthält Sortierfunktion sort()
#include<vector>     // Standard-Vektor einschließen
#include<cstddef>    //  size_t
using namespace std;

int main() {         // Programm mit typischen Vektor-Operationen
    vector<float> kosten(12);  // Tabelle mit 12 {\tt float}-Werten

    // Füllen der Tabelle mit beliebigen Daten, dabei
    // Typumwandlung {\tt int} $\rightarrow$ {\tt float}
    for(size_t i = 0; i < kosten.size(); ++i) {
        kosten[i] = static_cast<float>(150-i*i)/10.0;
    }

    // Tabelle ausgeben
    for(size_t i = 0; i < kosten.size(); ++i) {
        cout << i << ": " << kosten[i] << endl;
    }

    // Berechnung und Anzeige der Summe $\sum_{i=0}^{anzahl} kosten_i$
    float sum = 0.0;
    for(size_t i = 0; i < kosten.size(); ++i) {
        sum += kosten[i];
    }

    cout << "Summe = " << sum << endl;

    // Mittelwert anzeigen
    cout << "Mittelwert = " << sum/kosten.size() << endl;

    // Maximum anzeigen
    float maxi = kosten[0];
    for(size_t i = 1; i < kosten.size(); ++i) {
       if (maxi < kosten[i]) {
          maxi = kosten[i];
       }
    }
    cout << "Maximum = " << maxi << endl;

    // zweite Tabelle {\tt sortierteKosten} deklarieren und
    // mit der ersten initialisieren
    vector<float> sortierteKosten = kosten;

    // zweite Tabelle aufsteigend sortieren (Bubble-Sort-Variante)
    // (Natürlich gibt es auch eine Standardfunktion zum Sortieren,
    //  doch davon später (Abschnitt \ref{sortieren}).)
    for(size_t i = 1; i < sortierteKosten.size(); ++i) {
       for(size_t j = 0; j < i; ++j) {
          if (sortierteKosten[i] < sortierteKosten[j]) {
              // Elemente an {\tt i} und {\tt j} vertauschen
              float temp = sortierteKosten[i];
              sortierteKosten[i] = sortierteKosten[j];
              sortierteKosten[j] = temp;
          }
       }
    }
    // bessere Alternative, weil schneller und kürzer:
    // sort(sortierteKosten.begin(), sortierteKosten.end());

    // und ausgeben
    for(size_t i = 0; i < sortierteKosten.size(); ++i) {
        cout << i << ": " << sortierteKosten[i] << endl;
    }
}
