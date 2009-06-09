/* cppbuch/k9/matrix/matmain.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// Beispiele für
// - dreidimensionale Matrix
// - Multiplikation zweier 2-dimensionalen Matrizen
using namespace std;

#define PRINT(X) cout << (#X) << " = " << (X) << endl
#include"matrix.t"

int main() {
    Matrix<float> a(3,4);
    Matrix<float> b(4,5);
    Matrix<float> c;
    MathVektor<float> mV(5);
    Matrix3D<float> matrix3D(2,4,5);
    matrix3D.I();
    mV.init(99.0);
    
    a.init(1.0);
    for (size_t i = 0; i < b.zeilen(); ++i)
    for (size_t j = 0; j < b.spalten(); ++j)
    b[i][j] = i+j;
    
    c = a * b;
    
    PRINT(a);
    PRINT(b);
    PRINT(c);
    cin.get();
    
    cout <<"a.I(); :" << endl;
    a.I();
    PRINT(a);
    PRINT(b);
    PRINT(a*b);
    cin.get();
    
    a *= b;
    cout << "a *= b;\n";
    PRINT(a);
    PRINT(b);
    
    cout << "Zuweisung eines Vektors:\n";
    PRINT(mV);
    b[1] = mV;
    cout << "b[1] = mV:" << endl;
    PRINT(b);
    cin.get();
    
    cout << "Zuweisung einer Submatrix:\n";
    for (size_t i = 0; i < matrix3D.xDIM(); ++i) {
       PRINT(i);
       PRINT(matrix3D[i]);
    }
    cin.get();

    cout << "matrix3D[1] = b;:" << endl;
    matrix3D[1] = b;
    for (size_t i = 0; i < matrix3D.xDIM(); ++i) {
       PRINT(i);
       PRINT(matrix3D[i]);
    }
    mV.init(33.0);
    cout << "matrix3D[0][1] = mV; (init(33)):" << endl;
    matrix3D[0][1] = mV;
    for (size_t i = 0; i < matrix3D.xDIM(); ++i) {
       PRINT(i);
       PRINT(matrix3D[i]);
    }
    matrix3D.init(100);
    cout << "matrix3D.init(100)):" << endl;
    for (size_t i = 0; i < matrix3D.xDIM(); ++i) {
       PRINT(i);
       PRINT(matrix3D[i]);
    }
    matrix3D.I();
    cout << "matrix3D.I()):" << endl;
    for (size_t i = 0; i < matrix3D.xDIM(); ++i) {
       PRINT(i);
       PRINT(matrix3D[i]);
    }
}

