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
// mögliche Implementierung von Operator new
void* operator new (std::size_t size)
{
    void* p;        // Zeiger für neuen Speicher

    // solange es nicht klappt, neuen Speicher zu bekommen,
    // New-Handler aufrufen oder Ausnahme auslösen
    while ((p = holSpeicher(size)) == 0) {
        // kein ausreichender Speicherplatz verfügbar
        if (MyNewHandler != 0) {
              // New-Handler aufrufen
              (*myNewHandler)();
        }
        else {
              // Ausnahme auslösen
              throw std::bad_alloc();
        }
    }

    // OK, neuen Speicherplatz zurückliefern
    return p;
}
