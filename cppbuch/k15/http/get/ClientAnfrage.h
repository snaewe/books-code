/* cppbuch/k15/http/get/ClientAnfrage.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef CLIENTANFRAGE_H
#define CLIENTANFRAGE_H
#include<string>
#include<boost/asio.hpp>
#include<cstring>   // strchr()
#include<cctype>    // isalnum()

namespace {
   std::string urlencode(const std::string& s) {
      std::string ergebnis;
      for(size_t i = 0; i < s.length(); ++i) {
         char c = s[i];
         if(isalnum(c) || strchr("-_.!~*'()", c)) {  // RFC 2396, 2.3
            ergebnis += c;
         }
         else {
            ergebnis += '%';
            size_t ic = c/16;
            if(ic < 10) ic += 48; // 0..9
            else        ic += 55; // A..F
            ergebnis += (char)ic;
            ic = c%16;
            if(ic < 10) ic += 48; // 0..9
            else        ic += 55; // A..F
            ergebnis += (char)ic;
         }
      }
      return ergebnis;
   }
}

class ClientAnfrage {
public:
   ClientAnfrage(const std::string& wwws) 
      : socket(ioService), gesendet(false) {
      std::string wwwseite = urlencode(wwws);
      std::string pfad;
      std::string hostname;
      size_t schraegstrichPosition = wwwseite.find("/");
      if(schraegstrichPosition == std::string::npos) { // nicht vorhanden
         hostname = wwwseite;
         pfad = "/";
      }
      else { // extrahieren:
         hostname = wwwseite.substr(0, schraegstrichPosition); 
         pfad = wwwseite.substr(schraegstrichPosition);
      }
      anfrage =  "GET ";  // s. RFC 2616 Kap. 5.1.2
      anfrage += pfad + " HTTP/1.1\r\nHost: " + hostname 
         +"\r\nAccept: */*\r\nConnection: close\r\n\r\n";  // Extra-Leerzeile
      dateiname = pfad.substr(1+pfad.rfind("/")); // letzter /
      if(dateiname.length() == 0 
         || dateiname.find("?") != std::string::npos) { // keine Datei, sondern Anfrage
         dateiname = "antwort.html";
      }
      boost::asio::ip::tcp::resolver resolver(ioService);
      boost::asio::ip::tcp::resolver::query query(hostname, "http");
      server = *resolver.resolve(query);
   }
   void send() {
      // Anfrage senden
      socket.connect(server);
      socket.write_some(boost::asio::buffer(anfrage.c_str(), anfrage.length()));
      gesendet = true;
   }
   boost::asio::ip::tcp::socket& getSocket() {
      return socket;
   }
   const std::string& getDateiname() { 
      return dateiname;
   }
   bool istGesendet() {
      return gesendet;
   }
private:
   boost::asio::io_service ioService;
   boost::asio::ip::tcp::socket socket;
   boost::asio::ip::tcp::endpoint server;
   std::string anfrage;
   std::string dateiname;
   bool gesendet;
};

#endif
