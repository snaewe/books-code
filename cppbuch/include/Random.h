/* cppbuch/include/Random.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef RANDOM_H
#define RANDOM_H
#include<cstdlib> 

class Random {
 public:
   Random(size_t g = 100) 
      : grenze(g) {
   }
   void setSeed(size_t seed) {
      srand(seed);
   }
   // gibt eine size_t-Pseudo-Zufallszahl zwischen 0 und range-1 zurück
   size_t operator()(size_t range)  {
        return (size_t)((double)rand()*range/(RAND_MAX+1.0));
   }
   // gibt eine size_t-Pseudo-Zufallszahl zwischen 0 und grenze-1 zurück
   size_t operator()()  {
        return (size_t)((double)rand()*grenze/(RAND_MAX+1.0));
   }
 private:
   size_t grenze;
};

#endif
