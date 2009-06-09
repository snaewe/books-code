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
#include <iostream>    // C++-Headerdatei für Ein-/Ausgaben
#include <string>      // C++-Headerdatei für Strings

int main (int argc, char* argv[])
{
    // Programmname und Anzahl der Parameter ausgeben
    std::string progname = argv[0];
    if (argc > 1) {
        std::cout << progname << " hat " << argc-1 << " Parameter: "
                  << std::endl;
    }
    else {
        std::cout << progname << " wurde ohne Parameter aufgerufen"
                  << std::endl;
    }

    // Programmparameter ausgeben
    for (int i=1; i<argc; ++i) {
        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    }
}
