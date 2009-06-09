/* cppbuch/k3/qsort.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<vector>
#include<cstdlib>  // abs(int)
using namespace std;

// Templates mit T als Parameter für den Datentyp (Platzhalter)
template<typename T>
void tausche(T &a, T &b) {    // a und b vertauschen
    const T temp = a;
    a = b;
    b = temp;
}

template<typename T>
bool kleiner(const T& a, const T& b)   {// Vergleich
    return (a<b);
}

// Spezialisierung für int 
// hier: Vergleich nach Absolutbetrag
template<>
bool kleiner<>(const int& a, const int& b)    {
    return abs(a) < abs(b);
}

template<typename T>
void drucke(const vector<T>& V) {
   for (unsigned int i = 0; i < V.size(); ++i) {
         cout << V[i] <<" ";
   }
   cout << endl;
}

template<typename T>
void quicksort(vector<T>& a, int links, int rechts) {
    int li = links; int re = rechts;
    T el = a[(links+rechts)/2];
    do {
         while(kleiner(a[li],el)) ++li;
         while(kleiner(el,a[re])) --re;
         if (li <  re) tausche(a[li],a[re]);
         if (li <= re) {++li; --re;}
    } while (li <= re);
    if (links < re)  quicksort(a, links, re);
    if (li < rechts) quicksort(a, li, rechts);
}

int main () {
    vector<double> dV(8);
    dV[0]=1.09; dV[1]=2.2; dV[2]=79.6; dV[3]=-1.9; dV[4]=2.7;
    dV[5]=100.9; dV[6]=18.8; dV[7]=99.9;

    cout << "Sortierung von double-Zahlen nach Größe:" << endl;
    quicksort(dV, 0, dV.size()-1);
    drucke(dV);

    vector<int> iV(10);
    iV[0]=100; iV[1]=22;  iV[2]=-3; iV[3]=44; iV[4]=6;
    iV[5]= -9; iV[6]=-2;  iV[7]= 1;  iV[8]=8;  iV[9]=9;

    cout << "Sortierung von int-Zahlen nach Absolutbetrag:" << endl;
    quicksort(iV, 0, iV.size()-1);
    drucke(iV);

    cout <<  (kleiner(3, 6) ? 3 : 6) << endl;
} // Ende von {\tt main()}
