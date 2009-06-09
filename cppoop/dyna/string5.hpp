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
#ifndef STRING_HPP
#define STRING_HPP

// Headerdatei für I/O
#include <iostream>

// **** BEGINN Namespace Bsp ********************************
namespace Bsp {

class String {

  protected:
    char*    buffer;    // Zeichenfolge als dynamisches Feld (Array)
    unsigned len;       // aktuelle Anzahl an Zeichen
    unsigned size;      // Speicherplatzgröße von buffer

  public:
    // Default- und char*-Konstruktor
    String (const char* = "");

    // Aufgrund dynamischer Komponenten:
    String (const String&);             // Copy-Konstruktor
    String& operator= (const String&);  // Zuweisung
    virtual ~String();                  // Destruktor (neu: virtuell)

    // Vergleichen von Strings
    friend bool operator== (const String&, const String&);
    friend bool operator!= (const String&, const String&);

    // Hintereinanderhängen von Strings
    friend String operator+ (const String&, const String&);

    // Ausgabe mit Streams
    virtual void printOn (std::ostream&) const;

    // Eingabe mit Streams
    virtual void scanFrom (std::istream&);

    // Anzahl der Zeichen
    // Beachte: darf beim Ableiten nicht überschrieben werden
    unsigned length () const {
        return len;
    }

  private:
    /* Konstruktor aus Länge und Puffer
     * - intern für Operator +
     */
    String (unsigned, char*);
};

// Standard-Ausgabeoperator
inline std::ostream& operator << (std::ostream& strm, const String& s)
{
    s.printOn(strm);    // String auf Stream ausgeben
    return strm;        // Stream zurückliefern
}

// Standard-Eingabeoperator
inline std::istream& operator >> (std::istream& strm, String& s)
{
    s.scanFrom(strm);   // String von Stream einlesen
    return strm;        // Stream zurückliefern
}

/* Operator !=
 * - als Umsetzung auf Operator == inline implementiert
 */
inline bool operator!= (const String& s1, const String& s2) {
    return !(s1==s2);
}

} // **** ENDE Namespace Bsp ********************************

#endif  // STRING_HPP
