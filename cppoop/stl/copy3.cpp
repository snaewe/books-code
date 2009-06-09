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
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

int main()
{
    std::list<int>   menge1;
    std::vector<int> menge2;
    std::deque<int>  menge3;

    // Elemente 1 bis 6 in die erste Menge einfügen
    for (int i=1; i<=6; i++) {
        menge1.push_back(i);
    }

    // Elemente hinten einfügend in die zweite Menge kopieren
    std::copy (menge1.begin(), menge1.end(),    // Quellbereich
               std::back_inserter(menge2));     // Zielbereich

    // Elemente vorn einfügend in die dritte Menge kopieren
    std::copy (menge1.begin(), menge1.end(),    // Quellbereich
               std::front_inserter(menge3));    // Zielbereich
}
