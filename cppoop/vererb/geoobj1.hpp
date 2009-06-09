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
#ifndef GEOOBJ_HPP
#define GEOOBJ_HPP

// Headerdatei für Koord
#include "koord.hpp"

namespace Geo {

/* abstrakte Basisklasse GeoObj
 * - gemeinsame Basisklasse für geometrische Objekte
 * - zur Vererbung vorgesehen
 */
class GeoObj {
  protected:
    // Jedes GeoObj hat einen Referenzpunkt
    Koord refpunkt;

    /* Konstruktor für Startwert vom Referenzpunkt
     * - nichtöffentlich
     * - damit ist kein Default-Konstruktor vorhanden
     */
    GeoObj (const Koord& p) : refpunkt(p) {
    }

  public:
    // GeoObj um relativen Offset verschieben
    virtual void move (const Koord& offset) {
        refpunkt += offset;
    }

    /* GeoObj ausgeben
     * - rein virtuelle Funktion
     */
    virtual void draw () const = 0;

    // virtueller Destruktor
    virtual ~GeoObj () {
    }
};

}  // namespace Geo

#endif  // GEOOBJ_HPP
