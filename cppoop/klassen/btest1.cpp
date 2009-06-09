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
    Bsp::Bruch x;        // Initialisierung durch Default-Konstruktor
    Bsp::Bruch w(7,3);   // Initialisierung durch int/int-Konstruktor

    // Bruch w ausgeben
    w.print();

    // Bruch w wird an Bruch x zugewiesen
    x = w;

    // 1000 in einen Bruch umwandeln und w zuweisen
    w = Bsp::Bruch(1000);

    // x und w ausgeben
    x.print();
    w.print();
}
