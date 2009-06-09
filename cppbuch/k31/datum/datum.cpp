/* cppbuch/k31/datum/datum.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"datum.h"
#include<ctime>
#include<cassert>
#include<sstream>
#include<limits>   // für maxDatum()

Datum::Datum()  { aktuell();}

void Datum::set(int t, int m, int j) 
          throw(UngueltigesDatumException) {
    if(!istGueltigesDatum(t, m, j)) {
       throw UngueltigesDatumException(t, m, j);
    }
    tag_ = t;
    monat_ = m;
    jahr_ = j;
}

void Datum::aktuell() {   // Systemdatum eintragen
    // {\tt time\_t, time(), tm, localtime()} sind in <ctime> deklariert
    time_t now = time(NULL);
    tm *z = localtime(&now);           // Zeiger auf struct tm
    jahr_  = z->tm_year + 1900;
    monat_ = z->tm_mon+1;               // localtime liefert 0..11
    tag_   = z->tm_mday;
}

void Datum::maxDatum() {   // maximales Systemdatum ermitteln
    time_t maxSekunden =  std::numeric_limits<time_t>::max();
    tm *z = localtime(&maxSekunden);
    jahr_  = z->tm_year + 1900;
    monat_ = z->tm_mon+1;               // localtime liefert 0..11
    tag_   = z->tm_mday;
}


Datum& Datum::operator++() {     // Datum um 1 Tag erhöhen
   ++tag_;
   // Monatsende erreicht?
   if(!istGueltigesDatum(tag_, monat_, jahr_)) {
     tag_ = 1;
     if (++monat_ > 12) {
        monat_ = 1;
        ++jahr_;
     }
   }
   return *this;
}

Datum Datum::operator++(int) {        // Datum um 1 Tag erhöhen
   Datum temp = *this;
   ++*this;                           // Präfix ++ aufrufen
   return temp;
}

// neu, siehe unten
// std::string Datum::toString() const {
//     std::string temp("tt.mm.jjjj");
//               // implizite Umwandlung in char
//     temp[0] = tag_/10 +'0';
//     temp[1] = tag_%10 +'0';
//     temp[3] = monat_/10 +'0';
//     temp[4] = monat_%10 +'0';
//     int pos = 9;                 // letzte Jahresziffer
//     int j = jahr_;
//     while(j > 0) {
//        temp[pos] = j % 10 + '0';  // letzte Ziffer
//        j = j/10;                  // letzte Ziffer abtrennen
//        --pos;
//     }
//     return temp;
// }

// neu
std::string Datum::toString(const std::locale& loc) const {
   std::ostringstream oss;
   oss.imbue(loc);
   oss << *this;      // Benutzung des obigen operator<<()
   return oss.str();
}

// globale Funktionen + Operatoren
bool istGueltigesDatum(int t, int m, int j) {
   // Tage pro Monat(static vermeidet Neuinitialisierung):
   static int tmp[]={31,28,31,30,31,30,31,31,30,31,30,31};
   int letzterTagImMonat = tmp[m-1];
   if(m == 2 && istSchaltjahr(j)) {
      letzterTagImMonat = 29;
   }
   return (   m >= 1    && m <= 12
              && j  >= 1583 && j  <= 2399  // oder mehr
              && t  >= 1    && t   <= letzterTagImMonat);
}


bool operator==(const Datum& a, const Datum& b) {
   return    a.tag()   == b.tag()
          && a.monat() == b.monat()
          && a.jahr()  == b.jahr();
}

bool operator!=(const Datum& a, const Datum& b) {
   return !(a == b);
}

bool operator<(const Datum& a, const Datum& b) {
   return    a.jahr() < b.jahr()
      || (a.jahr() == b.jahr() && a.monat() < b.monat())
      || (a.jahr() == b.jahr()
          && a.monat() == b.monat() && a.tag() < b.tag());
}

int datumDifferenz(const Datum& a, const Datum& b) {
   if(a == b)         // kurzer Prozeß bei Gleichheit
      return 0;
   bool richtigeReihenfolge = a < b;
   Datum frueher = a, spaeter = b;
   if(!richtigeReihenfolge)    {// ggf. vertauschen
      frueher = b; spaeter = a;
   }
   int Differenz = 0;
   // Achtung! nicht optimiert! (tageweises Hochzählen)
   while(frueher != spaeter) {
      ++Differenz;
      ++frueher;
   }
   return richtigeReihenfolge ? Differenz : -Differenz;
}

std::istream& operator>>(std::istream& is, Datum& d) {
   std::istream::sentry s(is); 
   if(s) {
      std::ios_base::iostate fehler = std::ios_base::goodbit;
      struct std::tm t;
      std::use_facet<std::time_get<char> >(is.getloc())
         .get_date(is, 0, is, fehler, &t);
      if (!fehler) {
         d = Datum(t.tm_mday, t.tm_mon + 1, t.tm_year + 1900);
      }
      is.setstate(fehler);
   } 
   return is;
}


// std::ostream& operator<<(std::ostream& os, const Datum& d) {
//    os << d.tag() << '.' << d.monat() << '.' << d.jahr();
//    return os;
// }

// neu
std::ostream& operator<<(std::ostream& os, const Datum& d) {
   std::ostream::sentry s(os); 
   if(s) {
      struct std::tm t;
      t.tm_mday  = d.tag();
      t.tm_mon   = d.monat()-1;
      t.tm_year  = d.jahr()-1900;
      std::use_facet<std::time_put<char> >(os.getloc())
         .put(os, os, ' ', &t, 'x'); // x : siehe strftime :locale~s appropriate date representation
   } 
   return os;
}
