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
// Headerdatei der eigenen Klasse
#include "string.hpp"

// C-Headerdateien für String-Funktionen
#include <cstring>
#include <cctype>

// **** BEGINN Namespace Bsp ********************************
namespace Bsp {

/* Konstruktor aus C-String (const char*)
 * - Default für s: ""
 */
String::String (const char* s)
{
    len = std::strlen(s);       // Anzahl an Zeichen
    size = len;                 // Zeichenanzahl bestimmt Speicherplatzgröße
    buffer = new char[size];    // Speicherplatz anlegen
    std::memcpy(buffer,s,len);  // Zeichen in Speicherplatz kopieren
}

/* Copy-Konstruktor
 */
String::String (const String& s)
{
    len = s.len;                // Anzahl an Zeichen übernehmen
    size = len;                 // Zeichenanzahl bestimmt Speicherplatzgröße
    buffer = new char[size];           // Speicherplatz anlegen
    std::memcpy(buffer,s.buffer,len);  // Zeichen kopieren
}

/* Destruktor
 */
String::~String ()
{
    // mit new[] angelegten Speicherplatz wieder freigeben
    delete [] buffer;
}

/* Operator =
 * - Zuweisung
 */
String& String::operator= (const String& s)
{
    // Zuweisung eines Strings an sich selbst hat keinen Effekt
    if (this == &s) {
        return *this;        // String zurückliefern
    }

    len = s.len;             // Anzahl an Zeichen übernehmen

    // falls Platz nicht reicht, vergrößern
    if (size < len) {
        delete [] buffer;         // alten Speicherplatz freigeben
        size = len;               // Zeichenanzahl bestimmt neue Größe
        buffer = new char[size];  // Speicherplatz anlegen
    }

    std::memcpy(buffer,s.buffer,len);  // Zeichen kopieren

    return *this;            // geänderten String zurückliefern
}

/* Operator ==
 * - vergleicht zwei Strings
 * - globale Friend-Funktion, damit eine automatische
 *     Typumwandlung des ersten Operanden möglich ist
 */
bool operator== (const String& s1, const String& s2)
{
    return s1.len == s2.len &&
           std::memcmp(s1.buffer,s2.buffer,s1.len) == 0;
}

/* Operator +
 * - hängt zwei Strings hintereinander
 * - globale Friend-Funktion, damit eine automatische
 *     Typumwandlung des ersten Operanden möglich ist
 */
String operator+ (const String& s1, const String& s2)
{
    // Puffer für den Summenstring erzeugen
    char* buffer = new char[s1.len+s2.len];

    // Summenzeichenfolge darin initialisieren
    std::memcpy (buffer,        s1.buffer, s1.len);
    std::memcpy (buffer+s1.len, s2.buffer, s2.len);

    // daraus Summenstring erzeugen und zurückliefern
    return String (s1.len+s2.len, buffer);
}

/* Konstruktor für uninitialisierten String bestimmter Länge
 * - intern für Operator +
 */
String::String (unsigned l, char* buf)
{
    len = l;       // Anzahl an Zeichen übernehmen
    size = len;    // ist gleichzeitig auch Speicherplatzgröße
    buffer = buf;  // Speicherplatz übernehmen
}

/* Ausgabe auf Stream
 */
void String::printOn (std::ostream& strm) const
{
    // Zeichenfolge einfach ausgeben
    strm.write(buffer,len);
}

} // **** ENDE Namespace Bsp ********************************
