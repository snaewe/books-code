/* cppbuch/k14/window/Window.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef WINDOW_H
#define WINDOW_H
#include<QtGui>
#include<fstream>

class Window : public QMainWindow {
public:
   Window() {
      setAttribute(Qt::WA_DeleteOnClose);
   }
   ~Window() {
      //save(); Alternative ohne Benutzerinteraktion
   }
protected:
   void closeEvent(QCloseEvent* ce) {
      int antwort = QMessageBox::warning(this, "Titel", 
                                  "closeEvent gerufen. Sichern?",
                                   QMessageBox::Yes|QMessageBox::No);
      if(antwort == QMessageBox::Yes) {
         save();
      }
   }
private:
   void save() {
      std::ofstream log("daten.txt");
      log << "gesicherte Daten" << std::endl;
      log.close();
   }
};










#endif



