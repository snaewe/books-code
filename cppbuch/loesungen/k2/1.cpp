/* cppbuch/loesungen/k2/1.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <iostream>
#include<string>
#include <fstream>
using namespace std;

int main() {
   /* Eingabe der notwendigen Daten  */
   cout << "Tilgungsplan berechnen"  << endl;
   double rate, zinssatzProzent, zinssatz, zinsen, schulden;
   int startmonat, startjahr, laufzeit;
   /* Um das Programm kurz zu halten, werden fehlerhafte
      Eingaben bis auf die Höhe der Rate hier NICHT abgefangen
      und es gibt KEINE Fehlerbehandlung der Dateiausgabe! */
   cout << "Kreditsumme:";
   cin >> schulden;
   cout << "Zinssatz in %:";
   cin >> zinssatzProzent;
   cout << "Anfangsmonat (1..12):";
   cin >> startmonat;
   cout << "Anfangsjahr (jjjj):";
   cin >> startjahr;
   cout << "Laufzeit in Jahren:";
   cin >> laufzeit;
   int mindestrateInCent = (int)(schulden*zinssatzProzent/12.0+1.0);
   double mindestrate = 0.01*mindestrateInCent;
   do {
      cout << "monatliche Rate (mindestens " 
           << mindestrate << "):";
      cin >> rate;
      if(rate < mindestrate)
         cout << "Falsche Eingabe";
   } while(rate < mindestrate);
   /* Berechnung und Ausgabe */
   ofstream ausgabe("tilgungsplan.txt");
   ausgabe << "Tilgungsplan" << endl;
   /* Formatierungshilfen, Näheres siehe Kapitel 13 */
   ausgabe.setf(ios::showpoint|ios::fixed, ios::floatfield);
   ausgabe.precision(2); // Nachkommastellen
   ausgabe << "Anfangsschulden  : " << schulden << endl;
   ausgabe << "Zinssatz nominal : " << zinssatzProzent << " %" 
           << endl << endl;
   double summeBezahlt = 0.0; 
   double summeTilgung = 0.0; 
   double summeZinsen = 0.0;
   double gesamtSummeBezahlt = 0.0; 
   double gesamtSummeTilgung = 0.0; 
   double gesamtSummeZinsen = 0.0;
   int monat = startmonat;
   int jahr = startjahr;
   // zinssatz ab hier nicht mehr in Prozent!
   zinssatz = 0.01 * zinssatzProzent;
   do  {
      if(monat == 1 || (monat == startmonat && jahr ==startjahr))
         ausgabe << "Zahlmonat     Rate    Zinsen   Tilgung"
            "      Rest" << endl;

      zinsen = schulden*zinssatz/12.;
      // kaufmännische Rundung:
      zinsen = 100.0*zinsen + 0.5;
      long temp = (long)zinsen; // Nachkommateil abhacken
      zinsen = (double)temp / 100.0;

      // letzte Rate reduzieren, falls genug abbezahlt worden ist
      if(rate > schulden + zinsen) { 
         rate = schulden + zinsen;
      }
      double tilgung = rate - zinsen;
      schulden -= tilgung;
      summeBezahlt += rate;
      summeTilgung += tilgung;
      summeZinsen += zinsen;

      if(monat < 10) {
         ausgabe << " ";
      }
      ausgabe << " " <<  monat << "." << jahr;
      ausgabe.width(10); ausgabe <<  rate;
      ausgabe.width(10); ausgabe <<  zinsen;
      ausgabe.width(10); ausgabe <<  tilgung;
      ausgabe.width(10); ausgabe <<  schulden;
      ausgabe << endl;
      if(monat == 12 || schulden < 0.001) {
         ausgabe << "Summen: ";
         ausgabe.width(10); ausgabe <<  summeBezahlt;
         ausgabe.width(10); ausgabe <<  summeZinsen;
         ausgabe.width(10); ausgabe <<  summeTilgung;
         ausgabe << "  pro Jahr" << endl << endl;
         gesamtSummeBezahlt += summeBezahlt; 
         gesamtSummeTilgung += summeTilgung; 
         gesamtSummeZinsen += summeZinsen;
         summeBezahlt = 0.0; 
         summeTilgung = 0.0; 
         summeZinsen = 0.0;
      }
      monat++;
      if(monat==13) {
         ++jahr;
         monat = 1;
      }
   } while(schulden > 0.0001);
   ausgabe << "Gesamt: ";
   ausgabe.width(10); ausgabe <<  gesamtSummeBezahlt;
   ausgabe.width(10); ausgabe <<  gesamtSummeZinsen;
   ausgabe.width(10); ausgabe <<  gesamtSummeTilgung;
   ausgabe << endl;
   ausgabe.close();
   cout << "Ergebnis siehe tilgungsplan.txt" << endl;
}
