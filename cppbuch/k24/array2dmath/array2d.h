/* cppbuch/k24/array2dmath/array2d.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef ARRAY2D_H
#define ARRAY2D_H
// 2-dim. Array-Klasse mit zusammenhängendem (contiguous) Memory-Bereich
#if  __GNUC__*10+__GNUC_MINOR__ < 44
#error "Die Compilation dieses Programms setzt mindestens GNU C++ 4.4 voraus!"
#endif
#include<stdexcept>
#include<utility>
#include<algorithm>
#include<iostream>
#include<tuple>
using std::tuple;
using std::tuple_cat;
using std::get;
// ggf. in main.cpp einschalten
//#define TESTARRAY2D 

#ifdef TESTARRAY2D 
#define TESTAUSGABE(x) std::cout << #x << std::endl
#else
#define TESTAUSGABE(x) /* nichts */
#endif

template<typename T> class Array2d;

template<typename T>
struct Summand {
   Summand(const T& faktor, const Array2d<T>& arr) 
      : f(faktor), a(arr) {
   }
   Summand(const Array2d<T>& arr) 
      : f(T(1)), a(arr) {
   }
   T getWert(size_t index) const {
         return *(a.data()+index) * f; 
   }
   size_t getZeilen() const { 
      return a.getZeilen();
   }
   size_t getSpalten() const {
      return a.getSpalten();
   }
   Summand<T>& mult(const T& faktor) {
      f *= faktor;
      return *this;
   }
   T f;
   const Array2d<T>& a;
};

////////// Berechnung über alle Summanden
template<size_t N, typename T, typename... Args>
struct Summe {
   static T ergebnis(size_t index, const tuple<Args...>& t) {
       return get<N-1>(t).getWert(index)
             + Summe<N-1, T, Args...>::ergebnis(index, t);
   }
};
// partielle Spezialisierung zum Rekursionsabbruch
template<typename T, typename... Args>
struct Summe<1, T, Args...> {
   static T ergebnis(size_t index, const tuple<Args...>& t) {
      return get<0>(t).getWert(index);
   }
};

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

   // Konstruktoren
   Array2d(size_t z, size_t s)
      : zeilen(z), spalten (s), arr(new T[z*s]) {
   }
   Array2d(size_t z, size_t s, const T& wert)
      : zeilen(z), spalten (s), arr(new T[z*s]) {
      init(wert);
   }
   Array2d(size_t z, size_t s, const T* array)
      : zeilen(z), spalten (s), arr(new T[z*s]) {
      for(size_t i = 0; i < size(); ++i) {
         arr[i] = array[i];
      }   
   }
   Array2d(const Array2d& a) 
      : zeilen(a.zeilen), spalten (a.spalten), 
        arr(new T[zeilen*spalten]) {
      for(size_t i = 0; i < size(); ++i) {
         arr[i] = a.arr[i];
      }
      TESTAUSGABE(Array2d(const Array2d<T>& a));
   }
   Array2d(Array2d&& a)
      : zeilen(0), spalten(0), arr(0) {
      swap(a);
      TESTAUSGABE(Array2d(const Array2d<T>&& a) (move));
   }

   // Destruktor
   ~Array2d() {
      delete [] arr;
   }
   // Zuweisungsoperatoren
   Array2d& operator=(const Array2d& a) {
      checkDimension(a);
      for(size_t i = 0; i < size(); ++i) {
         arr[i] = a.arr[i];
      }
      TESTAUSGABE(operator=(const Array2d<T>& a));
      return *this;
   }
   Array2d& operator=(Array2d&& a) {
      swap(a);
      TESTAUSGABE(operator=(const Array2d<T>&& a) (move));
      return *this;
   }
   // Elementzugriff
   void checkIndizes(int z, int s) const {
      if(z < 0 || z >= (int)zeilen) 
         throw std::range_error("Array2d: Zeile ausserhalb des erlaubten Bereichs");
      if(s < 0 || s >= (int)spalten) 
         throw std::range_error("Array2d: Spalte ausserhalb des erlaubten Bereichs");
   }
   const T& at(int z, int s) const { 
      checkIndizes(z, s);
      return arr[z*spalten + s]; 
   }
   T& at(int z, int s) { 
      checkIndizes(z, s);
      return arr[z*spalten + s]; 
   }
   const T* operator[](int z) const { return &arr[z*spalten]; }
   T* operator[](int z) { return &arr[z*spalten]; }
   const T* data() const {  return arr; }

   // weitere Methoden
   size_t getZeilen() const { return zeilen; }
   size_t getSpalten() const { return spalten; }
   void init(const T& wert) {  // Alle Elemente mit wert initialisieren
      for(size_t i = 0; i < size(); ++i) {
         arr[i] = wert;
      }
   }

   void print(std::ostream& ausgabe = std::cout) const {
      for(size_t z=0; z < getZeilen(); ++z) {
         for(size_t s=0; s < getSpalten(); ++s) {
            ausgabe << (*this)[z][s] << " ";
         }
         ausgabe << std::endl;
      }
   }
   // STL-entsprechende Funktionen
   size_t size() const  { return zeilen*spalten;}
   iterator begin() { return arr;}
   iterator end() { return arr + size();}
   const_iterator begin() const { return arr;}
   const_iterator end() const { return arr + size();}
   const_iterator cbegin() const { return arr;}
   const_iterator cend() const { return arr + size();}
   void swap(Array2d& a) {
      size_t tmpzeilen = zeilen;
      size_t tmpspalten = spalten;
      T* tmparr = arr;
      zeilen = a.zeilen;
      spalten = a.spalten;
      arr = a.arr;
      a.zeilen = tmpzeilen;
      a.spalten = tmpspalten;
      a.arr = tmparr;
   }

   // mathematische Operatoren + Zubehör
   void checkDimension(const Array2d& a) const {
      if(zeilen != a.zeilen || spalten != a.spalten) 
         throw std::range_error("Array2d: ungleiche Zeilen-/Spaltenanzahl");
   }

  /////////  mathematische Operatoren und zugehörige Methoden ///////////

   //////////    unäres plus/minus  //////////////
   Array2d& operator+() { return *this;}
   Summand<T> operator-() { 
      TESTAUSGABE(operator-());
      return Summand<T>(T(-1), *this);
   }   
   //////////    binäre Kurzform-Operatoren  //////////////
   Array2d& operator*=(const Array2d& a) {
      TESTAUSGABE(operator*=(const Array2d<T>& a));
      checkDimension(a);
      // *this ist selbst Argument, temporärer Zwischenspeicher notwendig
      Array2d<T> tmp(*this); 
      matMult(*this, tmp, a);
      return *this;
   }

   Array2d& operator*=(T wert) {
      TESTAUSGABE(operator*=(T wert));
      for(size_t i = 0; i < size(); ++i) {
         arr[i] *= wert;
      }
      return *this;
   }

   //////////     +=   //////////////
   Array2d& operator+=(const Summand<T>& o) {
      TESTAUSGABE(operator+=(const Summand<T>& o));
      checkDimension(o.a);
      for(size_t i = 0; i < size(); ++i) {
         arr[i] += o.getWert(i);
      }
      return *this;
   }

   Array2d& operator+=(const Array2d& a) {
      TESTAUSGABE(operator+=(const Array2d<T>& a));
      return  operator*=(Summand<T>(a));
   }

   //////////     -=   //////////////
   Array2d& operator-=(const Summand<T>& o) {
      TESTAUSGABE(operator-=(const Summand<T>& a));
      checkDimension(o.a);
      for(size_t i = 0; i < size(); ++i) {
         arr[i] -= o.getWert(i);
      }
      return *this;
   }
   Array2d& operator-=(const Array2d& a) {
      TESTAUSGABE(operator-=(const Array2d<T>& a));
      return  operator*=(Summand<T>(-1, a));
   }

   //////////    Zuweisungsoperatoren für Hilfsklassen  //////////////
   template<typename... Args>
   Array2d& operator=(const tuple<Args...>& t) {
      TESTAUSGABE(operator=(tuple));
         for(size_t i = 0; i < size(); ++i) {
            arr[i] =  Summe<sizeof...(Args), T, Args...>::ergebnis(i, t);
         }
      return *this;
   }

   template<typename... Args>
   Array2d& operator+=(const tuple<Args...>& t) {
      TESTAUSGABE(operator+=(tuple));
         for(size_t i = 0; i < size(); ++i) {
            arr[i] +=  Summe<sizeof...(Args), T, Args...>::ergebnis(i, t);
         }
      return *this;
   }
   template<typename... Args>
   Array2d& operator-=(const tuple<Args...>& t) {
      TESTAUSGABE(operator+=(tuple));
         for(size_t i = 0; i < size(); ++i) {
            arr[i] -=  Summe<sizeof...(Args), T, Args...>::ergebnis(i, t);
         }
      return *this;
   }


   //////////    Konstruktor für Hilfsklasse  //////////////
   template<typename... Args>
   Array2d(const tuple<Args...>& t) 
      : zeilen(0), spalten(0), arr(0) {
      TESTAUSGABE(Array2d(tuple));
         Array2d temp(get<0>(t).getZeilen(), get<0>(t).getSpalten());
      for(size_t i = 0; i < temp.size(); ++i) {
         temp.arr[i] =  Summe<sizeof...(Args), T, Args...>::ergebnis(i, t);
      }
      swap(temp);
   }

   Array2d(const Summand<T>& op) 
      : zeilen(op.getZeilen()), spalten (op.getSpalten()), 
        arr(new T[zeilen*spalten]) {
      TESTAUSGABE(Array2d(const Summand&));
         for(size_t i = 0; i < size(); ++i) {
            arr[i] =  op.getWert(i);
         }
   }

 private:
   size_t zeilen;
   size_t spalten;
   T* arr;
};


/////////  globale Funktionen ///////////
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
using namespace std::rel_ops;

/////////  globale mathematische Operatoren ///////////

//////////    mult  //////////////
namespace {
   template<typename T>  // Hilfsfunktion
   void matMult(Array2d<T>& erg, const Array2d<T>& x, const Array2d<T>& y) {
      if(x.getSpalten() != y.getZeilen()) {
         throw std::range_error("Array2d-Multiplikation:: falsche Zeilen-/Spaltenanzahl");
      }
      std::fill(erg.begin(), erg.end(), T(0));  // erg = 0 setzen
      for(size_t i = 0; i < erg.getZeilen(); ++i) {
         for(size_t j = 0; j < erg.getSpalten(); ++j) {
            for(size_t k = 0; k < x.getSpalten(); ++k) {
               erg[i][j] +=  x[i][k] * y[k][j];
            }
         }
      }
   }
}

template<typename T>
inline Array2d<T> operator*(const Array2d<T>& x, const Array2d<T>& y) {
   TESTAUSGABE(operator*(const Array2d<T>&, const Array2d<T>&));
  // temporärer Zwischenspeicher notwendig, weil das Ergebnis einem Objekt 
   // zugewiesen wird, das selbst an den Berechnungen beteiligt sein kann
   Array2d<T> tmp(x.getZeilen(), y.getSpalten()); 
   matMult(tmp, x, y);
   return tmp;
}

template<typename T>
inline Summand<T> operator*(const T& f, const Array2d<T>& x) {
   TESTAUSGABE(operator*(T, const Array2d<T>&));
   return Summand<T>(f, x);
}

template<typename T>
inline Summand<T> operator*( const Array2d<T>& x, const T& f) {
   TESTAUSGABE(operator*(const Array2d<T>&, T));
   return Summand<T>(f, x);
}

template<typename T>
inline Summand<T> operator*(Summand<T>&& x, const T& f) {
   TESTAUSGABE(operator*(const Summand<T>&, T));
      return x.mult(f);
}
template<typename T>
inline Summand<T>& operator*(const T& f, Summand<T>& x) {
   TESTAUSGABE(operator*(T, const Summand<T>&));
   return x.mult(f);
}



//////////    plus  //////////////
template<typename T>
tuple<Summand<T>, Summand<T>> 
inline operator+(const Summand<T>& x, const Summand<T>& y) {
   x.a.checkDimension(y.a);
   TESTAUSGABE(operator+(const Summand<T>&, const Summand<T>&));
   return tuple<Summand<T>, Summand<T>>(x, y);
}
template<typename T>
tuple<Summand<T>, Summand<T>> 
inline operator+(const Summand<T>& x, const Array2d<T>& y) {
   TESTAUSGABE(operator+(const Summand<T>&, const Array2d<T>&));
   return tuple<Summand<T>, Summand<T>>(x, Summand<T>(y));
}
template<typename T>
tuple<Summand<T>, Summand<T>> 
inline operator+(const Array2d<T>& x, const Summand<T>& y) {
   TESTAUSGABE(operator+(const Summand<T>&, const Array2d<T>&));
   return tuple<Summand<T>, Summand<T>>(Summand<T>(x), y);
}
template<typename T>
tuple<Summand<T>, Summand<T>> 
inline operator+(const Array2d<T>& x, const Array2d<T>& y) {
   TESTAUSGABE(operator+(const Array2d<T>&, const Array2d<T>&));
   return tuple<Summand<T>, Summand<T>>(Summand<T>(x), Summand<T>(y));
}

template<typename T, typename... Args>
tuple<Summand<T>, Args...>
inline operator+(const tuple<Args...>& t, const Summand<T>& y) {
   TESTAUSGABE(operator+(const tupel<Args...>& t, const Summand<T>&));
   return tuple_cat(tuple<Summand<T>>(y), t);
}

template<typename T, typename... Args>
tuple<Summand<T>, Args...>
inline operator+(const Summand<T>& y, const tuple<Args...>& t) {
   TESTAUSGABE(operator+( const Summand<T>&, const tupel<Args...>& t));
   return tuple_cat(tuple<Summand<T>>(y), t);
}

template<typename T, typename... Args>
tuple<Summand<T>, Args...>
inline operator+(const tuple<Args...>& t, const Array2d<T>& y) {
   TESTAUSGABE(operator+(const tupel<Args...>& t, const Array2d<T>&));
   return t + Summand<T>(y);
}


//////////    minus  /////////////
template<typename T>
tuple<Summand<T>, Summand<T>> 
inline operator-(const Summand<T>& x, const Summand<T>& y) {
   x.a.checkDimension(y.a);
   TESTAUSGABE(operator-(const Summand<T>&, const Summand<T>&));
   return tuple<Summand<T>, Summand<T>>(x, y);
}
template<typename T>
tuple<Summand<T>, Summand<T>> 
inline operator-(const Summand<T>& x, const Array2d<T>& y) {
   TESTAUSGABE(operator-(const Summand<T>&, const Array2d<T>&));
   return tuple<Summand<T>, Summand<T>>(x, Summand<T>(-1, y));
}
template<typename T>
tuple<Summand<T>, Summand<T>> 
inline operator-(const Array2d<T>& x, const Summand<T>& y) {
   TESTAUSGABE(operator-(const Summand<T>&, const Array2d<T>&));
   return tuple<Summand<T>, Summand<T>>(Summand<T>(x), y);
}
template<typename T>
tuple<Summand<T>, Summand<T>> 
inline operator-(const Array2d<T>& x, const Array2d<T>& y) {
   TESTAUSGABE(operator-(const Array2d<T>&, const Array2d<T>&));
   return tuple<Summand<T>, Summand<T>>(Summand<T>(x), Summand<T>(-1, y));
}

template<typename T, typename... Args>
tuple<Summand<T>, Args...>
inline operator-(const tuple<Args...>& t, Summand<T>&& y) {
   TESTAUSGABE(operator-(const tupel<Args...>& t, const Summand<T>&));
   y.mult(-1);
   return tuple_cat(tuple<Summand<T>>(y), t);
}


template<typename T, typename... Args>
tuple<Summand<T>, Args...>
inline operator-(const tuple<Args...>& t, const Array2d<T>& a) {
   TESTAUSGABE(operator-(const tupel<Args...>& t, const Array2d<T>&));
   return t + Summand<T>(-1, a);
}

#endif
