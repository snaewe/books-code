/* cppbuch/loesungen/k6/1/meinstring.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"meinstring.h"
#include<cassert>
#include<cstring>

// Der Default-Konstruktor erzeugt einen leeren String der Länge 0,
//der nur aus dem Nullbyte besteht
MeinString::MeinString()
   : len(0), cap(0), start(new char[1]) {  // Platz für '\0'
    *start = '\0';                         // leerer String
}

// Der allgemeine Konstruktor erzeugt aus einem klassischen C-String ein
// {\tt MeinString}-Objekt.

MeinString::MeinString(const char *s)              // allg. Konstruktor
   : len(strlen(s)), cap(len), start(new char[cap+1]) {
   strcpy(start, s);
}

// Der Kopierkonstruktor arbeitet ähnlich, nur dass er die Länge des
// Objekts, mit dem initialisiert wird, direkt übernehmen kann:
MeinString::MeinString(const MeinString& m)           // Kopierkonstruktor
   : len(m.len), cap(len), start(new char[cap+1]) {
   strcpy(start, m.start);
}

MeinString::~MeinString() {                        // Destruktor
    delete [] start;
}

void MeinString::reserve(size_t groesse) {
   if(groesse > cap) {
      char *temp = new char[groesse+1]; // neuen Platz beschaffen
      strcpy(temp, start);            // umkopieren
      delete [] start;                // alten Platz freigeben
      start = temp;                   // Verwaltungsinformation aktualisieren
      cap = groesse;                  // Verwaltungsinformation aktualisieren
   }
}

void MeinString::reserve_only(size_t groesse) {
   if(groesse > cap) {
      char *temp = new char[groesse+1]; // neuen Platz beschaffen
      delete [] start;                // alten Platz freigeben
      start = temp;                   // Verwaltungsinformation aktualisieren
      cap = groesse;                  // Verwaltungsinformation aktualisieren
   }
}

void MeinString::shrink_to_fit() {
   if(cap > len) {
      char *temp = new char[len+1];   // neuen Platz beschaffen
      strcpy(temp, start);            // umkopieren
      delete [] start;                // alten Platz freigeben
      start = temp;                   // Verwaltungsinformation aktualisieren
      cap = len;                      // Verwaltungsinformation aktualisieren
   }
}

void MeinString::insert(size_t pos, const MeinString& m) { // m vor pos einfügen 
   if(pos > len) {
      pos = len;
   }
   reserve(len + m.len);
   // Teil hinter pos verschieben
   size_t neuesende = len + m.len;
   for(size_t anz = 0; anz <= len-pos; ++anz) {
      start[neuesende] = start[neuesende-m.len];
      --neuesende;
   }
   // m einfügen
   const char* temp = m.start;
   while(*temp) {
      start[pos++] = *temp++;
   }
   len = len + m.len;                 // Verwaltungsinformation aktualisieren
}

MeinString& MeinString::assign(const MeinString& m)  { // Zuweisung eines {\tt MeinString}
   reserve_only(m.len);
   strcpy(start, m.start);
   len = m.len;
   return *this;
}

MeinString& MeinString::assign(const char *s) {  // Zuweisung eines {\tt char*}
   size_t temp = strlen(s);
   reserve_only(temp);
   strcpy(start, s);
   len = temp;
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
