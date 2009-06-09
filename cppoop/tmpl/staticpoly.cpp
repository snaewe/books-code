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
template <typename GeoObj>
void zeichne (const GeoObj& obj) {
    obj.draw();
}

// Abstand zwischen zwei geometrischen Objekten berechnen
template <typename GeoObj1, typename GeoObj2>
Koord abstand (const GeoObj1& x1, const GeoObj2& x2) {
    Koord a = x1.position() - x2.position();
    return a.abs();
}

// inhomogene Menge von geometrischen Objekten ausgeben
template <typename GeoObj>
void ausgeben (const std::vector<GeoObj>& elems) {
    for (unsigned i=0; i<elems.size(); ++i) {
        elems[i].draw();
    }
}

int main()
{
    Linie l;
    Kreis k;
    Kreis k1, k2;

    zeichne(l);            // zeichne<Linie>(GeoObj&) => Linie::draw()
    zeichne(k);            // zeichne<Kreis>(GeoObj&) => Kreis::draw()

    abstand(k1,k2);        // abstand<Kreis,Kreis>(GeoObj&,GeoObj&)
    abstand(l,k);          // abstand<Linie,Kreis>(GeoObj&,GeoObj&)

    \ccstd::vector<GeoObj*> menge;   // FEHLER: keine inhomogene Menge möglich
    std::vector<Linie> menge;        // OK: homogene Menge
    menge.push_back(l);              // Linie einfügen
    ausgeben(menge);                 // Menge ausgeben
}
