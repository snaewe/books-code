/* cppbuch/k29/iappl.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<list>
#include<vector>
#include<iterator>

// aufrufende Funktion
template<class Iterator>
void showLastElements(Iterator last, 
         typename std::iterator_traits<Iterator>::difference_type n) {
   typename std::iterator_traits<Iterator>::iterator_category typeobject;
   showLastElements3(last, n, typeobject);
}

   /*  Diese Funktion ruft eine überladene Variante, wobei die Auswahl,
    welche der überladenen Variante genommen wird, zur Compilierzeit
    durch den Parameter iterator_category() bestimmt wird, dessen Typ
    mit einem Iterator-Tag korrespondiert. Der dritte Parameter ist
    ein Iterator-Tag-Objekt, konstruiert durch seinen Standard-
    Konstruktor.
   */

// Erste überladene Funktion
template<class Iterator, class Distance>
void showLastElements3(Iterator last, Distance n,
                      std::bidirectional_iterator_tag) {
    Iterator temp = last;
    std::advance(temp, -n);
    while(temp != last) {
       std::cout << *temp << ' ';
       ++temp;
    }
    std::cout << std::endl;
}

/* Ein bidirektionaler Iterator erlaubt keinen wahlfreien Zugriff (random
   access) und daher keine Iterator-Arithmetik. Nur die Operatoren
   ++ und -- sind für die Bewegung möglich. Deshalb wird  advance() 
   benutzt, um n Schritte zurückzugehen und dann die restlichen
   Elemente anzuzeigen. Ein Random-Access-Iterator erlaubt
   Arithmetik, was die Implementierung dieses Falles ein wenig leichter 
   macht: */

// Zweite überladene Funktion
template<class Iterator, class Distance>
void showLastElements3(Iterator last, Distance n,
                      std::random_access_iterator_tag) {
    Iterator first = last - n;      // Arithmetik
    while(first != last) std::cout << *first++ << ' ';
    std::cout << std::endl;
}


int main( ) {
    std::list<int> L;                        // list
    for(int i = 0; i < 10; ++i) L.push_back(i);

    // Aufruf der 1. überladenen Funktion
    showLastElements(L.end(), 5L);   // 5 long

    std::vector<int> v(10);                  // vector
    for(int i = 0; i < 10; ++i) v[i] = i;
 
    // Aufruf der 2. überladenen Funktion
    showLastElements(v.end(), 5);    // 5 int

}
