/* cppbuch/k15/http/server/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<cstdlib>
#include"Server.h"

int main(int argc, char* argv[]) {
   if(argc != 2) {
      std::cout << "Gebrauch: " << argv[0]  << " <port>" << std::endl;
      return 1;
   }
   unsigned short port = atoi(argv[1]);
   Server server(port, "web");
   server.run();
}
