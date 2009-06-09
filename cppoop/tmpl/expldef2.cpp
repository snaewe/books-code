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
#include <string>
#include "expldef.hpp"

// benötigte Funktions-Templates explizit instanziieren
template const int& max (const int&, const int&);

// benötigte Funktionen von Stack<> für int explizit instanziieren
template Bsp::Stack<int>::Stack();
template void Bsp::Stack<int>::push (const int&);
template int Bsp::Stack<int>::top () const;
template int Bsp::Stack<int>::pop ();

// benötigte Funktionen von Stack<> für std::string explizit instanziieren
// - top() wird nicht benötigt
template Bsp::Stack<std::string>::Stack();
template void Bsp::Stack<std::string>::push (const std::string&);
template std::string Bsp::Stack<std::string>::pop ();
