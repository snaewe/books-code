/* cppbuch/k7/privat/warteschlange.t
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef WARTESCHLANGE_T
#define WARTESCHLANGE_T
#include<list>

template<typename T>
class Warteschlange
  : private std::list<T> { // mit privater Vererbung 
                             // (Implementationsvererbung)
    public:
      using std::list<T>::empty;
      using std::list<T>::size;
      // am Ende einfügen:
      void push(const T& x)  { std::list<T>::push_back(x);}
      // am Anfang entnehmen:
      void pop()             { std::list<T>::pop_front();}
      // am Anfang bzw. Ende lesen
      using std::list<T>::front;
      using std::list<T>::back;
};
#endif
