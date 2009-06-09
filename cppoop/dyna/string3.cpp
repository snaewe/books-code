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
/* Operator [] für Variablen
 */
char& String::operator [] (unsigned i)
{
    // Index nicht im erlaubten Bereich?
    if (i >= len) {
        // Ausnahme mit fehlerhaftem Index auslösen
        throw RangeError(i);
    }

    return cstring[i];
}

/* Operator [] für Konstanten
 */
const char String::operator [] (unsigned i) const
{
    // Index nicht im erlaubten Bereich?
    if (i >= len) {
        // Ausnahme mit fehlerhaftem Index auslösen
        throw RangeError(i);
    }

    return cstring[i];
}
