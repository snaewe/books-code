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

class BspKlasse {
  public:
    void func1() {
        std::cout << "Aufruf von func1()" << std::endl;
    }
    void func2() {
        std::cout << "Aufruf von func2()" << std::endl;
    }
};

// Datentyp: Zeiger auf Elementfunktion der Klasse BspKlasse
//     ohne Parameter und Rückgabewert
typedef void (BspKlasse::*BspKlassenFunktion) ();

int main ()
{
    // Funktionszeiger auf Elementfunktion der Klasse BspKlasse
    BspKlassenFunktion funcPtr;

    // Objekt der Klasse BspKlasse
    BspKlasse x;

    // Komponentenzeiger zeigt auf func1()
    funcPtr = & BspKlasse::func1;

    // Elementfunktion, auf die der Zeiger zeigt, für Objekt x aufrufen
    (x.*funcPtr) ();
    
    // Komponentenzeiger zeigt auf func2()
    funcPtr = & BspKlasse::func2;

    // Elementfunktion, auf die der Zeiger zeigt, für Objekt x aufrufen
    (x.*funcPtr) ();
}
