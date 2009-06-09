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
// beliebiges geometrisches Objekt zeichnen
void zeichne (const GeoObj& obj) {
    obj.draw();
}

// Abstand zwischen zwei geometrischen Objekten berechnen
Koord abstand (const GeoObj& x1, const GeoObj& x2) {
    Koord a = x1.position() - x2.position();
    return a.abs();
}

// inhomogene Menge von geometrischen Objekten ausgeben
void ausgeben (const std::vector<GeoObj*>& elems) {
    for (unsigned i=0; i<elems.size(); ++i) {
        elems[i]->draw();
    }
}

int main()
{
    Linie l;
    Kreis k, k1, k2;

    zeichne(l);            // zeichne(GeoObj&) => Linie::draw()
    zeichne(k);            // zeichne(GeoObj&) => Kreis::draw()

    abstand(k1,k2);        // abstand(GeoObj&,GeoObj&)
    abstand(l,k);          // abstand(GeoObj&,GeoObj&)

    std::vector<GeoObj*> menge;  // inhomogene Menge
    menge.push_back(&l);         // Linie einfügen
    menge.push_back(&k);         // Kreis einfügen
    ausgeben(menge);             // Menge ausgeben
}
