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
#include <string>       // für Strings
#include <iostream>     // für I/O
#include <fstream>      // für Datei-I/O
#include <iomanip>      // für setw()
#include <cstdlib>      // für EXIT_FAILURE

// Vorwärtsdeklarationen
void zeichensatzInDateiSchreiben (const std::string& dateiname);
void dateiAusgeben (const std::string& dateiname);


int main ()
{
    try {
        zeichensatzInDateiSchreiben("charset.out");
        dateiAusgeben("charset.out");
    }
    catch (const std::string& msg) {
        std::cerr << "Exception: " << msg << std::endl;
        return EXIT_FAILURE;
    }
}


void zeichensatzInDateiSchreiben (const std::string& dateiname)
{
    // Datei zum Schreiben öffnen
    std::ofstream datei(dateiname.c_str());

    // wurde die Datei wirklich geöffnet?
    if (! datei) {
        // NEIN, Ausnahme auslösen
        throw "kann Datei \"" + dateiname
              + "\" nicht zum Schreiben oeffnen";
    }

    // Zeichensatz in Datei schreiben
    for (int i=32; i<127; ++i) {
        // Wert als Zahl und als Zeichen ausgeben:
        datei << "Wert: " << std::setw(3) << i << "   "
              << "Zeichen: " << static_cast<char>(i) << std::endl;
    }

}   // schließt die Datei automatisch

void dateiAusgeben (const std::string& dateiname)
{
    // Datei zum Lesen öffnen
    std::ifstream datei(dateiname.c_str());

    // wurde die Datei wirklich geöffnet?
    if (! datei) {
        // NEIN, Ausnahme auslösen
        throw "kann Datei \"" + dateiname
              + "\" nicht zum Lesen oeffnen";
    }

    // alle Zeichen der Datei nach std::cout kopieren
    char c;
    while (datei.get(c)) {
        std::cout.put(c);
    }

}   // schließt die Datei automatisch
