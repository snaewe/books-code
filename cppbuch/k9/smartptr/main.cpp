/* cppbuch/k9/smartptr/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"smartptr.t"
#include<iostream>

using namespace std;

class A {
    public:
      virtual void hi() {
           cout << "hier ist A::hi()" << endl;
      }

      virtual ~A() {
           cout << "A::Destruktor" << endl;
      }
};

class B : public A {
    public:
      virtual void hi() {
           cout << "hier ist B::hi()" << endl;
      }

      virtual ~B() {
           cout << "B::Destruktor" <<endl;
      }
};


// Übergabe per Wert ist hier nicht möglich, wohl aber per Referenz:
template<class T>
void perReferenz(const SmartPointer<T>& p) {
    cout << "Aufruf: perReferenz(const SmartPointer<T>&):";
    p->hi(); // (p.operator->())->hi();
}


int main() {
    cout << "Zeiger auf dynamische Objekte:" << endl;
    cout << "Konstruktoraufruf" << endl;
    SmartPointer<A> spA(new A);

    cout << "Operator ->" << endl;
    spA->hi();

    cout << "Operator *" << endl;
    (*spA).hi();

    cout << "Polymorphismus:" << endl;
    SmartPointer<A> spAB(new B);    // zeigt auf {\tt B}-Objekt
    spAB->hi();                     // {\tt B::hi()}

    // Parameterübergabe eines {\tt SmartPointer}
    perReferenz(spAB);

/*
Die  Wirkung der Sicherungsmaßnahmen im Vergleich zu einfachen
C-Zeigern zeigen die folgenden Zeilen:
*/

    SmartPointer<B> spUndef;
    try {
    if (!spUndef)          // = {\tt if(!(spUndef.operator bool()))}
        cout << "undefinierter Zeiger:" << endl;
    // Zugriff auf nicht-initialisierten Zeiger bewirkt Laufzeitfehler:
    spUndef->hi();                  // Laufzeitfehler!
    (*spUndef).hi();                // Laufzeitfehler!
    } catch(NullPointerException ex) {
       cout << "Laufzeitfehler: " << ex.what() << endl;
    }

/***********
//  alle folgenden Anweisungen bewirken
//  Fehlermeldungen des Compilers

//  Typkontrolle: ein {\tt B} ist kein {\tt A}!
    SmartPointer<B> spTyp(new A);         //  Fehler!

//  keine Initialisierung mit Kopierkonstruktor
    SmartPointer<A> spY = spA;   // Fehler!

//  Zuweisung ist nicht möglich (privater {\tt =}-Operator):
    SmartPointer<A> spA1;
    spA1 = spA;                                // Fehler!
***********/
}
