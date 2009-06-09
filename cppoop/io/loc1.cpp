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
#include <iostream>
#include <locale>

int main()
{
    // verwende die klassische Sprachumgebung, um Daten
    // von der Standard-Eingabe zu lesen
    std::cin.imbue(std::locale::classic());

    // verwende eine deutsche Sprachumgebung, um Daten zu schreiben
    std::cout.imbue(std::locale("de_DE"));

    // Gleitkommawerte in einer Schleife lesen und ausgeben
    double wert;
    while (std::cin >> wert) {
        std::cout << wert << std::endl;
    }
}
