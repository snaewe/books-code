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
namespace Bsp {  // ******** Beginn Namensbereich Bsp::

template <typename T, int MAXSIZE>
class Stack {
  private:
    T elems[MAXSIZE];     // Elemente
    int numElems;         // aktuelle Anzahl eingetragener Elemente

  public:
    Stack();              // Konstruktor
    void push(const T&);  // Element einkellern
    T pop();              // Element auskellern
    T top() const;        // oberstes Element
};

// Konstruktor
template <typename T, int MAXSIZE>
Stack<T,MAXSIZE>::Stack ()
  : numElems(0)    // kein Elemente
{
    // nichts mehr zu tun
}

template <typename T, int MAXSIZE>
void Stack<T,MAXSIZE>::push (const T& elem)
{
    if (numElems == MAXSIZE) {
        throw "Stack<>::push(): der Stack ist voll";
    }
    elems[numElems] = elem;   // Element eintragen
    ++numElems;               // Anzahl der Elemente erhöhen
}

template<typename T, int MAXSIZE>
T Stack<T,MAXSIZE>::pop ()
{
    if (numElems <= 0) {
        throw "Stack<>::pop(): der Stack ist leer";
    }
    --numElems;               // Anzahl der Elemente herabsetzen
    return elems[numElems];   // bisheriges oberstes Element zurückliefern
}

template <typename T, int MAXSIZE>
T Stack<T,MAXSIZE>::top () const
{
    if (numElems <= 0) {
        throw "Stack<>::top(): der Stack ist leer";
    }
    return elems[numElems-1];  // oberstes Element zurückliefern
}

}  // ******** Ende Namensbereich Bsp::
