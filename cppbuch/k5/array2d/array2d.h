/* cppbuch/k5/array2d/array2d.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef ARRAY2D_H
#define ARRAY2D_H
#include<stdexcept>
#include<algorithm>
#include<iostream>

// Indexprüfung:
// Wie bei der Standard-Vector-Klasse ist der Zugriff über [][] ungeprüft,
// der Zugriff über at(i, j) geprüft.

template<typename T>  
class Array2d {
 public:
   Array2d(int zeilen, int spalten); 
   Array2d(int zeilen, int spalten, const T& init); 
   Array2d(const Array2d& arr); 
   ~Array2d(); 
   Array2d& operator=(const Array2d& arr); 
   int getZeilen() const;
   int getSpalten() const;
   void init(const T& wert);  // Alle Elemente mit wert initialisieren
   const T& at(int z, int s) const;
   T& at(int z, int s);
   const T* operator[](int z) const;
   T* operator[](int z);
 private:
   int zeilen;
   int spalten;
   T** arr;
};

template<typename T>
Array2d<T>::Array2d(int z, int s) 
   : zeilen(z), spalten (s), 
     arr(new T*[z]) {
   for(int z=0; z < zeilen; ++z) {
      arr[z] = new T[spalten];
   }
}

template<typename T>
Array2d<T>::Array2d(int z, int s, const T& wert) 
   : zeilen(z), spalten (s), 
     arr(new T*[z]) {
   for(int z=0; z < zeilen; ++z) {
      arr[z] = new T[spalten];
   }
   init(wert);
}

template<typename T>
Array2d<T>::Array2d(const Array2d& a) 
   : zeilen(a.zeilen), spalten (a.spalten), 
     arr(new T*[zeilen]) {
   for(int z=0; z < zeilen; ++z) {
      arr[z] = new T[spalten];
      for(int s = 0; s < spalten; ++s) {
         arr[z][s] = a.arr[z][s];
      }
   }
}

template<typename T>
Array2d<T>::~Array2d() {
   for(int z=0; z < zeilen; ++z) {
      delete [] arr[z];
   }
   delete [] arr;
}


template<typename T>
Array2d<T>& Array2d<T>::operator=(const Array2d& a) {
   Array2d<T> tmp(a);  // temporäres Objekt erzeugen
   std::swap(zeilen, tmp.zeilen);    // Verwaltungsdaten vertauschen
   std::swap(spalten, tmp.spalten);
   std::swap(arr, tmp.arr);
   return *this;
}

template<typename T>
inline int Array2d<T>::getZeilen() const { return zeilen; }

template<typename T>
inline int Array2d<T>::getSpalten() const { return spalten; }

template<typename T>
void Array2d<T>::init(const T& wert) { 
   for(int z=0; z < zeilen; ++z) {
      for(int s = 0; s < spalten; ++s) {
         arr[z][s] = wert;
      }
   }
}

template<typename T>
inline const T* Array2d<T>::operator[](int z) const { 
   return arr[z]; 
}

template<typename T>
inline T* Array2d<T>::operator[](int z) { 
   return arr[z]; 
}

template<typename T>
inline const T& Array2d<T>::at(int z, int s) const { 
   if(z < 0 || z >= zeilen) 
      throw std::range_error("Array2d: Zeile ausserhalb des erlaubten Bereichs");
   if(s < 0 || s >= spalten) 
      throw std::range_error("Array2d: Spalte ausserhalb des erlaubten Bereichs");
   return arr[z][s]; 
}

template<typename T>
inline T& Array2d<T>::at(int z, int s) { 
   if(z < 0 || z >= zeilen) 
      throw std::range_error("Array2d: Zeile ausserhalb des erlaubten Bereichs");
   if(s < 0 || s >= spalten) 
      throw std::range_error("Array2d: Spalte ausserhalb des erlaubten Bereichs");
   return arr[z][s]; 
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
