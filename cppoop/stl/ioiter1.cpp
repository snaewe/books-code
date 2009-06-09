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
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    using namespace std;    // Alle Symbole in std sind global

    vector<string> menge;    // Vektor-Container für Strings

    /* Strings von der Standard-Eingabe bis zum Ende der Daten einlesen
     * - von der ``Eingabe-Menge'' cin einfügend in menge kopieren
     */
    copy (istream_iterator<string>(cin),    // Beginn Quellbereich
          istream_iterator<string>(),       // Ende Quellbereich
          back_inserter(menge));            // Zielbereich

    // Elemente in menge sortieren
    sort (menge.begin(), menge.end());

    /* alle Elemente ausgeben
     * - von menge in die ``Ausgabe-Menge'' cout kopieren
     * - jeder String auf einer Zeile (durch "\n" getrennt)
     */
    copy (menge.begin(), menge.end(),             // Quellbereich
          ostream_iterator<string>(cout,"\n"));   // Zielbereich
}
