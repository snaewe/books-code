/* cppbuch/k9/smartptr/smartptr.t
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef SMARTPTR_T
#define SMARTPTR_T
#include"NullPointerException.h"

template<typename T>
class SmartPointer {
   public:
      SmartPointer(T *p=0);
      ~SmartPointer();   // nicht virtual: Vererbung ist nicht geplant
      T* operator->() const;
      T& operator*() const;
      operator bool() const;
   private:                           
      T* zeigerAufObjekt;
      void check() const; // Prüfung auf nicht-Null
   // Ergänzung siehe Text
     // {\tt p1 = p2;}  verbieten
    void operator=(const SmartPointer& );
    // Initialisierung mit {\tt SmartPointer} verbieten
    SmartPointer(const SmartPointer&);
};

template<typename T>
inline void SmartPointer<T>::check() const {
   if(!zeigerAufObjekt) {
     throw NullPointerException();
   }
}

template<typename T>
inline SmartPointer<T>::SmartPointer(T *p)
: zeigerAufObjekt(p) {
}

template<typename T>
inline SmartPointer<T>::~SmartPointer() {
    delete zeigerAufObjekt;
}

template<typename T>
inline T* SmartPointer<T>::operator->() const {
    check();
    return zeigerAufObjekt;
}

template<typename T>
inline T& SmartPointer<T>::operator*() const {
    check();
    return *zeigerAufObjekt;
}

template<typename T>
inline SmartPointer<T>::operator bool() const {
   return bool(zeigerAufObjekt);
}

#endif    // SMARTPTR_T
