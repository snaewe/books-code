/* cppbuch/k7/privat/warteschlangeD.t
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef WARTESCHLANGED_T
#define WARTESCHLANGED_T
#include<list>

template<typename T>
class Warteschlange {  // wie warteschlange.t, aber Delegation statt privater Vererbung
 public:
   bool empty( ) { return liste.empty(); }
   size_t size() { return liste.size(); }
   // am Ende einfügen:
   void push(const T& x)  { liste.push_back(x);}
   // am Anfang entnehmen:
   void pop()             { liste.pop_front();}
   // am Anfang bzw. Ende lesen
   const T& front() { return liste.front();}
   const T& back()  { return liste.back();}
 private:
   std::list<T> liste;
};
#endif
