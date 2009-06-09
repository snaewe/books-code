/* cppbuch/k14/label/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <QApplication>
#include <QLabel>
#include<iostream>

class MeinLabel : public QLabel{
public:
   MeinLabel(const char* text)
      : QLabel(text) {
   }
   ~MeinLabel() {
      std::cout << "Destruktor ~MeinLabel gerufen!" << std::endl;
   }
};

int main(int argc, char *argv[]) {
   QApplication app(argc, argv);
   MeinLabel* mlabel = new MeinLabel("Erstes Qt-Programm");
   mlabel->show();
   int ergebnis = app.exec();
   delete mlabel;
   return ergebnis;
}
