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
#include <iostream>    // C++-Headerdatei für Ein-/Ausgaben
#include <string>      // C++-Headerdatei für Strings

int main ()
{
    const std::string anfang("http:");       // Beginn eines Links
    const std::string trenner(" \"\t\n<>");  // Zeichen, die den Link beenden
    std::string zeile;                       // aktuelle Zeile
    std::string link;                        // aktueller HTML-Link
    std::string::size_type anfIdx, endIdx;   // Indizes

    // für jede erfolgreich gelesene Zeile
    while (getline(std::cin,zeile)) {
        // suche erstes Vorkommen von "http:"
        anfIdx = zeile.find(anfang);

        // solange "http:" in der Zeile gefunden wurde,
        while (anfIdx != std::string::npos) {
            // Ende des Links finden
            endIdx = zeile.find_first_of(trenner,anfIdx);

            // Link extrahieren
            if (endIdx != std::string::npos) {
                // Ausschnitt von gefundenem Anfang bis gefundenem Ende
                link = zeile.substr(anfIdx,endIdx-anfIdx);
            }
            else {
                // Kein Ende gefunden: Rest der Zeile
                link = zeile.substr(anfIdx);
            }

            // Link ausgeben
            // - "http:" ohne weitere Zeichen ignorieren
            if (link != "http:") {
                link = string("Link: ") + link;
                std::cout << link << std::endl;
            }

            // weiteren Link in der Zeile suchen
            if (endIdx != std::string::npos) {
                // suche weiteres Vorkommen von "http:" ab gefundenem Ende
                anfIdx = zeile.find(anfang,endIdx);
            }
            else {
                // Ende war Zeilenende: kein neuer Anfang in der Zeile auffindbar
                anfIdx = std::string::npos;
            }
        }
    }
}
