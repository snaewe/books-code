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
#ifndef AUTO_HPP
#define AUTO_HPP

// Headerdatei für I/O einbinden
#include <iostream>

namespace Bsp {

/* Klasse Auto
 * - zur Vererbung geeignet
 */
class Auto {
  protected:
    int km;     // gefahrene Kilometer

  public:
    // Default- und int-Konstruktor
    Auto (int d = 0) : km(d) {  // gefahrene Kilometer initialisieren
    }

    // bestimmte Anzahl von Kilometern fahren
    virtual void fahre (int d) {
        km += d;        // Kilometer aufaddieren
    }

    // Anzahl gefahrener Kilometer ausgeben
    virtual void printGefahren () {
        std::cout << "Das Auto ist "
                  << km << " km gefahren" << std::endl;
    }

    // virtueller Destruktor (ohne Anweisungen)
    virtual ~Auto () {
    }
};

}  // namespace Bsp

#endif    // AUTO_HPP
