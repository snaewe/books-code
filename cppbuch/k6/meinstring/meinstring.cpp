/* cppbuch/k6/meinstring/meinstring.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"meinstring.h"
#include<cassert>
#include<cstring>

/* Der Default-Konstruktor erzeugt einen leeren String der Länge 0,
der nur aus dem Nullbyte besteht. */

MeinString::MeinString()                         // Default-Konstruktor
: len(0), start(new char[1]) {             // Platz für '\0'
    *start = '\0';                         // leerer String
}

/* Der allgemeine Konstruktor erzeugt aus einem klassischen C-String ein
{\tt MeinString}-Objekt. */

MeinString::MeinString(const char *s)              // allg. Konstruktor
: len(strlen(s)), start(new char[len+1]) {
    strcpy(start, s);
}

/* Der Kopierkonstruktor arbeitet ähnlich, nur dass er die Länge des
Objekts, mit dem initialisiert wird, direkt übernehmen kann:
*/
MeinString::MeinString(const MeinString& m)           // Kopierkonstruktor
: len(m.len), start(new char[len+1]) {
    strcpy(start, m.start);
}

MeinString::~MeinString() {                        // Destruktor
    delete [] start;
}

MeinString& MeinString::assign(const MeinString& m)  { // Zuweisung eines {\tt MeinString}
    char *p = new char[m.len+1]; // neuen Platz beschaffen
    strcpy(p, m.start);
    delete [] start;             // alten Platz freigeben
    len   = m.len;               // Verwaltungsinformation aktualisieren
    start = p;
    return *this;
}

MeinString& MeinString::assign(const char *s) {  // Zuweisung eines {\tt char*}
    size_t L = strlen(s);
    char *p = new char[L+1];
    strcpy(p, s);
    delete [] start;             // alten Platz freigeben
    len   = L;                   // Verwaltungsinformation aktualisieren
    start = p;
    return *this;
}

char& MeinString::at(size_t position)  {// Zeichen per Referenz holen
    assert(position < len);  // Nullbyte lesen ist nicht erlaubt
    return start[position];
}

const char& MeinString::at(size_t position) const   {// Zeichen holen
    assert(position < len);  // Nullbyte lesen ist nicht erlaubt
    return start[position];
}

void anzeigen(std::ostream& os, const MeinString& m)  {// Version 2
        os << m.c_str();
}
