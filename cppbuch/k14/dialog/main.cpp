/* cppbuch/k14/dialog/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"DialogUser.h"

int main(int argc, char *argv[]) {
   QApplication app(argc, argv);
   DialogUser* dialogUser = new DialogUser;
   dialogUser->show();
   return app.exec();
}
