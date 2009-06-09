/* cppbuch/k14/signalslot/window.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef WINDOW_H
#define WINDOW_H
#include "QtBeispiel.h"

class Window : public QMainWindow {
   Q_OBJECT

public:
   Window() {
      setAttribute(Qt::WA_DeleteOnClose);
      setGeometry(100, 100, 400, 300);
      widget = new QtBeispiel(this);
      setCentralWidget(widget);
      menuAnlegen();
      statuszeileAnlegen();
      connect(widget->getZeichenflaeche(), SIGNAL(radiusChanged(int)), 
              this, SLOT(statuszeileAktualisieren(int)));
   }

private slots:
   void statuszeileAktualisieren(int radius) {
      if(radius < 51) {
         statusLabel->setText("<span style=\"color:green\">klein</span>");
      }
      else{
         statusLabel->setText("<span style=\"color:red\">gross</span>");
      }
   }
private:
   void menuAnlegen() {
      fileMenu = menuBar()->addMenu(tr("&Datei"));
      QAction* quitAction = new QAction(tr("&Ende"), this);
      quitAction->setShortcut(tr("Ctrl+Q"));
      quitAction->setStatusTip(tr("Programm beenden"));
      fileMenu->addAction(quitAction);
      // qApp ist globale Variable der Applikation
      connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
   }

   void statuszeileAnlegen() {
      statusLabel = new QLabel("nicht bewegt");   
      statusBar()->addWidget(statusLabel);
   }
   QtBeispiel* widget;
   QMenu* fileMenu;
   QLabel* statusLabel;
};

#endif
