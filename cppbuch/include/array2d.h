/* cppbuch/include/array2d.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef ARRAY2D_H
#define ARRAY2D_H
// 2-dim. Array-Klasse mit zusammenhängendem (contiguous) Memory-Bereich
#include<stdexcept>
#include<utility>
#include<algorithm>
#include<iostream>
// ggf auskommentieren
//#define TEST

#ifdef TEST
#define TESTAUSGABE(x) std::cout << #x << std::endl
#else
#define TESTAUSGABE(x) /* nichts */
#endif

// Indexprüfung:
// Wie bei der Standard-Vector-Klasse ist der Zugriff über [][] ungeprüft,
// der Zugriff über at(i, j) geprüft.
// Ansonsten ist die Klasse teilweise STL-kompatibel

template<typename T>  
class Array2d {
 public:
   // Typedefs wegen STL-Konformität
   typedef T value_typ;
   typedef T& reference;
   typedef T* iterator;
   typedef const T* const_iterator;
   typedef T* pointer;
   typedef const T* const_pointer;
   typedef int difference_type;
   typedef unsigned int size_type;

   Array2d(int zeilen, int spalten); 
   Array2d(int zeilen, int spalten, const T& init); 
   Array2d(const Array2d& a); 
   Array2d(Array2d&& a); 
   ~Array2d(); 
   Array2d& operator=(const Array2d& a); 
   Array2d& operator=(Array2d&& a); 
   int getZeilen() const;
   int getSpalten() const;
   void init(const T& wert);  // Alle Elemente mit wert initialisieren
   const T& at(int z, int s) const;
   T& at(int z, int s);
   const T* operator[](int z) const;
   T* operator[](int z);
   const T* data() const;
   // STL-entsprechende Funktionen
   size_t size() const  { return zeilen*spalten;}
   iterator begin() { return arr;}
   iterator end() { return arr + zeilen*spalten;}
   const_iterator begin() const { return arr;}
   const_iterator end() const { return arr + size();}
   const_iterator cbegin() const { return arr;}
   const_iterator cend() const { return arr + size();}
   void swap(Array2d& a);
 private:
   void checkIndizes(int z, int s) const;
   void checkDimension(const Array2d<T>& a) const;
   int zeilen;
   int spalten;
   T* arr;
};


// relationale Operatoren
template<typename T>
bool operator==(const Array2d<T>& a, const Array2d<T>& b) {
   if(a.getZeilen() != b.getZeilen()) return false;
   if(a.getSpalten() != b.getSpalten()) return false;
   return std::equal(a.begin(), a.end(), b.begin());
}

template<typename T>
bool operator<(const Array2d<T>& a, const Array2d<T>& b) {
   return std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
}
// um aus == und < alle anderen relationalen Operatoren bei Bedarf 
// automatisch zu bilden:
using namespace std::rel_ops;

// Konstruktoren
template<typename T>
Array2d<T>::Array2d(int z, int s) 
   : zeilen(z), spalten (s), 
     arr(new T[z*s]) {
}

template<typename T>
Array2d<T>::Array2d(int z, int s, const T& wert) 
   : zeilen(z), spalten (s), arr(new T[z*s]) {
   init(wert);
}

template<typename T>
Array2d<T>::Array2d(const Array2d<T>& a) 
   : zeilen(a.getZeilen()), spalten (a.getSpalten()), 
     arr(new T[zeilen*spalten]) {
   for(size_t i = 0; i < size(); ++i) {
      arr[i] = a.arr[i];
   }
   TESTAUSGABE(Array2d(const Array2d<T>& a));
}

template<typename T>
Array2d<T>::Array2d(Array2d<T>&& a)  // moving Kopierkonstruktor
   : zeilen(0), spalten(0), arr(0) {
   swap(a);
   TESTAUSGABE(Array2d(const Array2d<T>&& a) (move));
}

template<typename T>
void Array2d<T>::swap(Array2d<T>& a) {
   int tmpzeilen = zeilen;
   int tmpspalten = spalten;
   T* tmparr = arr;
   zeilen = a.zeilen;
   spalten = a.spalten;
   arr = a.arr;
   a.zeilen = tmpzeilen;
   a.spalten = tmpspalten;
   a.arr = tmparr;
}

template<typename T>
Array2d<T>::~Array2d() {
   delete [] arr;
}

template<typename T>
Array2d<T>& Array2d<T>::operator=(const Array2d<T>& a) {
   checkDimension(a);
   for(size_t i = 0; i < size(); ++i) {
      arr[i] = a.arr[i];
   }
   TESTAUSGABE(operator=(const Array2d<T>& a));
   return *this;
}

template<typename T>
Array2d<T>& Array2d<T>::operator=(Array2d<T>&& a) {
   swap(a);
   TESTAUSGABE(operator=(const Array2d<T>&& a) (move));
   return *this;
}

template<typename T>
inline int Array2d<T>::getZeilen() const { return zeilen; }

template<typename T>
inline int Array2d<T>::getSpalten() const { return spalten; }

template<typename T>
void Array2d<T>::init(const T& wert) { 
   for(size_t i = 0; i < size(); ++i) {
      arr[i] = wert;
   }
}

template<typename T>
inline const T* Array2d<T>::operator[](int z) const { 
   return &arr[z*spalten]; 
}

template<typename T>
inline T* Array2d<T>::operator[](int z) { 
   return &arr[z*spalten]; 
}

template<typename T>
inline void Array2d<T>::checkIndizes(int z, int s) const {
   if(z < 0 || z >= zeilen) 
      throw std::range_error("Array2d: Zeile ausserhalb des erlaubten Bereichs");
   if(s < 0 || s >= spalten) 
      throw std::range_error("Array2d: Spalte ausserhalb des erlaubten Bereichs");
}

template<typename T>
inline void Array2d<T>::checkDimension(const Array2d<T>& a) const {
   if(zeilen != a.getZeilen() || spalten != a.getSpalten()) 
      throw std::range_error("Array2d: ungleiche Zeilen-/Spaltenanzahl");
}

template<typename T>
inline const T& Array2d<T>::at(int z, int s) const { 
   checkIndizes(z, s);
   return arr[z*spalten + s]; 
}

template<typename T>
inline T& Array2d<T>::at(int z, int s) { 
   checkIndizes(z, s);
   return arr[z*spalten + s]; 
}

template<typename T>
inline const T* Array2d<T>::data() const { 
   return arr; 
}


// Globale Funktion zur Ausgabe
template<typename T>
void printArray(const Array2d<T>& a) {
   for(int z=0; z < a.getZeilen(); ++z) {
       for(int s=0; s < a.getSpalten(); ++s) {
          std::cout << a[z][s] << " ";
       }
       std::cout << std::endl;
   }
}
#endif
