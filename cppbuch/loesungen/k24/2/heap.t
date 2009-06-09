/* cppbuch/loesungen/k24/2/heap.t
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef HEAP_T
#define HEAP_T
#include<algorithm>
#include<vector>
#include<utility>
using std::vector;

template<class T, class Compare = std::less<T> >
class Heap {
 public:
   Heap(const Compare& cmp = Compare())
      : anz(0), comp(cmp), v(vector<T>(1)) {
       last = v.begin();
   }
   void push(const T& t) {
      if(anz == v.size()) {
         v.resize(anz+100);
         last = v.begin() + anz; // neu bestimmen
      }
      *last = t;
      push_heap(v.begin(), ++last, comp);
      ++anz;
   }
   void pop() {
      pop_heap(v.begin(), last--, comp);
      --anz;
   }
   const T& top() const {
      return *v.begin();
   }
   bool empty() const {
      return anz == 0;
   }
   size_t size() const {
      return anz;
   }
   vector<T> toSortedVector() const {
      vector<T> temp(anz);
      for(size_t i = 0; i < anz; ++i) {
         temp[i] = v[i];
      }
      sort_heap(temp.begin(), temp.end(), comp);
      return temp;
   }
 private:
   size_t anz;
   Compare comp;
   vector<T> v;
   typename vector<T>::iterator last;
};
#endif
