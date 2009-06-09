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
// Headerdatei für den New-Handler
#include <new>

// Standard-Headerdateien
#include <iostream>

// Vorwärtsdeklaration
static void eigenerNewHandler();

// Reserve-Speicherplatz
static char* reserveSpeicherplatz1;
static char* reserveSpeicherplatz2;

void initNewHandler ()
{
    // je nach Bedarf Reserve-Speicherplatz anfordern
    reserveSpeicherplatz1 = new char[1000000];
    reserveSpeicherplatz2 = new char[100000];

    // New-Handler installieren
    std::set_new_handler(&eigenerNewHandler);
}

static void eigenerNewHandler ()
{
    static bool firstKiss = true;

    // - beim ersten Mal:  Reserve-Speicherplatz bereitstellen
    // - beim zweiten Mal: Ausnahme auslösen
    if (firstKiss) {
        // Programm läuft weiter bis zum zweiten Aufruf
        firstKiss = false;

        // ersten Speicherplatz für New-Handler freigeben
        delete [] reserveSpeicherplatz1;

        // Warnung auf Standard-Fehlerkanal ausgeben
        std::cerr << "Warnung: Speicherplatz bald alle" << std::endl;
    }
    else {
        // zweiten Reserve-Speicherplatz für New-Handler freigeben
        delete [] reserveSpeicherplatz2;

        // Fehlermeldung auf Standard-Fehlerkanal ausgeben
        std::cerr << "Speicherplatz endgueltig alle" << std::endl;

        // entsprechende Exception auslösen
        throw std::bad_alloc();
    }
}
