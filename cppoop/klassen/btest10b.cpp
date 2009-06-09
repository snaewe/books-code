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
Bsp::Bruch liesBruch ()
{
    Bsp::Bruch x;         // Bruch-Variable
    bool       fehler;    // Fehler aufgetreten?

    do {
        fehler = false;   // zunächst mal kein Fehler

        /* Versuche, den Bruch x einzulesen, und fange
         * Fehler vom Typ NennerIstNull ab
         */
        try {
            std::cout << "Bruch eingeben (zaehler/nenner): ";
            std::cin >> x;
            std::cout << "Eingabe war: " << x << std::endl;
        }
        catch (const Bsp::Bruch::NennerIstNull&) {
            /* Fehlermeldung ausgeben und Schleife nochmal
             */
            std::cout << "Eingabefehler: Nenner darf nicht Null sein"
                      << std::endl;
            fehler = true;
        }
    } while (fehler);

    return x;             // eingelesenen Bruch zurückliefern
}
