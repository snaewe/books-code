/* cppbuch/k7/mehrfach/basinit.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>

class Basis {
    public:
   Basis() { std::cout << "Basis-Standard-Konstruktor\n"; }
        Basis(const char* a)  { std::cout << a << std::endl; }
        virtual ~Basis(){}  // virtueller Destruktor
};

class Links : virtual public Basis {
    public:
         Links(const char* a)
//  : Basis(a)             // siehe Text
         { }
};

class Rechts : virtual public Basis {
    public:
         Rechts(const char* a) : Basis(a) {}
};

class Unten: public Links, public Rechts {
    public:
         Unten(const char* a) :
//       Basis(a),             // siehe Text
         Links(a), Rechts(a)  {}
};

int main() {
    Unten x("Unten");
    Links li("Links");
}
