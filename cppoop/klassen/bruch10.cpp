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
/* Default-Konstruktor, Konstruktor aus ganzer Zahl,
 * Konstruktor aus Zähler und Nenner
 * - Default für z: 0
 * - Default für n: 1
 */
Bruch::Bruch (int z, int n)
{
    /* Zähler und Nenner wie übergeben initialisieren
     * - 0 als Nenner ist allerdings nicht erlaubt
     * - ein negatives Vorzeichen des Nenners kommt in den Zähler
     */
    if (n == 0) {
        // Ausnahme: Fehlerobjekt für 0 als Nenner auslösen
        throw NennerIstNull();
    }
    if (n < 0) {
        zaehler = -z;
        nenner  = -n;
    }
    else {
        zaehler = z;
        nenner  = n;
    }
}

/* scanFrom
 * - Bruch von Stream strm einlesen
 */
void Bruch::scanFrom (istream& strm)
{
    int z, n;

    // Zähler einlesen
    strm >> z;

    // optionales Trennzeichen und Nenner '/' einlesen
    if (strm.peek() == '/') {
        strm.get();
        strm >> n;
    }
    else {
        n = 1;
    }

    // Lesefehler?
    if (! strm) {
        // Ausnahme mit Fehlerobjekt für Lesefehler auslösen
        throw Lesefehler();
    }

    // Nenner == 0?
    if (n == 0) {
        // Ausnahme mit Fehlerobjekt für 0 als Nenner auslösen
        throw NennerIstNull();
    }

    // OK, eingelesene Zahlen zuweisen
    if (n < 0) {
        zaehler = -z;
        nenner  = -n;
    }
    else {
        zaehler = z;
        nenner  = n;
    }
}
