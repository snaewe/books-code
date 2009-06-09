/* cppbuch/k34/Matrix.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef Matrix_DEFINED
#define Matrix_DEFINED Matrix_DEFINED
#include "valarray"

// Slice_iter and Matrix class from Stroustrup, C++ PL3, Sec. 22.4.5
template<class T>
class Slice_iter {
  public:
    Slice_iter(std::valarray<T>* vv, std::slice ss)
    :v(vv), s(ss) {}
    Slice_iter end() {
      Slice_iter t = *this;
      t.curr = s.start()+s.stride(); // (last+1) position
      return t;
    }
    Slice_iter& operator++() {++curr; return *this;}
    Slice_iter& operator++(int)  {
       Slice_iter t=*this;
       ++curr; 
       return t;
    }
    T& operator[](std::size_t i) { return ref(curr = i);} // C-style subscript
    T& operator()(std::size_t i) { return ref(curr = i);} // Fortran-style subscript
    T& operator*() { return ref(curr);} // current element
  private:
    std::valarray<T>* v;
    std::slice s;
    std::size_t curr; // index of current element
    T& ref(std::size_t i) const {return (*v)[s.start()+i*s.stride()];}
};

template<class T>
bool operator==(const Slice_iter<T>& p, const Slice_iter<T>& q) {
 return p.curr == q.curr && p.stride == q.stride && p.start == q.start;
}

template<class T>
bool operator!=(const Slice_iter<T>& p, const Slice_iter<T>& q) {
 return !(p == q);
}


template<class T>
bool operator<(const Slice_iter<T>& p, const Slice_iter<T>& q) {
 return p.curr < q.curr && p.stride == q.stride && p.start == q.start;
}

template<class T>
class Cslice_iter {
  public:
    Cslice_iter(std::valarray<T>* vv, std::slice ss)
    :v(vv), s(ss) {}
    Cslice_iter end() {
      Cslice_iter t = *this;
      t.curr = s.start()+s.stride(); // (last+1) position
      return t;
    }
    Cslice_iter& operator++() { ++curr; return *this;}
    Cslice_iter& operator++(int)  {
       Cslice_iter t=*this;
       ++curr; 
       return t;
    }
    const T& operator[](std::size_t i) { return ref(curr = i);} // C-style subscript
    const T& operator()(std::size_t i) { return ref(curr = i);} // Fortran-style subscript
    const T& operator*() { return ref(curr);} // current element
  private:
    std::valarray<T>* v;
    std::slice s;
    std::size_t curr; // index of current element
    T& ref(std::size_t i) const {return (*v)[s.start()+i*s.stride()];}
};

template<class T>
bool operator==(const Cslice_iter<T>& p, const Cslice_iter<T>& q) {
 return p.curr == q.curr && p.stride == q.stride && p.start == q.start;
}

template<class T>
bool operator!=(const Cslice_iter<T>& p, const Cslice_iter<T>& q) {
 return !(p == q);
}

template<class T>
bool operator<(const Cslice_iter<T>& p, const Cslice_iter<T>& q) {
 return p.curr < q.curr && p.stride == q.stride && p.start == q.start;
}


class Matrix {
  public:
    Matrix(std::size_t di1, std::size_t di2)
    : d1(di1), d2(di2), v(new std::valarray<double>(d1*d2)) {}
    Slice_iter<double> row(std::size_t i)  {
      return Slice_iter<double>(v,std::slice(i*d2,d2,1));
    }
    Cslice_iter<double> row(std::size_t i) const {
      return Cslice_iter<double>(v,std::slice(i*d2,d2,1));
    }

    Slice_iter<double> column(std::size_t i)  {
      return Slice_iter<double>(v,std::slice(i,d1,d2));
    }
    Cslice_iter<double> column(std::size_t i) const {
      return Cslice_iter<double>(v,std::slice(i,d1,d2));
    }

    // Fortran-style subscript
    double& operator()(std::size_t x, std::size_t y) {
      return (*v)[x*d2+y];
    }
    double operator()(std::size_t x, std::size_t y) const {
      return (*v)[x*d2+y];
    }
    // C-style subscript
    Slice_iter<double> operator[](std::size_t i) {return row(i);}
    Cslice_iter<double> operator[](std::size_t i) const {return row(i);}

    std::size_t size() const { return d1*d2;}
    std::size_t dim1() const { return d1;}
    std::size_t dim2() const { return d2;}
    Matrix& operator*=(double d) {
      (*v) *= d;
      return *this;
    }
  private:
    std::size_t d1, d2;
    std::valarray<double>* v;
};
#endif
