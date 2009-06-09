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
#include <deque>
#include <string>

int main()
{
    std::deque<std::string> menge;    // Deque-Container für strings

    // Elemente jeweils vorn einfügen
    menge.push_front("oefter");
    menge.push_front("immer");
    menge.push_front("aber");
    menge.push_front("immer");
    menge.push_front("nicht");

    // alle Elemente jeweils gefolgt von einem Leerzeichen ausgeben
    for (unsigned i=0; i<menge.size(); ++i) {
        std::cout << menge[i] << ' ';
    }

    // zum Abschluss ein Zeilenende ausgeben
    std::cout << std::endl;
}
