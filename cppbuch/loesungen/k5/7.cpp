/* cppbuch/loesungen/k5/7.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<cstring>
#include<cstdlib>   // enthält Prototyp von qsort()
using namespace std;

// Vergleichsfunktion für C-String-Array-Elemente
int scmp(const void *a, const void *b) {
   // Umwandlung in einen const-Zeiger auf einen C-String,
   // dh. auf (const char *)
   const char *pa = *static_cast<const char* const*>(a);
   const char *pb = *static_cast<const char* const*>(b);
   return strcmp(pa,pb);
}

int main() {
   const char* sfeld[] = {"eins","zwei","drei","vier","fünf",
                   "sechs","sieben","acht","neun","zehn"};
   size_t anzahlElemente = sizeof(sfeld)/sizeof(sfeld[0]);
   /* Quicksort wird ähnlich wie im Textbeispiel aufgerufen. Da wir 
      ein Feld von Zeigern vor uns haben, wird als Elementgröße die 
      Größe eines Zeigers  auf char übergeben: 
   */
   // Aufruf von qsort():
   //qsort(sfeld, anzahlElemente, sizeof(sfeld[0]), scmp); oder:
   qsort(sfeld, anzahlElemente, sizeof(char*), scmp);

   // ALPHABETISCHE Ausgabe des sortierten Feldes:
   for(size_t i = 0; i < anzahlElemente; ++i)
      cout << ' ' << sfeld[i];
   cout << endl;
}
