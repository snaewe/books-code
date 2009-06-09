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

int main()
{
    std::vector<int> menge;    // Vektor-Container für ints

    // Elemente mit den Werten 1 bis 6 einfügen
    for (int i=1; i<=6; ++i) {
        menge.push_back(i);
    }

    // alle Elemente jeweils gefolgt von einem Leerzeichen ausgeben
    // - Iterator wandert dazu über alle Elemente
    std::vector<int>::iterator pos;
    for (pos = menge.begin(); pos != menge.end(); ++pos) {
        std::cout << *pos << ' ';
    }

    // zum Abschluss ein Zeilenende ausgeben
    std::cout << std::endl;
}
