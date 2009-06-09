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
#include "quer.hpp"

// Funktion, die die Quersumme aus einer ganzen Zahl berechnet
int quersumme (long zahl)
{
    int quer = 0;

    while (zahl > 0) {
        quer += zahl % 10;    // Einer auf Quersumme addieren
        zahl = zahl / 10;     // weiter mit restlichen Ziffern
    }

    return quer;
}
