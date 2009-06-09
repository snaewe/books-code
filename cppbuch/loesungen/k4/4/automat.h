/* cppbuch/loesungen/k4/4/automat.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef AUTOMAT_H
#define AUTOMAT_H 

class GetraenkeAutomat {
    public:
      GetraenkeAutomat(int anzahl, int dosenpreis);

      bool istGesperrt() const   { return gesperrt;}


      bool rueckgeldVorhanden() const {
          return rueckgeld > 0;
      }

      bool doseHerausgegeben() const { return doseInAusgabe;}

      int  getraenkePreis() const { return preisProDose;}

      void doseFreigeben() { doseInAusgabe = false;}

      void geldPruefenUndDoseHerausgeben();

      void muenzenAkzeptieren(int M);

      int geldRueckGabe();

    private:
      int anzahlDosen;
      int preisProDose;
      int einnahmen;
      int eingeworfeneMuenzen;
      int rueckgeld;
      bool doseInAusgabe;
      bool gesperrt;

      // Übergabe per Wert verbieten:
      GetraenkeAutomat(const GetraenkeAutomat&);
};
#endif
