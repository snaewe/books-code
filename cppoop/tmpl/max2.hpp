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
#include <cstring>

template <typename T>
const T& max (const T& a, const T& b)
{
    std::cout << "max<>() fuer T" << std::endl;
    return (a > b ? a : b);
}

template <typename T>
T*const& max (T*const& a, T*const& b)
{
    std::cout << "max<>() fuer T*" << std::endl;
    return (*a > *b ? a : b);
}

inline const char* max (const char* a, const char* b)
{ 
    std::cout << "max<>() fuer char*" << std::endl;
    return (std::strcmp(a,b) > 0 ? a : b);
}
