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
#include <iostream>    // C++-Headerdatei für Ein-/Ausgaben

int main ()
{
    int zaehler = 0;    // aktuelle Anzahl der gefundenen Zahlen

    // für jede Zahl zahl von 1000 bis 9999
    for (int zahl=1000; zahl<10000; ++zahl) {

        // die vorderen und hinteren beiden Ziffern abspalten
        int vorn = zahl/100;      // die ersten beiden Ziffern
        int hinten = zahl%100;    // die letzten beiden Ziffern

        // Falls die Summe der Quadrate die ursprüngliche Zahl ergibt,
        // Zahl ausgeben und Zähler inkrementieren
        if (vorn*vorn + hinten*hinten == zahl) {
            std::cout << zahl << " == "
                      << vorn << "*" << vorn << " + "
                      << hinten << "*" << hinten << std::endl;
            ++zaehler;
        }
    }

    // Anzahl der gefundenen Zahlen ausgeben
    std::cout << zaehler << " Zahlen gefunden" << std::endl;
}
