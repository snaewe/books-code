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
int main()
{
    try {
        Bsp::Bruch x;
        //...
        x = liesBruch();
        //...
    }
    catch (Bsp::Bruch::Bruchfehler) {
        // main() mit Fehlermeldung und Fehlerstatus beenden
        std::cerr << "Exception durch Fehler in Klasse Bruch"
                  << std::endl;
        return EXIT_FAILURE;
    }
}
