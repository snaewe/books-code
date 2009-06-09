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
    // String-Stream zum formatierten Schreiben anlegen
    std::ostringstream os;

    // ganzzahlige Werte dezimal und hexadezimal schreiben
    os << "dec: " << 15 << std::hex << " hex: " << 15 << std::endl;

    // String-Stream als String ausgeben
    std::cout << os.str() << std::endl;

    // Gleitkommawerte anhängen
    os << "float: " << 4.67 << std::endl;

    // String-Stream als String ausgeben
    std::cout << os.str() << std::endl;

    // String-Stream vorn mit oktalem Wert überschreiben
    os.seekp(0);
    os << "oct: " << std::oct << 15;

    // String-Stream als String ausgeben
    std::cout << os.str() << std::endl;
}
