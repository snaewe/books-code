/* cppbuch/k15/tcpsocket/zeit/zeitserver.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<ctime>
#include<iostream>
#include<boost/asio.hpp>
#include<cstring>
#include<cstdlib>
using boost::asio::ip::tcp;
using namespace std;

int main(int argc, char* argv[]) {
   if(argc != 2) {
      cout << "Gebrauch: " << argv[0]  << " <port>" << endl;
      return 1;
   }
   boost::asio::io_service ioService;
   unsigned short port = atoi(argv[1]);
   tcp::acceptor acceptor(ioService, tcp::endpoint(tcp::v4(), port));
   while(true) {        //    Abbruch mit Strg+C
      tcp::socket socket(ioService);
      cout << "lauschen  an Port " << port 
           << " ... (Abbruch mit Strg+C)"  << endl;
      acceptor.accept(socket);
      cout << "Lokaler Endpunkt:  " << socket.local_endpoint() << endl;
      cout << "Verbindung mit " << socket.remote_endpoint() 
           << " hergestellt." << endl;
      time_t jetzt = time(NULL);
      const char* zeitstring = ctime(&jetzt);
      socket.write_some(boost::asio::buffer(zeitstring, strlen(zeitstring)+1));
   }
}
