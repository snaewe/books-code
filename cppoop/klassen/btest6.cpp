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
// Standard-Headerdateien einbinden
#include <iostream>
#include <cstdlib>

// Headerdateien für die verwendeten Klassen einbinden
#include "bruch.hpp"

int main()
{
    const Bsp::Bruch a(7,3);      // Bruch-Konstante a deklarieren
    Bsp::Bruch x;                 // Bruch-Variable x deklarieren

    std::cout << a << std::endl;  // Bruch a ausgeben

    // Bruch x einlesen
    std::cout << "Bruch eingeben (zaehler/nenner): ";
    if (! (std::cin >> x)) {
        // Eingabefehler: Programmabbruch mit Fehlerstatus
        std::cerr << "Fehler beim Bruch-Eingeben" << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "Eingabe war: " << x << std::endl;

    // solange x < 1000
    while (x < 1000) {    // neu: statt while (x < Bsp::Bruch(1000))
        // x mit a multiplizieren und ausgeben
        x = x * a;
        std::cout << x << std::endl;
    }   
}
