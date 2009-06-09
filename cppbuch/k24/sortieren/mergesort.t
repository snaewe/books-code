/* cppbuch/k24/sortieren/mergesort.t
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>

template<class ForwardIterator, class OutputIterator>
   void mergesort(ForwardIterator first,
                  ForwardIterator last,
                  OutputIterator result) {
   typename std::iterator_traits<ForwardIterator>::difference_type 
      n    = std::distance(first, last),
      haelfte = n/2;
   ForwardIterator mitte = first;
   std::advance(mitte, haelfte);
   if(haelfte > 1)            // linke Hälfte sortieren, falls notwendig
      mergesort(first, mitte, result);  // Rekursion
   if(n - haelfte > 1) {               // rechte Hälfte sortieren, falls notwendig
      OutputIterator ergebnis = result;
      std::advance(ergebnis, haelfte);
      mergesort(mitte, last, ergebnis);  // Rekursion
   }
   // beide Hälften mischen und zurückkopieren
   //OutputIterator end =  std::merge(first, mitte, mitte, last, result);
   // std::copy(result, end, first);
   // oder zusammengefasst:
   copy(result, merge(first, mitte, mitte, last, result), first);
}
