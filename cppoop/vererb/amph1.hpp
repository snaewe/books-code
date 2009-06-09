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
#ifndef AMPH_HPP
#define AMPH_HPP

// Headerdateien der Basisklassen einbinden
#include "auto.hpp"
#include "boot.hpp"

namespace Bsp {

/* Klasse Amph
 * - abgeleitet von Auto und Boot
 * - zur Weiter-Vererbung geeignet
 */
class Amph : public Auto, public Boot {
  public:
    /* Default-, int und int/int-Konstruktor
     * - mit erstem Parameter wird Auto-Konstruktor aufgerufen
     * - mit zweitem Parameter wird Boot-Konstruktor aufgerufen
     */
    Amph (int k = 0, int s = 0) : Auto(k), Boot(s) {
        // damit ist nichts mehr zu tun
    }

    // Anzahl gefahrener Kilometer und Seemeilen ausgeben
    virtual void printGefahren () {
        std::cout << "Das Amphibienfahrzeug ist " << km << " km und "
                  << sm << " sm gefahren" << std::endl;
    }

    // virtueller Destruktor (ohne Anweisungen)
    virtual ~Amph () {
    }
};

}  // namespace Bsp

#endif    // AMPH_HPP
