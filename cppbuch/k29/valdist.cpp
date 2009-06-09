/* cppbuch/k29/valdist.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// Bestimmung von Wert- und Distaz-Typ
#include<showSequence.h>
#include<list>
#include<vector>
#include<iterator>

template<class BidirectionalIterator>
void reverseIt(BidirectionalIterator first,
               BidirectionalIterator last,
               std::bidirectional_iterator_tag) {
   // difference_type wird zur Berechnung der Anzahl der Vertauschungen
   // verwendet. difference_type wird vom Iteratortyp abgeleitet:
   typename std::iterator_traits<BidirectionalIterator>::difference_type
      n = std::distance(first, last) -1; 

   while(n > 0) {
      // Auch der Werttyp wird vom Iteratortyp abgeleitet:
      typename std::iterator_traits<BidirectionalIterator>::value_type
         temp = *first;      
      *first++ = *--last;
      *last = temp;
      n -= 2;
   }
}

/* Die zweite Implementation benutzt Arithmetik, um die Entfernung (=
Anzahl der Vertauschungen) zu berechnen. Dies geht nur mit
Random-Access-Iteratoren.
*/
template<class RandomAccessIterator>
void reverseIt(RandomAccessIterator first,
               RandomAccessIterator last,
               std::random_access_iterator_tag) {
   // difference_type wird zur Berechnung der Anzahl der Vertauschungen
   // verwendet. difference_type wird vom Iteratortyp abgeleitet:
   typename std::iterator_traits<RandomAccessIterator>::difference_type
      n = last -first -1; // arithmetic! 

   while(n > 0) {
      // Auch der Werttyp wird vom Iteratortyp abgeleitet:
      typename std::iterator_traits<RandomAccessIterator>::value_type
         temp = *first;      
      *first++ = *--last;
      *last = temp;
      n -= 2;
   }
}

template<class BidirectionalIterator>
void reverseIt(BidirectionalIterator first,
               BidirectionalIterator last) {
   typename std::iterator_traits<BidirectionalIterator>
      ::iterator_category typeobject;
   /* Die Reihenfole umzudrehen bedeutet, dass ein Element temporär
      gespeichert werden muss. Dazu muss sein Typ bekannt sein. Entsprechend 
      dem erprobten Schema ruft die Funktion die für diesen Iteratortyp 
      passende Implementation auf:
   */
   reverseIt(first, last, typeobject);
}

int main() {
   const size_t ANZAHL = 10;

   std::list<int> L;
   for(size_t i = 0; i < ANZAHL; ++i) L.push_back(i);
   reverseIt(L.begin(), L.end());
   showSequence(L);

   std::vector<double> V(ANZAHL);
   for(size_t i = 0; i < ANZAHL; ++i) V[i] = i/20.;
   reverseIt(V.begin(), V.end());
   showSequence(V);

   // C-Array und Ausnutzung der partiellen Spezialisierung
   // iterator_traits<int*>
   int tabelle[ANZAHL];
   for(size_t i = 0; i < ANZAHL; ++i) tabelle[i] = i;
   // Zeiger statt Iteratoren übergeben
   reverseIt(tabelle, tabelle + ANZAHL);
   // showSequence(tabelle) geht nicht, weil es C-Arrays keine
   // Methoden haben, also auch nicht begin() und end()
   for(size_t i = 0; i < ANZAHL; ++i) {
      std::cout << tabelle[i] << ' ';
   }
   std::cout << std::endl;
}
