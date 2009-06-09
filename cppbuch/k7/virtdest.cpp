/* cppbuch/k7/virtdest.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

#define PRINT(X) cout << (#X) << " = " << (X) << endl

class Basis {
    int bWert;
  public:
    Basis(int b = 0)
    : bWert(b) {
    }

    virtual ~Basis() {            // virtueller Destruktor!
        cout << "Objekt " << bWert
             << " Basis-Destruktor aufgerufen!\n";
    }
};

class Abgeleitet : public Basis {
    double aWert;
  public:
    Abgeleitet(int b = 0, double a = 0.0)
    : Basis(b), aWert(a)
    {}

    ~Abgeleitet() {
         cout <<"Objekt " << aWert
              << " Abgeleitet-Destruktor aufgerufen!\n";
     }
};

int main () {
    Basis *pb = new Basis(1);
    PRINT(sizeof(*pb));

    Abgeleitet *pa = new Abgeleitet(2, 2.2);
    PRINT(sizeof(*pa));

    Basis *pba = new Abgeleitet(3, 3.3);
    PRINT(sizeof(*pba));

    cout << "pb löschen:\n";
    delete pb;                         // ok

    cout << "pa löschen:\n";
    delete pa;                         // ok

    cout << "pba löschen:\n";
    delete pba;          // ok nur mit virtuellem Destruktor!
}
