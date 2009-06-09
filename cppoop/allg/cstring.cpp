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
// C-Headerdatei für I/O
#include <stdio.h>

// C-Headerdatei für die String-Behandlung
#include <string.h>

void f()
{
    const char* k = "Eingabe: "; // String-Konstante
    char        text[81];        // String-Variable für 80 Zeichen
    char        s[81];           // String-Variable für die Eingabe (bis 80 Zeichen)

    /* String s einlesen
     * - aus Platzgründen nicht mehr als 80 Zeichen
     */
    if (scanf ("%80s", s) != 1) {
        // Einlesefehler
        //...
    }

    // String mit Leerstring vergleichen
    if (strcmp(s,"") == 0) {
        /* String-Literal an String text zuweisen
         * - VORSICHT: text muss ausreichend groß sein
         */
        strcpy (text, "keine Eingabe");
    }
    else {
        /* String-Konstante k, gefolgt von eingelesenem String,
         * an text zuweisen
         * - VORSICHT: text muss ausreichend groß sein
         */
        if (strlen(k)+strlen(s) <= 80) {
            strcpy (text, k);
            strcat (text, s);
        }
    }
    //...
}
