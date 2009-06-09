/* cppbuch/k1/bloecke.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;
/* {\tt a} und {\tt b} werden außerhalb eines jeden Blocks deklariert. Sie sind
   damit innerhalb eines jeden anderen Blocks gültig und heißen daher
   globale Variablen.*/
int a = 1, b = 2;

int main()  {   // Ein neuer \Index{Block} beginnt.
    cout << "globales a= " << a << endl;  // Ausgabe von {\tt a}

    /* Innerhalb des Blocks wird eine Variable {\tt a} deklariert. Ab
   jetzt ist das \index{global} globale {\tt a} noch gültig, aber
   nicht mehr unter dem Namen {\tt a} sichtbar, wie die Folgezeile
   zeigt.*/

    int a = 10;
    // Der Wert des lokalen {\tt a} wird ausgegeben:
    cout << "lokales a= " << a << endl;

    /* Das globale {\tt a} lässt sich nach der Deklaration des
   lokalen {\tt a} nur noch mit Hilfe des Bereichsoperators {\tt ::}
   \engl{scope ope\-ra\-tor} ansprechen. Ausgabe von {\tt
   ::a}.*/

    cout << "globales ::a= " << ::a << endl;
    {  // Ein neuer Block innerhalb des bestehenden beginnt.

       int b = 20;
       /* Variable {\tt b} wird innerhalb dieses Blocks deklariert. Damit
  wird das globale {\tt b} zwar nicht ungültig, aber unsichtbar.*/
       int c = 30; //  {\tt c} wird innerhalb dieses Blocks deklariert.
       // Die Werte von {\tt b}  und {\tt c}  werden ausgegeben.
       cout << "lokales b = " << b << endl;
       cout << "lokales c = " << c << endl;


       /* Wie oben beschrieben, ist das globale {\tt b} nur über den
            Scope-Operator ansprechbar. Ausgabe von {\tt
            ::b}.*/

       cout << "globales ::b = " << ::b << endl;
    } // Der innere Block wird geschlossen. Damit ist das globale {\tt b}
      // auch ohne Scope-Operator wieder sichtbar:
    cout << "globales b wieder sichtbar: b = " << b << endl;

    // cout << "c = " << c << endl;} // Fehler, siehe Text
} //  Ende des äußeren Blocks
