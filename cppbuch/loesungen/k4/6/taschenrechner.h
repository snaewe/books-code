/* cppbuch/loesungen/k4/6/taschenrechner.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef TASCHENRECHNER_H
#define TASCHENRECHNER_H
#include<string>

/** Taschenrechner-Klasse
 */
class Taschenrechner {
 public:
   /** Konstruktor.
    * @param ausdruck zu berechnender Ausdruck
    */
   Taschenrechner(const std::string& ausdruck);
   /** gibt den Ausdruck zurueck, mit dem das Objekt
    * initialisiert wurde.
    * @returns ausdruck
    */
   const std::string& getAnfrage();
   /** gibt das Ergebnis der Berechnung zurueck.
    * @returns Ergebnis
    */
   long getErgebnis();
 private:
   /** gibt das Ergebnis eines Ausdrucks zurueck.
    * @param c erstes auszuwertendes Zeichen
    * @returns Ergebnis
    */
   long ausdruck(char& c);

   /** gibt das Ergebnis der Auswertung eines Summanden zurueck.
    * @param c erstes auszuwertendes Zeichen
    * @returns Ergebnis
    */
   long summand(char& c);

   /** gibt das Ergebnis der Auswertung eines Faktors zurueck.
    * @param c erstes auszuwertendes Zeichen
    * @returns Ergebnis
    */
   long faktor(char& c);

   /** gibt das Ergebnis der Auswertung einer Zahl zurueck.
    * @param c erstes auszuwertendes Zeichen
    * @returns Ergebnis
    */
   long zahl(char& c);     

   /** liest das naechste Zeichen ein.
    * Leerzeichen werden ignoriert.
    * Bei Ende des Strings wird ein ungueltiges Zeichen
    * als Abbruchkriterium in c zurueckgegeben.
    * @param c das Zeichen
    */
   void get(char& c);
   std::string anfrage;
   size_t position;
   long ergebnis;
};
#endif
