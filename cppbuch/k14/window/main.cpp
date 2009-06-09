/* cppbuch/k14/window/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <QApplication>
#include"Window.h"

int main(int argc, char *argv[]) {
   QApplication app(argc, argv);
   Window* win1 = new Window();
   win1->show();
   Window* win2 = new Window();
   win2->show();
   return app.exec();
}
