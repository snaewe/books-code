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
#include <set>

int main()
{
    std::set<int> menge;    // Set-Container für ints

    // sieben Elemente mit den Werten 1 bis 6 ungeordnet einfügen
    menge.insert(3);
    menge.insert(1);
    menge.insert(5);
    menge.insert(4);
    menge.insert(6);
    menge.insert(2);
    menge.insert(1);

    // alle Elemente jeweils gefolgt von einem Leerzeichen ausgeben
    std::set<int>::iterator pos;
    for (pos = menge.begin(); pos != menge.end(); ++pos) {
        std::cout << *pos << ' ';
    }

    // zum Abschluss ein Zeilenende ausgeben
    std::cout << std::endl;
}
