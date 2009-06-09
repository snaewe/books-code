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
#ifndef FARBSTRING_HPP
#define FARBSTRING_HPP

// Headerdatei der Basisklasse
#include "string.hpp"

// **** BEGINN Namespace Bsp ********************************
namespace Bsp {

/* Klasse FarbString
 * - abgeleitet von String
 */
class FarbString : public String {
  protected:
    String farb;    // Farbe, die der String besitzt

  public:
    // Default-, String- und String/String-Konstruktor
    FarbString (const String& s = "", const String& f = "black")
        : String(s), farb(f) {
    }

    // Farbe abfragen und setzen
    const String& farbe () {
        return farb;
    }
    void farbe (const String& neueFarbe) {
        farb = neueFarbe;
    }

    // Ein- und Ausgabe mit Streams
    virtual void printOn (std::ostream&) const;
    virtual void scanFrom (std::istream&);

    // Vergleichen von FarbStrings
    friend bool operator== (const FarbString& s1,
                            const FarbString& s2) {
        return static_cast<const String&>(s1)
                 == static_cast<const String&>(s2)
               && s1.farb == s2.farb;
    }
    friend bool operator!= (const FarbString& s1,
                            const FarbString& s2) {
        return !(s1==s2);
    }
};

} // **** ENDE Namespace Bsp ********************************

#endif // FARBSTRING_HPP
