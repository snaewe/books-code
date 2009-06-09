/* cppbuch/k15/tcpsocket/zeit/zeitclient.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include <iostream>
#include<cstdlib>
#include <boost/asio.hpp>
using namespace std;

int main(int argc, char* argv[]) {
   if(argc != 3) {
      cout << "Gebrauch: " << argv[0]  << " <IP-Adresse> <port>" << endl;
      return 1;
   }
   boost::asio::io_service ioService;
   unsigned short port = atoi(argv[2]);
   boost::asio::ip::tcp::endpoint 
      server(boost::asio::ip::address::from_string(argv[1]), port);
   boost::asio::ip::tcp::socket socket(ioService);
   socket.connect(server);
   cout << "Lokaler Endpunkt:  " << socket.local_endpoint()  << endl;
   cout << "Verbindung mit " << socket.remote_endpoint() 
        << " hergestellt." << endl;
   const size_t SZ = 80;
   char buf[SZ+1];
   // Es werden maximal SZ Bytes gelesen:
   size_t  anzahlBytes = socket.read_some(boost::asio::buffer(buf, SZ));
   buf[anzahlBytes] = '\0'; // Rest für Ausgabe ignorieren
   cout << buf << endl;
}
