/* cppbuch/k14/signalslot/QtBeispiel.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef QTBEISPIEL_H
#define QTBEISPIEL_H
#include"Zeichenflaeche.h"

class QtBeispiel : public QWidget {
   Q_OBJECT
public:
   QtBeispiel(QMainWindow* parent = 0) 
      : QWidget(parent),
        zeichenflaeche(new Zeichenflaeche), 
        qdial(new QDial),
        qspinbox(new QSpinBox) {
      qdial->setNotchesVisible(true);   // Marken sichtbar machen
      qspinbox->setFont(QFont("Helvetica", 12, QFont::StyleNormal));
      QPushButton *maxWertButton = new QPushButton("100%");
      maxWertButton->setFont(QFont("Helvetica", 16, QFont::Normal));

      // Connect-Aufrufe
      // qdial signalisiert Änderungen der Einstellung. Empfänger: zeichenflaeche, deren
      // Methode setRadius(int) aufgerufen wird
      connect(qdial, SIGNAL(valueChanged(int)), zeichenflaeche, 
              SLOT(setRadius(int)));
            
      // qdial signalisiert Änderungen der Einstellung. Empfänger:  qspinbox, deren
      // Methode setValue(int) aufgerufen wird
      connect(qdial, SIGNAL(valueChanged(int)), qspinbox, SLOT(setValue(int)));

      // qspinbox signalisiert Änderungen. Empfänger: qdial, dessen
      // Methode setValue(int) aufgerufen wird
      connect(qspinbox, SIGNAL(valueChanged(int)), qdial, SLOT(setValue(int)));

      connect(maxWertButton, SIGNAL(clicked()), this, SLOT(setMaxwert()));

      QGridLayout *gridLayout = new QGridLayout(this);
      gridLayout->addWidget(maxWertButton, 0, 0);
      gridLayout->addWidget(qspinbox, 1, 0);
      gridLayout->addWidget(qdial, 2, 0);
      gridLayout->addWidget(zeichenflaeche, 0, 1, 3, 1); 
      // Zeile, Spalte, erstreckt sich über 3 Zeilen und eine Spalte
      // Spalte 1 breiteren Raum einräumen
      gridLayout->setColumnStretch(1, 10);
      setLayout(gridLayout); 
      qdial->setValue(1);                                // Startwert
   }
   const Zeichenflaeche* getZeichenflaeche() const {
      return zeichenflaeche;
   }
private slots:
   void setMaxwert() {
      qdial->setValue(100);
   }
private:
   Zeichenflaeche* zeichenflaeche;
   QDial* qdial;
   QSpinBox* qspinbox;
};
#endif
