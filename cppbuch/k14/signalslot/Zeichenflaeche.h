/* cppbuch/k14/signalslot/Zeichenflaeche.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef ZEICHENFLAECHE_H
#define ZEICHENFLAECHE_H
#include <QtGui>

class Zeichenflaeche : public QWidget {
   Q_OBJECT
public:
   Zeichenflaeche() {
      aktuellerRadius = 1;
      setPalette(QPalette(QColor(255, 255, 255)));  // weiﬂ
      setAutoFillBackground(true);
   }

public slots:
   void setRadius(int radius) {
      if(radius != aktuellerRadius) {          // nur dann etwas tun!
         if (radius < 1) {
            radius = 1;
         }
         aktuellerRadius = radius;
         update();                             // paintEvent()-Aufruf einplanen
         emit radiusChanged(aktuellerRadius);  // ƒnderung signalisieren
      }
   }

signals:
   void radiusChanged(int neuerRadius);

protected:
   void paintEvent(QPaintEvent*) {  // Parameter wird nicht benutzt
      QPainter painter(this);
      // Transformation der Koordinaten auf die Zeichenfl‰che
      painter.translate(0, rect().height());
      int offset = rect().height()/2;
      int r = aktuellerRadius;
      // einen durch ein Rechteck definierten Kreis zeichnen:
      painter.drawEllipse(QRectF(offset-r, -offset-r, 2*r, 2*r));
   }
private:
   int aktuellerRadius;
};
#endif
