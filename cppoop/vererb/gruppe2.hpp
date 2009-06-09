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
#ifndef GEOGRUPPE_HPP
#define GEOGRUPPE_HPP

// Headerdatei der Basisklasse einbinden
#include "geoobj.hpp"

// Headerdatei für die interne Verwaltung der Elemente
#include <vector>

namespace Geo {

/* Klasse GeoGruppe
 * - abgeleitet von GeoObj
 * - eine GeoGruppe besteht aus:
 *     - einem Referenzpunkt (geerbt)
 *     - einer Menge von geometrischen Elementen (neu)
 */
class GeoGruppe : public GeoObj {
  protected:
    std::vector<GeoObj*> elems;    // Menge von Zeigern auf GeoObjs

  public:
    // Konstruktor mit optionalem Referenzpunkt
    GeoGruppe (const Koord& p = Koord(0,0)) : GeoObj(p) {
    }

    // Ausgabe (jetzt auch implementiert)
    virtual void draw () const;

    // Element einfügen
    virtual void add (GeoObj&);

    // Element entfernen
    virtual bool remove (GeoObj&);

    // virtueller Destruktor
    virtual ~GeoGruppe () {
    }
};

}  // namespace Geo

#endif  // GEOGRUPPE_HPP
