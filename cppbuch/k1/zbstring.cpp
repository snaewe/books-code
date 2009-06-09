/* cppbuch/k1/zbstring.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<string>     // Standard-String einschlieﬂen
#include<cstddef>    // size_t 
using namespace std;

int main() {         // Programm mit typischen String-Operationen
    // String-Objekt {\tt einString} anlegen und mit \dq hallo\dq\ initialisieren.
    // {\tt einString} kann ein beliebiger Name sein.
    string einString("hallo");

    // String ausgeben
    cout << einString << endl;

       // Beim Vektor w‰re stattdessen f¸r die Ausgabe
       //  eine Schleife notwendig, etwa der folgenden Art:

    // String zeichenweise ausgeben, ungepr¸fter Zugriff wie bei {\tt vector}:
    for(size_t i = 0; i < einString.size(); ++i) {
       cout << einString[i];
    }
    cout << endl;

    // String zeichenweise mit Indexpr¸fung ausgeben. Die Anzahl der
    // Zeichen kann bei Strings auch mit length() ermittelt werden.
    for(size_t i = 0; i < einString.length(); ++i) {
       cout << einString.at(i);
    }
    cout << endl;

/* Die Pr¸fung geschieht wie beim Vektor. Ein Versuch, {\tt einString.at(i)}
mit {\tt i} $\ge$ {\tt einString.size(i)} abzufragen, f¸hrt zum
Programmabbruch mit Fehlermeldung.*/

    // Kopie des Strings {\tt einString} erzeugen
    string eineStringKopie(einString);
    cout << eineStringKopie << endl;     // hallo

    // Kopie durch Zuweisung
    string diesIstNeu("neu!");
    eineStringKopie = diesIstNeu;
    cout << eineStringKopie << endl;     // neu!

    // Zuweisung einer Zeichenkette in Anf¸hrungszeichen
    eineStringKopie = "Buchstaben";
    cout << eineStringKopie << endl;     // Buchstaben

    // Zuweisung nur eines Zeichens vom Typ {\tt char}
    einString = 'X';
    cout << einString << endl;           // X

    // Strings mit dem {\tt +=}-Operator verketten
    einString += eineStringKopie;
    cout << einString << endl;           // XBuchstaben

    // Strings mit dem {\tt +}-Operator verketten
    einString = eineStringKopie + " ABC";
    cout << einString<< endl;           // Buchstaben ABC

    einString = "123" + eineStringKopie;
    cout << einString << endl;           // 123Buchstaben

    // Eine Erkl‰rung gibts erst im Kapitel \ref{Ueberladen von Operatoren},
    // aber folgendes geht {\em nicht}:
//    einString = "123" + "ABC";          // Fehler!

      string a("Albert"), z("Alberta");
      string b = a;
      if(a == b) cout << a << " == " << b << endl;
      else       cout << a << " != " << b << endl;

      if(a < z)  cout << a << " < " << z << endl;

      if(z > a)  cout << z << " > " << a << endl;

      if(z != a) cout << z << " != " << a << endl;
}
