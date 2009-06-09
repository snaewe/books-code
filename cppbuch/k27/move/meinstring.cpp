/* cppbuch/k27/move/meinstring.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"meinstring.h"
#include<stdexcept>
#include<cstring>

namespace {
   void bereichPruefen(bool bedingung) {
      if(!bedingung) {
         throw std::out_of_range("MeinString: Bereichsüberschreitung");
      }
   }
}

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
    std::cout << "Kopierkonstruktor aufgerufen\n";
}

MeinString::MeinString(MeinString&& m)           // bewegender Konstruktor
   : len(m.len), cap(len), start(m.start) {
   m.start = 0;   // nicht vergessen
    std::cout << "Moving-Konstruktor aufgerufen\n";
}

MeinString::MeinString(const PlusVerknuepfung& pa)     // Konstruktor für PlusVerknuepfung
   : len(0), cap(0), start(0) { 
   reserve_only(pa.first.len + pa.second.len); //  Platz beschaffen
   strcpy(start, pa.first.start);               // Teil 1 kopieren
   strcpy(start + pa.first.len, pa.second.start);   // Teil 2 kopieren
   len   = pa.first.len + pa.second.len;   // Verwaltungsinformation aktualisieren
   std::cout << " MeinString(PlusVerknuepfung)-Konstruktor aufgerufen\n";
}

MeinString& MeinString::operator=(const PlusVerknuepfung& pa)  { // PlusVerknuepfung auswerten
   reserve_only(pa.first.len + pa.second.len); //  Platz beschaffen
   strcpy(start, pa.first.start);               // Teil 1 kopieren
   strcpy(start + pa.first.len, pa.second.start);   // Teil 2 kopieren
   len   = pa.first.len + pa.second.len;   // Verwaltungsinformation aktualisieren
   std::cout << "op=(PlusVerknuepfung) aufgerufen\n";
   return *this;
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

void MeinString::swap(MeinString& m)  {
   char *p = m.start;
   m.start = start;
   start = p;
   size_t tmp = m.len;
   m.len = len;
   len = tmp;
   tmp = m.cap;
   m.cap = cap;
   cap = tmp;
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

MeinString& MeinString::operator=(MeinString&& m)  {     // bewegende Zuweisung
    std::cout << "Moving-op= aufgerufen\n";
    swap(m);
    return *this;
}

MeinString& MeinString::operator=(const MeinString& m)  { // Zuweisung eines MeinString
    std::cout << "op(MeinString&)= aufgerufen\n";
   reserve_only(m.len);
   strcpy(start, m.start);
   len = m.len;
   return *this;
}

MeinString& MeinString::operator=(const char *s) {  // Zuweisung eines char*
   size_t temp = strlen(s);
   reserve_only(temp);
   strcpy(start, s);
   len = temp;
   return *this;
}

char& MeinString::at(size_t pos)  { // Zeichen per Referenz holen
    bereichPruefen(pos < len);  // Nullbyte lesen ist nicht erlaubt
    return start[pos];
}

const char& MeinString::at(size_t pos) const  { // Zeichen holen
    bereichPruefen(pos < len);  // Nullbyte lesen ist nicht erlaubt
    return start[pos];
}

char& MeinString::operator[](size_t pos) { // Zeichen per Referenz holen
    bereichPruefen(pos >= 0 && pos<= len); // Nullbyte lesen ist erlaubt
    return start[pos];
}

const char& MeinString::operator[](size_t pos) const  { // Zeichen holen
    bereichPruefen(pos >= 0 && pos<= len); // Nullbyte lesen ist erlaubt
    return start[pos];
}

MeinString& MeinString::operator+=(const MeinString& m)  { // Verketten
    char *p = new char[len + m.len + 1]; // neuen Platz beschaffen
    strcpy(p, start);          // Teil 1 kopieren
    strcpy(p + len, m.start);  // Teil 2 kopieren
    delete [] start;             // alten Platz freigeben
    len   += m.len;              // Verwaltungsinformation aktualisieren
    start = p;
    return *this;
}

void anzeigen(std::ostream& os, const MeinString& m)  {// Version 2
        os << m.c_str();
}

// Ausgabeoperator (keine Elementfunktion)
std::ostream& operator<<(std::ostream& os, const MeinString& m) {
     os << m.c_str();
     return os;
}

// Neu
PlusVerknuepfung operator+(const MeinString& a, const MeinString& b) {
   return PlusVerknuepfung(a, b);
}

// ersetzt durch vorstehenden op+
// MeinString operator+(const MeinString& a, const MeinString& b) {
//    return static_cast<MeinString&&>(MeinString(a) += b); // moving Kopierkonstruktor
//    // return MeinString(a) += b;  Kopierkonstruktor
//}

// dito, wenn temporäre Objekte beteiligt sind.
MeinString&& operator+(MeinString&& x, const MeinString& y) {
   return x += y;
}
MeinString&& operator+(const MeinString& x, MeinString&& y) {
   y.insert(0, x);
   return y; 
}
MeinString&& operator+(MeinString&& x, MeinString&& y) {
   return x += y;
}


void  MeinString::verketten(const MeinString& a, const MeinString& b) {
   reserve_only(a.len + b.len); // neuen Platz beschaffen
   strcpy(start, a.c_str());             // Teil 1 kopieren
   strcpy(start + a.len, b.start);  // Teil 2 kopieren
   len = a.len + b.len;
}

