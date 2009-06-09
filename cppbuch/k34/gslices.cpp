/* cppbuch/k34/gslices.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <iostream>
#include "valarray"
using namespace std;

template<class T>
void print(const valarray<T>& v) {
   for(size_t i = 0; i < v.size(); ++i) 
     cout << '\t' << v[i];
   cout << endl;
}

void printIndizes(const gslice& gs) {
   for(size_t r = 0; r < gs.size()[0]; ++r) {  // Zeilen
     for(size_t c = 0; c < gs.size()[1]; ++c)  // Spalten
        cout << '\t' 
	     << gs.start()
                + r * gs.stride()[0]
                + c * gs.stride()[1];
     cout << endl;
   }
}

void print3DIndizes(const gslice& gs) {
   for(size_t x = 0; x < gs.size()[0]; ++x)  
     for(size_t y = 0; y < gs.size()[1]; ++y) 
       for(size_t z = 0; z < gs.size()[2]; ++z) 
	 cout << " ("<<x<<", "<<y<<", "<<z<<", "
	     << gs.start() + x*gs.stride()[0]
                           + y*gs.stride()[1]
                           + z*gs.stride()[2]
	      << ")\n";
   cout << endl;
}

// index() aus Stroustrup C++PL3 22.4.8
size_t index(const gslice& gs, size_t i, size_t j) {
 return gs.start()+i*gs.stride()[0]+j*gs.stride()[1];
}


//  2D-Submatrix aus einer durch gs definierten 2D-Matrix erzeugen
gslice submatrix_gslice(const gslice& gs, 
                              size_t position, 
                              size_t rows, 
                              size_t cols) {
  size_t sz[]  = {rows, cols};
  size_t str[] = {gs.size()[1], 1};
  valarray<size_t> sizes(sz, 2);
  valarray<size_t> strides(str, 2);
  return gslice(position, sizes, strides);
}

int main() {
   valarray<size_t> sizes(2);
   valarray<size_t> strides(2);
   cout << endl << "\nZeige Beispiel aus Stroustrup C++PL3 22.4.8:\n";
   sizes  [0] = 2; sizes  [1] = 3; 
   strides[0] = 4; strides[1] = 1;
   gslice G1(0, sizes, strides);
   cout << "Zeilen-Indizes:  ";
   for(size_t i = 0; i< G1.size()[0]; ++i) cout << index(G1, i, 0)<< " ";
   cout << "\nSpalten-Indizes   :  ";
   for(size_t i = 0; i< G1.size()[1]; ++i) cout << index(G1, 0, i)<< " ";
   cout << endl;
   printIndizes(G1);

   cout << endl << "\nzeige Beispiel aus C++ Standard 26.3.6.1, nur 2 Dimensionen:\n";
   sizes  [0] = 4; sizes  [1] = 3; 
   strides[0] = 4; strides[1] = 1;
   gslice G2(3, sizes, strides);
   printIndizes(G2);

   cout << endl << "\nZeige vollständiges Beispiel aus C** Standard 26.3.6.1:\n";
   valarray<size_t> sizes3(3);
   valarray<size_t> strides3(3);
   sizes3  [0] = 2;  sizes3  [1] = 4; sizes3  [2] = 3; 
   strides3[0] = 19; strides3[1] = 4; strides3[2] = 1;
   gslice G3(3, sizes3, strides3);
   print3DIndizes(G3);


   cout << " valarray als 4x5 Matrix (Index == Wert):\n";
   const size_t ZEILEN = 4, SPALTEN = 5;
   valarray<double> v(ZEILEN*SPALTEN);  
   for(size_t i = 0; i < v.size(); ++i) v[i]=i;

   for(size_t i = 0; i < ZEILEN; ++i) 
     print(valarray<double>(v[slice(i*SPALTEN, SPALTEN, 1)]));
   cout << endl;

   sizes  [0] = ZEILEN; sizes  [1] = SPALTEN; 
   strides[0] = SPALTEN; strides[1] = 1;
   // gslice in der Ecke oben links konstruieren
   gslice g(0, sizes, strides);
   cout << endl << "Indizes der 4x5 Matrix:\n";
   printIndizes(g);

   cout << "\nZeige Indizes der 3x4 Submatrix in Position 0:\n";
   printIndizes(submatrix_gslice(g, 0, 3, 4));

   cout << "\nZeige Indizes der 3x4 Submatrix in Position 1:\n";
   printIndizes(submatrix_gslice(g, 1, 3, 4));

   cout << "\nZeige Indizes der 3x4 Submatrix in Position 6:\n";
   printIndizes(submatrix_gslice(g, 6, 3, 4));

   cout << "\nZeige Indizes der 2x3 Submatrix in Position 6:\n";
   gslice G4(submatrix_gslice(g, 6, 2, 3));
   printIndizes(G4);

   cout << "\nZeige 2x3 Submatrix in Position 6:\n";
   valarray<double> sub1 = v[G4];
   cout << "sub1.size()= " << sub1.size() << endl;
   print(sub1);
   cout << "\nSetze Submatrix zu 0:\nMatrix vorher:\n";
   for(size_t i = 0; i < ZEILEN; ++i) 
     print(valarray<double>(v[slice(i*SPALTEN, SPALTEN, 1)]));
   cout << endl << " und danach:\n";
   v[G4] = 0;   // Setze 2x3 Submatrix zu 0
   for(size_t i = 0; i < ZEILEN; ++i) 
     print(valarray<double>(v[slice(i*SPALTEN, SPALTEN, 1)]));
   cout << endl;

}
