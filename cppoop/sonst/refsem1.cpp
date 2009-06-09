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
#include <list>
#include <deque>
#include <algorithm>
#include "countptr.hpp"
using namespace std;

void printCountedPtr (CountedPtr<int> elem)
{
    cout << *elem << ' ';
}

int main()
{
    // Datentyp für Smart-Pointer dazu
    typedef CountedPtr<int> IntPtr;

    // zwei verschiedene Mengen
    deque<IntPtr> coll1;
    list<IntPtr> coll2;

    // Array von initialen ints
    static int values[] = { 3, 5, 9, 1, 6, 4 };

    /* neu erzeugte ints in die Mengen mit Referenz-Semantik einfügen
     * - gleiche Reihenfolge in coll1
     * - umgekehrte Reihenfolge in coll2
     */
    for (unsigned i=0; i<sizeof(values)/sizeof(values[0]); ++i) {
        IntPtr ptr(new int(values[i]));
        coll1.push_back(ptr);
        coll2.push_front(ptr);
    }

    // Inhalt beider Mengen ausgeben
    for_each (coll1.begin(), coll1.end(),
              printCountedPtr);
    cout << endl;
    for_each (coll2.begin(), coll2.end(),
              printCountedPtr);
    cout << endl << endl;

    /* Elemente der Mengen an verschiedenen Stellen modifizieren
     * - dritten Wert in coll1 quadrieren
     * - ersten Wert in coll1 negieren
     * - ersten Wert in coll2 auf 0 setzen
     */
    *coll1[2] *= *coll1[2];
    (**coll1.begin()) *= -1;
    (**coll2.begin()) = 0;

    // Inhalt beider Mengen erneut ausgeben
    for_each (coll1.begin(), coll1.end(),
              printCountedPtr);
    cout << endl;
    for_each (coll2.begin(), coll2.end(),
              printCountedPtr);
    cout << endl;
}
