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
// Headerdateien für die verwendeten Klassen einbinden
#include "bruch.hpp"

int main()
{
    Bsp::Bruch x;             // Bruch x deklarieren
    Bsp::Bruch w(7,3);        // Bruch w deklarieren

    // Bruch w ausgeben
    w.print();

    // x das Quadrat von w zuweisen
    x = w * w;

    // solange x < 1000
    while (x < Bsp::Bruch(1000)) {

        // x mit a multiplizieren
        x *= w;

        // und ausgeben
        x.print();
    }
}

