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
#include <map>
#include <string>

int main()
{
    // Datentyp der Menge
    typedef std::multimap<int,std::string> IntStringMMap;

    IntStringMMap menge;    // Multimap-Container für int/string-Wertepaare

    // einige Elemente ungeordnet einfügen
    // - zwei Werte haben den Schlüssel 1
    menge.insert(std::make_pair(5,"feucht"));
    menge.insert(std::make_pair(2,"besten"));
    menge.insert(std::make_pair(1,"Die"));
    menge.insert(std::make_pair(4,"sind:"));
    menge.insert(std::make_pair(5,"lang"));
    menge.insert(std::make_pair(3,"Parties"));

    /* die Werte aller Elemente ausgeben
     * - ein Iterator wandert über alle Elemente
     * - mit second wird auf den Wert der Elemente zugegriffen
     */
    IntStringMMap::iterator pos;
    for (pos = menge.begin(); pos != menge.end(); ++pos) {
        std::cout << pos->second << ' ';
    }
    std::cout << std::endl;
}
