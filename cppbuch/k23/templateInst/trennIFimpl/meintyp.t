/* cppbuch/k23/templateInst/trennIFimpl/meintyp.t
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef MEINTYP_T
#define MEINTYP_T

template<typename T>
class MeinTyp {
   public:
     MeinTyp(T par); 
     T get();
   private:
     T attribut;
};
#endif
