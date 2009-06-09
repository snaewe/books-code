/* cppbuch/loesungen/k9/6_7/meinstring.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef MEINSTRING_H
#define MEINSTRING_H
#include<cstddef>                    // {\tt size\_t}
#include<iostream>                   // {\tt ostream}

class MeinString {
  public:
   MeinString();                     // Default-Konstruktor
   MeinString(const char *);         // allg. Konstruktor
   MeinString(const MeinString&);    // Kopierkonstruktor
   ~MeinString();                    // Destruktor
   MeinString& operator=(const MeinString&);  // Zuweisung eines MeinString
   MeinString& operator=(const char *);    // Zuweisung eines char*
   const char& at(size_t position) const; // Zeichen holen
   char& at(size_t position);          // Zeichen holen,
                     //  die Referenz erlaubt Ändern des Zeichens
   const char& operator[](size_t position) const; // Zeichen holen
   char& operator[](size_t position);          // Zeichen holen,
                     //  die Referenz erlaubt Ändern des Zeichens
   MeinString& operator+=(const MeinString&);  // Verketten
   size_t length() const { return len;}  // Stringlänge zurückgeben
   size_t capacity() const { return cap;}  // Kapazität zurückgeben
   void reserve(size_t bytes);           // Platz reservieren mit Erhalt des Inhalts
   void shrink_to_fit();               // Platz minimieren
   const char* c_str() const { return start;} // C-String zurückgeben
   void insert(size_t pos, const MeinString& m); // m vor pos einfügen 
  private:
   size_t len;                         // Länge
   size_t cap;                         // Kapazität
   char *start;                        // Zeiger auf den Anfang
   void reserve_only(size_t bytes);    // nur Platz reservieren
};

void anzeigen(std::ostream& os, const MeinString& m); // Version 2

MeinString operator+(const MeinString&, const MeinString&);  // Verketten

std::ostream& operator<<(std::ostream &os, const MeinString &m);
#endif
