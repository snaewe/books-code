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
#ifndef BOOT_HPP
#define BOOT_HPP

// Headerdatei für I/O einbinden
#include <iostream>

namespace Bsp {

/* Klasse Boot
 * - zur Vererbung geeignet
 */
class Boot {
  protected:
    int sm;     // gefahrene Seemeilen

  public:
    // Default- und int-Konstruktor
    Boot (int d = 0) {
        sm = d;         // gefahrene Seemeilen initialisieren
    }

    // bestimmte Anzahl von Seemeilen fahren
    virtual void fahre (int d) {
        sm += d;        // Seemeilen aufaddieren
    }

    // Anzahl gefahrener Seemeilen ausgeben
    virtual void printGefahren () {
        std::cout << "Das Boot ist "
                  << sm << " sm gefahren" << std::endl;
    }

    // virtueller Destruktor (ohne Anweisungen)
    virtual ~Boot () {
    }
};

}  // namespace Bsp

#endif    // BOOT_HPP
