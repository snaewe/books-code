/* cppbuch/k14/dialog/NamenDialog.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef NAMENDIALOG_H
#define NAMENDIALOG_H
#include<QtGui>

class NamenDialog : public QDialog {
Q_OBJECT
public:
   NamenDialog(QWidget* parent = 0) 
      :  QDialog(parent) {
      setWindowTitle("Name?");
      eingabezeile = new QLineEdit;
      QLabel* text = new QLabel("&Namen eingeben:");
      text->setBuddy(eingabezeile);
      QPushButton* okButton = new QPushButton("OK");
      QPushButton* abbruchButton = new QPushButton("Abbruch");

      QBoxLayout* zeile1 = new QBoxLayout(QBoxLayout::LeftToRight);
      zeile1->addWidget(text);
      zeile1->addWidget(eingabezeile);
      QBoxLayout* zeile2 = new QBoxLayout(QBoxLayout::LeftToRight);
      zeile2->addWidget(okButton);
      zeile2->addWidget(abbruchButton);
      QBoxLayout* alles = new QBoxLayout(QBoxLayout::TopToBottom);
      alles->addLayout(zeile1);
      alles->addLayout(zeile2);
      setLayout(alles);

      connect(okButton, SIGNAL(clicked()),this, SLOT(accept()));
      connect(abbruchButton, SIGNAL(clicked()),this, SLOT(reject()));
   }
   QString getText() {
      return eingabezeile->text();
   }
private:
   QLineEdit* eingabezeile;
};

#endif
