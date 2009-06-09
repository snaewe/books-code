/* cppbuch/k28/list/identify/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iterator>
#include<fstream>
#include<list>
#include"identif.h"

int main( ) {
    // define and open input file
    std::ifstream Source("main.cpp");

    std::list<Identifier> Identifier_list;

    std::istream_iterator<Identifier> iPos(Source), end;

    if(iPos == end)
       std::cout << "File not found!" << std::endl;
    else
       while(iPos != end)
          // insert identifier and read next one
          Identifier_list.push_back(*iPos++);

    // output
    std::list<Identifier>::const_iterator I = Identifier_list.begin();
    while(I != Identifier_list.end())
         std::cout << *I++ << std::endl;
}
