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
// Deklaration des Funktions-Templates max()
template <typename T>
const T& max (const T& a, const T& b);

// Deklaration des Klassen-Templates Stack<>
#include <vector>

namespace Bsp {  // ******** Beginn Namensbereich Bsp::

template <typename T>
class Stack {
  private:
    std::vector<T> elems;  // Elemente
  public:
    Stack();               // Konstruktor
    void push(const T&);   // Element einkellern
    T pop();               // Element auskellern
    T top() const;         // oberstes Element
};

}  // ******** Ende Namensbereich Bsp::
