/* cppbuch/k14/signalslot/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <QApplication>
#include "window.h"

int main(int argc, char *argv[]) {
   QApplication app(argc, argv);
   Window* win = new Window;
   win->show();
   return app.exec();
}
