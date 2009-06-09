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

// exportiertes Objekt und exportierte Elementfunktion
void* objPtr;
void* objfpPtr;

void exportObjectAndFunction (void* op, void* fp)
{
    objPtr = op;
    objfpPtr = fp;
}

void callBspKlassenFunc (void* op, void* fp)
{
    // Typen zurückwandeln
    BspKlasse* bspObjPtr = static_cast<BspKlasse*>(op);
    BspKlassenFunktion* bspObjfpPtr
                         = static_cast<BspKlassenFunktion*>(fp);

    // übergebene Elementfunktion für das übergebene Objekt aufrufen
    (bspObjPtr->*(*bspObjfpPtr)) ();
}

int main ()
{
    // Objekt der Klasse BspKlasse
    BspKlasse x;

    // Funktionszeiger auf Elementfunktion der Klasse BspKlasse
    BspKlassenFunktion funcPtr;

    // Komponentenzeiger zeigt auf func1()
    funcPtr = & BspKlasse::func1;

    // Objekt und Elementfunktion exportieren
    exportObjectAndFunction (&x, &funcPtr);

    // exportierte Elementfunktion für exportiertes Objekt aufrufen
    callBspKlassenFunc (objPtr, objfpPtr);
}
