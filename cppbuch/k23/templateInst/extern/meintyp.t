/* cppbuch/k23/templateInst/extern/meintyp.t
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef MEINTYP_T
#define MEINTYP_T
#include<vector>

template<typename T>
class MeinTyp {
   public:
     MeinTyp(T par) 
     : attribut(par) {
     } 
     T get() {
        std::vector<T> v; 
        v.push_back(T());  // vector benutzen
        return attribut; 
     }

   private:
     T attribut;
};
#endif
