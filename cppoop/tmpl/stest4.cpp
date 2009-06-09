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
#include <cstdlib>
#include "stack.hpp"

int main()
{
    try {
        Bsp::Stack<int,20>         int20Stack;     // Stack für 20 ints
        Bsp::Stack<int,40>         int40Stack;     // Stack für 40 ints
        Bsp::Stack<std::string,40> stringStack;    // Stack für 40 Strings

        // Integer-Stack manipulieren
        int20Stack.push(7);
        std::cout << int20Stack.pop() << std::endl;

        // String-Stack manipulieren
        std::string s = "hallo";
        stringStack.push(s);
        std::cout << stringStack.pop() << std::endl; 
        std::cout << stringStack.pop() << std::endl;
    }
    catch (const char* msg) {
        std::cerr << "Exception: " << msg << std::endl;
        return EXIT_FAILURE;
    }
}
