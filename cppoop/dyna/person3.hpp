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

// Headerdateien einbinden
#include <string>

// **** BEGINN Namespace Bsp ********************************
namespace Bsp {

class Person {
  /* neu: statische Klassenkomponenten
   */
  private:
    static long personenMaxID;   // höchste ID aller Personen
    static long personenAnzahl;  // aktuelle Anzahl aller Personen
  public:
    // aktuelle Anzahl aller Personen liefern
    static long anzahl () {
        return personenAnzahl;
    }

  // nicht-statische Klassenkomponenten
  private:
    std::string vname;        // Vorname der Person
    std::string nname;        // Nachname der Person
    const long  pid;          // neu: eindeutige ID der Person

  public:
    // Konstruktor aus Nachname und optional Vorname
    Person (const std::string&, const std::string& = "");

    // neu: Copy-Konstruktor
    Person (const Person&);

    // neu: Destruktor
    ~Person ();

    // neu: Zuweisung
    Person& operator = (const Person&);

    // Abfragen von Eigenschaften
    const std::string& nachname () const {  // Nachname liefern
        return nname;
    }
    const std::string& vorname () const {   // Vorname liefern
        return vname;
    }
    long id () const {                      // neu: ID liefern
        return pid;
    }

    friend bool operator == (const Person& p1, const Person& p2) {
        return p1.vname == p1.vname && p2.nname == p2.nname;
    }
    friend bool operator != (const Person& p1, const Person& p2) {
        return !(p1==p2);
    }
    //...
};

} // **** ENDE Namespace Bsp ********************************

#endif  // PERSON_HPP
