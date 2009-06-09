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
#include <algorithm>
#include <string>

int main()
{
    std::vector<std::string> menge;            // Container für Strings
    std::vector<std::string>::iterator pos;    // Iterator

    // Verschiedene Städtenamen einfügen
    menge.push_back("Hamburg");
    menge.push_back("München");
    menge.push_back("Berlin");
    menge.push_back("Braunschweig");
    menge.push_back("Duisburg");
    menge.push_back("Leipzig");

    // alle Elemente aufsteigend sortieren
    std::sort (menge.begin(), menge.end());

    /* "Hannover" vor "Hamburg" einfügen
     * - Position von "Hamburg" suchen
     * - "Hannover" davor einfügen
     */
    pos = find (menge.begin(), menge.end(),    // Bereich
                "Hamburg");                    // Suchkriterium
    if (pos != menge.end()) {
        menge.insert(pos,"Hannover");
    }
    else {
        std::cerr << "Huch, Hamburg ist gar nicht vorhanden"
                  << std::endl;
        menge.push_back("Hannover");
    }

    // alle Elemente ausgeben
    for (pos=menge.begin(); pos!=menge.end(); ++pos) {
        std::cout << *pos << ' ';
    }
    std::cout << std::endl;
}
