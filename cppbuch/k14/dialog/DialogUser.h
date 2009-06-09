/* cppbuch/k14/dialog/DialogUser.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef DialogUser_h
#define DialogUser_h
#include"NamenDialog.h"

class DialogUser : public QMainWindow {
   Q_OBJECT
public:
   DialogUser() {
      setAttribute(Qt::WA_DeleteOnClose);
      namendialog = new NamenDialog(this);
      namendialog->setModal(true);
      namendialog->show();
      connect(namendialog, SIGNAL(accepted()), this, SLOT(dialogBeendet()));
      connect(namendialog, SIGNAL(rejected()), this, SLOT(dialogBeendet()));
   }
private slots:
   void dialogBeendet() {
      // Zuerst Ergebnis abfragen (hier mit Anzeige) ...
      QString str("Dialog abgebrochen");
      if(namendialog->result() == QDialog::Accepted) {  // doch erfolgreich
          str = namendialog->getText();
      }
      QMessageBox msgBox;
      QString msg("Dialogergebnis: ");
      msg += str;
      msgBox.setText(msg);
      msgBox.exec();
      // und dann Dialog schlieﬂen
      delete namendialog;
   }
private:
   NamenDialog* namendialog;
};
#endif
