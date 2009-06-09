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
#include <strstream>

int main()
{
    // dynamischen char*-Stream zum Schreiben erzeugen
    std::ostrstream puffer;

    // formatiert beschreiben und mit Stringendekennzeichen abschließen
    puffer << "Pi: " << 3.1415 << std::ends;

    /* Zeichenfolge ausgeben
     * - str() friert char*-Stream ein
     */
    std::cout << puffer.str() << std::endl;

    // das Einfrieren aufheben
    puffer.freeze(false);

    // so positionieren, dass std::ends überschrieben wird
    puffer.seekp(-1,std::ios::end);

    // char* stream weiter beschreiben
    puffer << " oder auch: " << std::scientific << 3.1415
           << std::ends;

    /* Zeichenfolge ausgeben
     * - str() friert char*-Stream ein
     */
    std::cout << puffer.str() << std::endl;

    // das Einfrieren aufheben, damit Speicherplatz freigegeben wird
    puffer.freeze(false);
}
