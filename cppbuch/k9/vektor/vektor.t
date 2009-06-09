/* cppbuch/k9/vektor/vektor.t
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// dynamische Vektor-Klasse
#ifndef VEKTOR_T
#define VEKTOR_T
#include<stdexcept>

template<typename T>
class Vektor {
  public:
    Vektor(size_t x = 0);                 // Allg. Konstruktor 1
    Vektor(size_t n, T t);                // Allg. Konstruktor 2: 
                                             // n Elemente mit Wert t
    Vektor(const Vektor<T>& v);           // Kopierkonstruktor
    virtual ~Vektor() { delete [] start;} // Destruktor

    size_t size() const {return xDim;}

    void groesseAendern(size_t);          // dynamisch ändern

    // Indexoperator inline
    T& operator[](int index) {
         if( index < 0  ||  index >= (int)xDim) {
            throw std::out_of_range("Indexüberschreitung!");
         }
         return start[index];
    }

    // Indexoperator für nicht-veränderliche Vektoren
    const T& operator[](int index) const {
         if( index < 0  ||  index >= (int)xDim) {
            throw std::out_of_range("Indexüberschreitung!");
         }
         return start[index];
    }

     // Zuweisungsoperator
    Vektor<T>& operator=(const Vektor<T>&);

    // Zeiger auf Anfang und Position nach dem Ende für Vektoren
    // mit nichtkonstanten und konstanten Elementen
    T* begin() { return start;}
    T* end()   { return start + xDim;}
    const T* begin() const { return start;}
    const T* end()   const { return start + xDim;}
  private:
    size_t  xDim;                      // Anzahl der Datenobjekte
    T   *start;                        // Zeiger auf Datenobjekte
};

/********** Implementierung ****************/

template<typename T>
inline Vektor<T>::Vektor(size_t x)             //  Allg. Konstruktor 1
: xDim(x), start(new T[x]) {
}

template<typename T>
Vektor<T>::Vektor(size_t n, T wert)     //  Allg. Konstruktor 2
: xDim(n), start(new T[n]) {
     for (size_t i = 0; i < xDim; ++i) {
         start[i] = wert;
     }
}

template<typename T>
Vektor<T>::Vektor(const Vektor<T> &v)   // Kopierkonstruktor
    : xDim(v.xDim), start(new T[xDim]) {
    for (size_t i = 0; i < xDim; ++i) {
        start[i] = v.start[i];
    }
}

template<typename T>
Vektor<T> &Vektor<T>::operator=(const Vektor<T> &v) {
    T * temp = new T[v.xDim];   // neuen Platz beschaffen
    for (size_t i = 0; i < v.xDim; ++i) {
        temp[i] = v.start[i];
    }
    delete[] start;        // Speicherplatz freigeben
    xDim  = v.xDim;
    start = temp;
    return *this;
}

template<typename T>
void Vektor<T>::groesseAendern(size_t neueGroesse) {
    // neuen Speicherplatz besorgen
    T *pTemp = new T[neueGroesse];

    // die richtige Anzahl von Elementen kopieren
    size_t kleinereZahl =
               neueGroesse > xDim ? xDim : neueGroesse;
    for (size_t i = 0; i < kleinereZahl; ++i) {
        pTemp[i] = start[i];
    }
    // alten Speicherplatz freigeben
    delete [] start;

    // Verwaltungsdaten aktualisieren
    start = pTemp;
    xDim  = neueGroesse;
}
#endif // VEKTOR_T

