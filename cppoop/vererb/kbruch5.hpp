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
#ifndef KBRUCH_HPP
#define KBRUCH_HPP

// Headerdatei der Basisklasse
#include "bruch.hpp"

// **** BEGINN Namespace Bsp ********************************
namespace Bsp {

/* Klasse KBruch
 * - abgeleitet von Bruch
 * - neu: der Zugriff auf geerbte Komponenten wird eingeschränkt
 *     (public wird protected)
 * - damit gilt die is-a-Beziehung nicht mehr
 */
class KBruch : protected Bruch {
  protected:
    bool kuerzbar;        // true: Bruch ist kürzbar

    // Hilfsfunktion: größter gemeinsamer Teiler von Zähler und Nenner
    unsigned ggt() const;

  public:
    /* Default-Konstruktor, Konstruktor aus Zähler
     * und Konstruktor aus Zähler und Nenner
     * - Parameter werden an Bruch-Konstruktor durchgereicht
     */
    KBruch (int z = 0, int n = 1) : Bruch(z,n) {
        kuerzbar = (ggt() > 1);
    }

    // neu: reine Zugriffsdeklaration für Operationen, die public bleiben
    Bruch::printOn;
    Bruch::toDouble;

    // multiplikative Zuweisung
    virtual const KBruch& operator*= (const Bruch&);

    // Eingabe mit Streams
    virtual void scanFrom (std::istream&);

    // Bruch kürzen
    virtual void kuerzen();

    // Kürzbarkeit testen
    virtual bool istKuerzbar() const {
        return kuerzbar;
    }
};

} // **** ENDE Namespace Bsp ********************************

#endif    // KBRUCH_HPP
