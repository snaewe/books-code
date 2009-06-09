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
// Headerdateien
#include <iostream>
#include "kbruch.hpp"

int main()
{
    // kürzbaren Bruch deklarieren
    Bsp::KBruch x(91,39);

    // x ausgeben
    std::cout << x; 
    std::cout << (x.istKuerzbar() ? " (kuerzbar)" : " (unkuerzbar)")
              << std::endl;

    // x kürzen
    x.kuerzen();

    // x ausgeben
    std::cout << x;
    std::cout << (x.istKuerzbar() ? " (kuerzbar)" : " (unkuerzbar)") 
              << std::endl;

    // x mit 3 multiplizieren
    x *= 3;

    // x ausgeben
    std::cout << x;
    std::cout << (x.istKuerzbar() ? " (kuerzbar)" : " (unkuerzbar)") 
              << std::endl;
}
