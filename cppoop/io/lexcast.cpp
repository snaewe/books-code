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
#include <string>
#include <cstdlib>
#include "lexcast.hpp"

int main (int argc, char* argv[])
{
    try {
        if (argc > 1) {
            // erstes Argument als int auswerten
            int wert = lexical_cast<int>(argv[1]);

            // int als String verwenden
            std::string msg;
            msg = "Der uebergebene Wert ist: "
                  + lexical_cast<std::string>(wert);
            std::cout << msg << std::endl;
        }
    }
    catch (const char* msg) {
        std::cerr << "Exception: " << msg << std::endl;
        return EXIT_FAILURE;
    }
}
