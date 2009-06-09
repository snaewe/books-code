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
// Headerdatei für I/O mit Streams
#include <iostream>

// allgemeine Headerdatei für EXIT_FAILURE
#include <cstdlib>

int main()
{
    int x, y;

    // Start-String ausgeben
    std::cout << "Ganzzahlige Division (x/y)\n\n";

    // x einlesen
    std::cout << "x: ";
    if (! (std::cin >> x)) {
        /* Fehler beim Einlesen
         * => Fehlermeldung und Programmabbruch mit Fehlerstatus
         */
        std::cerr << "Fehler beim Einlesen eines Integers"
                  << std::endl;
        return EXIT_FAILURE;
    }

    // y einlesen
    std::cout << "y: ";
    if (! (std::cin >> y)) {
        /* Fehler beim Einlesen
         * => Fehlermeldung und Programmabbruch mit Fehlerstatus
         */
        std::cerr << "Fehler beim Einlesen eines Integers"
                  << std::endl;
        return EXIT_FAILURE;
    }

    // Fehler, falls y null ist
    if (y == 0) {
        /* Division durch null
         * => Fehlermeldung und Programmabbruch mit Fehlerstatus
         */
        std::cerr << "Fehler: Division durch 0" << std::endl;
        return EXIT_FAILURE;
    }

    // Operanden und Ergebnis ausgeben
    std::cout << x << " durch " << y << " ergibt "
              << x / y << std::endl;
}
