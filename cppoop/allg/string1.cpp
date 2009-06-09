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
    // zwei Strings anlegen
    std::string vorname = "bjarne";
    std::string nachname = "stroustrup";
    std::string name;

    // Strings manipulieren
    vorname[0] = 'B';
    nachname[0] = 'S';

    // Strings verketten
    name = vorname + " " + nachname;

    // Strings vergleichen
    if (name != "") {
        // Strings ausgeben
        std::cout << name
                  << " ist der Urvater von C++" << std::endl;
    }

    // Anzahl der Zeichen in einem String ermitteln
    int anz = name.length();
    std::cout << "\"" << name << "\" hat " << anz
              << " Zeichen" << std::endl;
}

