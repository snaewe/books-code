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
#include <iostream>    // C++-Headerdatei für I/O
#include <string>      // C++-Headerdatei für Strings

int main ()
{
    const std::string k = "Eingabe: ";  // String-Konstante
    std::string text;                   // String-Variable
    std::string s;                      // String-Variable für Eingabe

    // String s einlesen
    if (! (std::cin >> s)) {
        // Einlesefehler
        //...
    }

    // String mit Leerstring vergleichen
    if (s == "") {
        // String-Literal an String text zuweisen
        text = "keine Eingabe";
    }
    else {
        /* String-Konstante k, gefolgt von eingelesenem String,
         * an text zuweisen
         */
        text = k + s;
    }
    //...
}
