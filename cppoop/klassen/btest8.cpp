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
    Bsp::Bruch x;     // Bruch-Variable

    /* Versuche, den Bruch x einzulesen, und fange
     * Ausnahmen vom Typ NennerIstNull ab
     */
    try {
        int z, n;
        std::cout << "Zaehler: ";
        std::cin >> z;
        std::cout << "Nenner: ";
        std::cin >> n;
        x = Bsp::Bruch(z,n);
        std::cout << "Eingabe war: " << x << std::endl;
    }
    catch (const Bsp::Bruch::NennerIstNull&) {
        /* Programm mit einer entsprechenden
         * Fehlermeldung beenden
         */
        std::cerr << "Eingabefehler: Nenner darf nicht Null sein"
                  << std::endl;
        return EXIT_FAILURE;
    }

    // diese Stelle wird nur erreicht, wenn x erfolgreich eingelesen wurde
    //...
}
