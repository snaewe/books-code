/* Die folgenden Code-Beispiele stammen aus dem Buch:
 *  Objektorientiertes Programmieren in C++
 *   Ein Tutorial für Ein- und Umsteiger
 * von Nicolai Josuttis, Addison-Wesley München, 2001
 *
 * (C) Copyright Nicolai Josuttis 2001.
 * Diese Software darf kopiert, verwendet, modifiziert und verteilt
 * werden, sofern diese Copyright-Angabe in allen Kopien vorhanden ist.
 * Diese Software wird "so wie sie ist" zur Verfügung gestellt.
 * Es gibt keine explizite oder implizite Garantie über ihren Nutzen.
 */
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

int add10 (int elem)
{
    return elem + 10;
}

int main()
{
    std::set<int>    coll1;
    std::vector<int> coll2;

    // Elemente mit den Werten 1 bis 9 in coll1 einfügen
    for (int i=1; i<=9; ++i) {
        coll1.insert(i);
    }

    // Elemente in coll1 ausgeben
    copy (coll1.begin(), coll1.end(),                  // Quelle: coll1
          std::ostream_iterator<int>(std::cout," "));  // Ziel: cout
    std::cout << std::endl;

    // jedes Element in coll1 nach coll2 transformieren
    // - dabei jeweils 10 addieren
    transform (coll1.begin(),coll1.end(),    // Quelle
               std::back_inserter(coll2),    // Ziel (einfügend)
               add10);                       // Operation

    // Elemente in coll2 ausgeben
    copy (coll2.begin(), coll2.end(),                  // Quelle: coll1
          std::ostream_iterator<int>(std::cout," "));  // Ziel: cout
    std::cout << std::endl;

}
