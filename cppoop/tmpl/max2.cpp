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
#include <string>
#include "max.hpp"

int main ()
{
    int a=7;                               // zwei Variablen vom Datentyp int
    int b=11;
    std::cout << max(a,b) << std::endl;    // max() für zwei ints

    std::string s="hallo";                 // zwei Strings
    std::string t="holla";
    std::cout << ::max(s,t) << std::endl;  // max() für zwei Strings

    int* p1 = &b;                          // zwei Zeiger
    int* p2 = &a;
    std::cout << *max(p1,p2) << std::endl; // max() für zwei Zeiger

    const char* s1 = "hallo";              // zwei C-Strings
    const char* s2 = "otto";
    std::cout << max(s1,s2) << std::endl;  // max() für zwei C-Strings
}
