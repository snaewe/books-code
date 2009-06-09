/* cppbuch/k15/udpsocket/ntp.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<boost/asio.hpp>
#include<cassert>
#include<ctime>
using boost::asio::ip::udp;

int main() {
   boost::asio::io_service ioService;
   udp::socket socket(ioService);
   assert(sizeof(size_t) == 4);
   size_t buf[12] = {0};
   const size_t BUFSIZE = sizeof(buf);
   buf[0] = htonl ( ( 3 << 27) | (3 << 24));    // s. RFC 4330
   // http://www.apps.ietf.org/rfc/rfc4330.html
   udp::resolver resolver(ioService);
   //udp::resolver::query query(udp::v4(), "ptbtime2.ptb.de", "123"); 
   udp::resolver::query query(udp::v4(), "europe.pool.ntp.org", "123"); 
   udp::endpoint zeitserver = *resolver.resolve(query);
   socket.open(boost::asio::ip::udp::v4());
   socket.send_to(boost::asio::buffer(buf, BUFSIZE),  zeitserver);

   boost::asio::ip::udp::endpoint hier;
   socket.receive_from(boost::asio::buffer(buf, BUFSIZE),  hier);
   time_t secs = ntohl(buf[8])- 2208988800u;
   tm *z = localtime(&secs);
   double secfrac = (double)ntohl(buf[9])/4294967296.0;
   std:: cout << z->tm_mday << '.' << z->tm_mon + 1 << '.'
              << z->tm_year + 1900 << "   "
              << z->tm_hour << ':' << z->tm_min << ':'
              << secfrac + z->tm_sec << std::endl;
}
