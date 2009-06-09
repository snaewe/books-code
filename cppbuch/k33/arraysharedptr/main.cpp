/* cppbuch/k33/arraysharedptr/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<memory>
using namespace std;

template<typename T>
struct ArrayDeleter {
   void operator()(T* ptr) {
      delete [] ptr;
      std::cout << "Array deleted" << std::endl;
   }
};

int main() {
   shared_ptr<int> p(new int[10], ArrayDeleter<int>());
}
