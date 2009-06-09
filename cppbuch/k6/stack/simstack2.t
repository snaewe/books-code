/* cppbuch/k6/stack/simstack2.t
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// ein einfaches Stack-Template (benutzt in simmain2.cc)
#ifndef SIMSTACK2_T
#define SIMSTACK2_T 
#include<cassert>

template<typename T, unsigned int maxSize>
class SimpleStack {
  public:
    SimpleStack() : anzahl(0){}
    bool empty() const { return anzahl == 0;}
    bool full() const { return anzahl == maxSize;}
    unsigned int size() const { return anzahl;}
    void clear() { anzahl=0;}          // Stack leeren

    const T& top() const;              // letztes Element sehen
    void pop();                        // Element entnehmen
    // Vorbedingung für top und pop: Stack ist nicht leer

    void push(const T &x);             // x auf den Stack legen
    // Vorbedingung für push: Stack ist nicht voll

   private:
    unsigned int anzahl;
    T array[maxSize];           // Behälter für Elemente
};

// noch fehlende Methoden-Implementierungen

template<typename T, unsigned int m>
const T& SimpleStack<T, m>::top() const {
    assert(!empty());
    return array[anzahl-1];
}

template<typename T, unsigned int m>
void SimpleStack<T, m>::pop() {
    assert(!empty());
    --anzahl;
}

template<typename T, unsigned int m>
void SimpleStack<T, m>::push(const T &x) {
    assert(!full());
    array[anzahl++] = x;
}
#endif     // SIMSTACK2_T
