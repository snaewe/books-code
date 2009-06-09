/* cppbuch/k9/matrix/matrix.t
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef MATRIX_T
#define MATRIX_T

#include"../mathvek/mvektor.t"

/* Matrix als Vektor von MathVektoren */

template<typename T>
class Matrix : public Vektor<MathVektor<T> > {
  protected:
    size_t yDim;
  public:
    typedef Vektor<MathVektor<T> > super;  // Oberklassentyp
    Matrix(size_t=0, size_t = 0);         // Zeilen, Spalten
    size_t zeilen()  const {return super::size();}
    size_t spalten() const {return yDim; }
    void init(const T&);

    // mathematische Operatoren und Funktionen
    Matrix<T>& I();   // Einheitsmatrix erzeugen
    Matrix<T>& operator*=(const T&);
    Matrix<T>& operator*=(const Matrix<T>&);
    // ... weitere  Operatoren und Funktionen
};

/* 3D-Matrix als Vektor von 2D-Matrizen*/
template<typename T>
class Matrix3D : public Vektor<Matrix<T> > {
  private:
    size_t yDim, zDim;
  public:
    typedef Vektor<Matrix<T> > super;  // Oberklassentyp
    Matrix3D(size_t = 0, size_t = 0, size_t = 0);
    size_t xDIM() const { return super::size();}  // geerbt
    size_t yDIM() const { return yDim;}
    size_t zDIM() const { return zDim;}
    void init(const T&);               // Initialisierung
    Matrix3D<T>& I();                  // Einheitsmatrix
    // mathematische Operatoren
    Matrix3D<T>& operator*=(const T&); // Multiplikation
    // weitere Operatoren und Funktionen ...
};

/* ============= Implementierung =========================*/

// 2D Matrix

template<typename T>
Matrix<T>::Matrix(size_t x, size_t y)
: Vektor<MathVektor<T> >(x), yDim(y) {
    MathVektor<T> temp(y);
    for(size_t i = 0; i < x; ++i) {
      super::operator[](i) = temp;
    }
}

template<typename T>
void Matrix<T>::init(const T& wert) {
    for(size_t i = 0; i < super::size(); ++i) {
       super::operator[](i).init(wert);
       // {\tt operator[](i)} ist vom Typ {\tt <MathVektor<T>}
    }
}

template<typename T>
Matrix<T>& Matrix<T>::I() {
    // keine Prüfung, ob  size() == yDim
    for(size_t i = 0; i< super::size(); ++i) {
       for(size_t j = 0; j < yDim ; ++j) {
          super::operator[](i)[j] = (i == j) ? T(1) : T(0);
       }
    }
    return *this;
}

template<typename T>                   // Multiplikationsoperator
Matrix<T>& Matrix<T>::operator*=(const T& faktor) {
    for(size_t i = 0; i < super::size(); ++i) {
      super::operator[](i) *= faktor;  // MathVektor::operator*=()
    }
    return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& b) {
    if(spalten() != b.zeilen()) 
         throw "Falsche Dimension in Matrix*= !";

    Matrix<T> erg(zeilen(), b.spalten());
    for(size_t i = 0; i < zeilen(); ++i) {
       for(size_t j=0; j < b.spalten(); ++j) {
          erg[i][j]= T(0);
          for(size_t k=0; k < spalten(); ++k)
             erg[i][j] += super::operator[](i)[k] * b[k][j];
       }
    }
    //*this = erg;  // nicht effizient. Siehe Diskussion in Teil 4, Abschnitt "Performanceproblem Wertsemantik"
    return *this;
}

template<typename T>
Matrix<T> operator*(const Matrix<T>& a, const Matrix<T>& b) {
    Matrix<T> erg = a;
    return erg *= b;// nicht effizient, siehe *=
}

template<typename T>
ostream& operator<<(ostream& s, const Matrix<T>& m ) {
    for(size_t i = 0; i < m.zeilen(); ++i) {
       s << endl << i <<" :  ";
       for(size_t j = 0; j < m.spalten(); ++j) {
          s << m[i][j] <<" ";
       }
    }
    s <<endl;
    return s;
}


// Matrix3D

template<typename T>
Matrix3D<T>::Matrix3D(size_t x, size_t y, size_t z)
: Vektor<Matrix<T> >(x), yDim(y), zDim(z) {
    Matrix<T> temp(y, z);
    for(size_t i = 0; i < x; ++i) {
       super::operator[](i) = temp;
    }
}

template<typename T>
void Matrix3D<T>::init(const T& wert) {
    for(size_t i = 0; i < super::size(); ++i)  {
       super::operator[](i).init(wert);
       // operator[](i) ist vom Typ Matrix<T>
    }
}

/***********
template<typename T>
Matrix3D<T>& Matrix3D<T>::I() {
    // keine Prüfung auf gleiche Dimensionen
    for(size_t i = 0; i < super::size(); ++i)
       for(size_t j = 0; j < yDim ; ++j)
          for(size_t k = 0; k < zDim ; ++k)
            super::operator[](i)[j][k] = (i==j && j==k) ? T(1) : T(0);
    return *this;
}
*******************/

template<typename T>
Matrix3D<T>& Matrix3D<T>::I() {
    // keine Prüfung auf gleiche Dimensionen
    for(size_t i = 0; i < super::size(); ++i) {
       super::operator[](i).I();
    }
    return *this;
}

template<typename T>
Matrix3D<T>& Matrix3D<T>::operator*=(const T& faktor) {
    for(size_t i = 0; i < super::size(); ++i) {
      super::operator[](i) *= faktor;  // Matrix::operator*=()
    }
    return *this;
}
#endif   
