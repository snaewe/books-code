/* cppbuch/k15/tcpsocket/bidirectional/zeitserver2.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <ctime>
#include<iostream>
#include<string>
#include<boost/asio.hpp>
#include<cstring>
#include<cstdlib>
#include<locale>

using boost::asio::ip::tcp;
using namespace std;

const char* getZeitstring(const char* format) {
   const size_t MAX = 80;
   static char buf[MAX];
      time_t jetzt = time(NULL);
      tm *z = localtime(&jetzt);
      strftime(buf, MAX, format, z);
      return buf;
}

int main(int argc, char* argv[]) {
   if(argc != 2) {
      cout << "Gebrauch: " << argv[0]  << " <port>" << endl;
      return 1;
   }
   boost::asio::io_service ioService;
   unsigned short port = atoi(argv[1]);
   tcp::acceptor acceptor(ioService, tcp::endpoint(tcp::v4(), port));
   while(true) {      // Abbruch mit Strg+C
      tcp::socket socket(ioService);
      cout << "lauschen  an Port " << port 
           << " ... (Abbruch mit Strg+C)"  << endl;
      acceptor.accept(socket);
      char daten[1] = {0};
      // 1 Byte lesen
      socket.read_some(boost::asio::buffer(daten, 1));
      const char* format;
      switch(daten[0]) {
      case '1' :  locale::global(locale("en_US")); 
         format = "%c";
         break;
      case '2' :  locale::global(locale("de_DE")); 
         format = "%c";
         break;
      case '3' :  locale::global(locale("de_DE")); 
         format = "%A, den %d. %B %Y %T Uhr";
         break;
      case '4' : format = "%s";
         break;
      default:  format = "%c";
      }
      const char* zeitstring = getZeitstring(format);
      socket.write_some(boost::asio::buffer(zeitstring, strlen(zeitstring)+1));
   }
}
