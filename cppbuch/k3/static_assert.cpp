/* cppbuch/k3/static_assert.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/

int main() {
   static_assert(sizeof(long) > sizeof(int),
           "long hat nicht mehr Bits als int!");
}
