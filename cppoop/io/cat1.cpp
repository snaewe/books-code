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
#include <fstream>
#include <iostream>
using namespace std;

/* für alle in der Kommandozeile übergebenen Dateinamen
 * - Datei öffnen, Inhalt ausgeben und Datei schließen
 */
int main (int argc, char* argv[])
{
    // Datei-Stream zum Lesen anlegen (ohne eine Datei zu öffnen)
    std::ifstream datei;

    // für alle Argumente aus der Kommandozeile
    for (int i=1; i<argc; ++i) {

        // Datei öffnen
        datei.open(argv[i]);

        // Inhalt der Datei ausgeben
        char c;
        while (datei.get(c)) {
            std::cout.put(c);
        }

        // eofbit und failbit löschen (wurden wegen EOF gesetzt)
        datei.clear();

        // Datei schließen
        datei.close();
    }
}
