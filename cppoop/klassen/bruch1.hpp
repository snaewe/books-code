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
#ifndef BRUCH_HPP
#define BRUCH_HPP

// **** BEGINN Namespace Bsp ********************************
namespace Bsp {

/* Klasse Bruch
 */
class Bruch {

  /* privat: kein Zugriff von außen
   */
  private:       
    int zaehler;
    int nenner;

  /* öffentliche Schnittstelle
   */
  public:
    // Default-Konstruktor
    Bruch();

    // Konstruktor aus int (Zähler)
    Bruch(int);

    // Konstruktor aus zwei ints (Zähler und Nenner)
    Bruch(int, int);

    // Ausgabe
    void print();
};

} // **** ENDE Namespace Bsp ********************************

#endif    /* BRUCH_HPP */
