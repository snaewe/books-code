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
class Bruch {
  private:
    int zaehler;
    int nenner;

  public:
    /* Fehlerklassen:
     * - neu: allgemeine Basisklasse mit zwei abgeleiteten Klassen
     */
    class Bruchfehler {
    };
    class NennerIstNull: public Bruchfehler {
    };
    class Lesefehler : public Bruchfehler {
    };

    /* Default-Konstruktor, Konstruktor aus Zähler und
     * Konstruktor aus Zähler und Nenner
     */
    Bruch (int = 0, int = 1);

    /* Ein- und Ausgabe mit Streams
     */
    void printOn (std::ostream&) const;
    void scanFrom (std::istream&);
    //...
};
