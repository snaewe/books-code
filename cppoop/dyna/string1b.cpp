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
// **** BEGINN Namespace Bsp ********************************
namespace Bsp {

void String::scanFrom (std::istream& strm)
{
    char c;

    len = 0;            // zunächst ist der gelesene String leer

    strm >> std::ws;    // führende Trennzeichen überlesen

    /* solange der Input-Stream strm nach dem Einlesen
     * eines Zeichens in c in Ordnung ist
     */
    while (strm.get(c)) {       // >> würde Trennzeichen überlesen

        /* ein Trennzeichen schließt die Stringeingabe ab
         * => RETURN
         */
        if (std::isspace(c)) {
            return;
        }

        /* falls der Platz nicht mehr ausreicht,
         * muss mehr geschaffen werden
         */
        if (len >= size) {
            char* tmp = buffer;           // Zeiger auf alten Speicherplatz
            size = size*2 + 32;           // Speicherplatz mehr als verdoppeln
            buffer = new char[size];      // neuen Speicherplatz anlegen
            std::memcpy(buffer,tmp,len);  // Zeichen kopieren
            delete [] tmp;                // alten Speicherplatz freigeben
        }

        // neues Zeichen eintragen
        buffer[len] = c;
        ++len;
    }

    // Einlese-Ende durch Fehler oder EOF
}

} // **** ENDE Namespace Bsp ********************************

