/* cppbuch/k9/new/eigene/Speicherverwaltung.t
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef SPEICHERVERWALTUNG_T
#define SPEICHERVERWALTUNG_T
#include<new>                     // bad_alloc
#include<stdexcept>               // invalid_argument

template<typename T, int N>
class Speicherverwaltung {
public:
   static void* getMemory(size_t size) {
      if(ersterFreierPlatz >= N) {
         throw std::bad_alloc();
      }
      if(size != sizeof(T)) {
         throw std::invalid_argument("getMemory(): Aufruf fuer falschen Typ!");
      }
      belegt[ersterFreierPlatz] = &speicher[sizeof(T)*ersterFreierPlatz];
      return belegt[ersterFreierPlatz++];
   }

   static void freeMemory(void* ptr) {
      if(ptr) {                  // NULL-Zeiger ignorieren
         // Stelle suchen
         for(int i = ersterFreierPlatz-1; i >=0; --i) {
            if(belegt[i] == ptr) {  
               // 'freimachen' durch Kopieren des letzten Eintrags
               // an diese Stelle und Anpassen  von  ersterFreierPlatz
               belegt[i] = belegt[--ersterFreierPlatz];
               break;
            }
         }
      }
   }
   static int freiePlaetze() {
      return N - ersterFreierPlatz;
   }
private:
   static int ersterFreierPlatz;
   static void* belegt[N];
   static char speicher[sizeof(T)*N];
};

// Definitionen
template<typename T, int N> 
int Speicherverwaltung<T, N>::ersterFreierPlatz = 0;

template<typename T, int N> 
void* Speicherverwaltung<T, N>::belegt[N];

template<typename T, int N> 
char Speicherverwaltung<T, N>::speicher[sizeof(T)*N];

#endif
