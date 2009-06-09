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
#ifndef PERSON_HPP
#define PERSON_HPP

// Headerdateien für Hilfsklassen
#include <string>

// **** BEGINN Namespace Bsp ********************************
namespace Bsp {

class Person {
  private:
    std::string       vname;      // Vorname der Person
    const std::string nname;      // Nachname der Person (neu: Konstante)

  public:
    // Konstruktor aus Nachname und optional Vorname
    Person (const std::string& nn, const std::string& vn = "")
      : nname(nn), vname(vn) {
    }

    // Abfragen von Eigenschaften
    const std::string& nachname () const {      // Nachname liefern
        return nname;
    }
    const std::string& vorname () const {       // Vorname liefern
        return vname;
    }
    //...
};

} // **** ENDE Namespace Bsp ********************************

#endif  // PERSON_HPP
