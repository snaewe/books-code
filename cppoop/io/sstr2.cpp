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
#include <sstream>

int main()
{
    // String anlegen, aus dem formatiert gelesen werden soll
    std::string s = "Pi: 3.1415";

    // String-Stream zum formatierten Lesen anlegen
    // und mit dem String initialisieren
    std::istringstream is(s);

    // ersten String und Wert dazu formatiert auslesen
    std::string name;
    double wert;
    is >> name >> wert;

    // eingelesene Daten ausgeben
    std::cout << "Name: " << name << std::endl;
    std::cout << "Wert: " << wert << std::endl;
}
