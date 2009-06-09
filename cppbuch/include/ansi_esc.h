/* cppbuch/include/ansi_esc.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
/* Headerdatei fuer ANSI-ESC-Steuersequencen zur Bildschirm-
   und Cursorsteuerung für Unix-Workstations und PCs.
   ACHTUNG: Nicht alle Betriebssysteme unterstützen diese
  Steuersequencen!

  Die Sequenzen gehen auf zurück auf die VT100-Terminalreihe von DEC.
  Viele andere Terminals sind konform dazu. Einzelheiten siehe
  http://www.vt100.net/  Eine vollstänige Liste der Steuersequenzen
  findet man in
  http://vt100.net/docs/vt100-ug/        bzw.
  http://vt100.net/docs/vt102-ug/

  PC-MSDOS: Voraussetzung:  ANSI-Treiber in der config.sys einbinden.

  Win 95/98/NT: Ins Windows-Verzeichnis, z.B. C:\Windows oder
   C:\winnt gehen, dort im Verzeichnis system32 in der Datei
   autoexec.nt oder config.nt die Zeile
   device=%SystemRoot%\system32\ansi.sys
   eintragen. 
  ANSI.SYS stimmt nur in Teilen mit den VT100/VT102-Codes überein.

  Windows XP: ansi.sys wird NICHT unterstützt!
 
  Linux: fast alle Codes werden unterstützt.

  Bei Problemen mit Betriebssystemen wenden Sie sich bitte an
  den Hersteller, nicht an mich, oder suchen Sie auf deren
  Hilfe-Seiten im internet (MS-Knowledge Base u.a.) (danke! U.B.).

  Aufruf der Bildschirm- und Cursorsteuerung wie Funktionsaufruf,
  z.B.:  cls(); gotoxy(10, 50);

  Farbsteuerung durch Ausgabe, z.B.:
  cout << vrot << hgruen << "Roter Text auf grünem Hintergrund!";
  // weitere Ausgaben  ....
  normal();      // zurück zur normalen Bildschirmdarstellung

  Die folgenden Makros enthalten die wichtigsten Steuersequenzen.
*/
#ifndef ansi_esc_h
#define ansi_esc_h
#include<iostream>

// Bildschirmsteuerung
#define cls()     std::cout << "\033[2J"        // Bildschirm loeschen
#define cll()     std::cout << "\033[K"         // Zeile loeschen
#define hhell()   std::cout << "\033[7m"        // heller Hintergrund
#define blink()   std::cout << "\033[5m"        // Blinken ein
#define normal()  std::cout << "\033[0m"        // Normaldarstellung

// Cursorsteuerung
#define cauf(x)   std::cout << "\033[" << (x) << "A"  // Cursor um x nach oben
#define cab(x)    std::cout << "\033[" << (x) << "B"  // Cursor um x nach unten
#define cli(x)    std::cout << "\033[" << (x) << "D"  // Cursor um x nach links
#define cre(x)    std::cout << "\033[" << (x) << "C"  // Cursor um x nach rechts
#define home()    std::cout << "\033[H"               // Cursor gohome
#define pos()     std::cout << "\033[s"               // Cursor Position speichern
#define zurpos()  std::cout << "\033[u"               // Cursor zur gesp. Position
// Cursor positionieren (Zeile,Spalte):
#define gotoxy(x,y) std::cout << "\033["<<(x)<<";"<<(y)<<"H"

// Farben der Zeichen (v=Vordergrund)
#define vrot           "\033[1;31m"    // Rote Zeichen
#define vgruen         "\033[1;32m"    // Gruene Zeichen
#define vgelb          "\033[1;33m"    // Gelbe Zeichen
#define vblau          "\033[34m"      // Blaue Zeichen
#define vviolett       "\033[1;35m"    // Violette Zeichen
#define vcyan          "\033[36m"      // Cyanblaue Zeichen
#define vweiss         "\033[1;37m"    // Weisse Zeichen
#define vschwarz       "\033[0;30m"    // Schwarze Zeichen

//Farben des Hintergrundes
#define hrot           "\033[41m"      // Roter Hintergrund
#define hgruen         "\033[42m"      // Gruener Hintergrund
#define hgelb          "\033[1;43m"    // Gelber Hintergrund
#define hblau          "\033[44m"      // Blauer Hintergrund
#define hviolett       "\033[1;45m"    // Violetter Hintergrund
#define hcyan          "\033[46m"      // Cyanblauer Hintergrund
#define hweiss         "\033[1;47m"    // Weisser Hintergrund
#define hschwarz       "\033[0;40m"    // Schwarzer Hintergrund

#endif

