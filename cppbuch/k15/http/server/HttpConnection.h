/* cppbuch/k15/http/server/HttpConnection.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef HTTPCONNECTION_H
#define HTTPCONNECTION_H
#include<iostream>
#include<string>
#include<boost/asio.hpp>
#include"AnfrageHandler.h"
#include"DateiHandler.h"

class HttpConnection {
public:
   HttpConnection( boost::asio::ip::tcp::acceptor& a, const std::string& v) 
      : acceptor(a), socket(a.get_io_service()), verzeichnis(v) {
   }
   void accept() {
      acceptor.accept(socket);
   }
   void operator()() {
      const size_t BUFSIZE = 1024;
      char daten[BUFSIZE+1] = {0};
      // Anfrage lesen
      size_t anzahl = socket.read_some(boost::asio::buffer(daten, BUFSIZE));
      daten[anzahl] = '\0';
      std::cout << daten << std::endl;
      std::string header(daten); 
      size_t leerzeichen = header.find(' ');
      // Fehlermeldung bei falschem Protokoll
      if(header.substr(0, leerzeichen) != "GET") {
         HttpResponse httpResponse(400);
         httpResponse.addToHeader("Content-Type", "text/html");
         std::string msg = httpResponse.getHTMLMessage(
                                         "Protokoll nicht implementiert!");
         httpResponse.addToHeader("Content-Length", i2string(msg.length()));
         httpResponse.sendHeader(socket);
         socket.write_some(boost::asio::buffer(msg.c_str(), msg.length()));
         return;                                                 // Abbruch!
      }
      size_t leerzeichen2 = header.find(' ', leerzeichen+1);
      std::string pfad =  header.substr(leerzeichen+1,
                                        leerzeichen2-leerzeichen-1);
      // Gibt es eine Anfrage oder ist eine Datei gewünscht?
      size_t qpos = pfad.find('?');
      if(qpos != std::string::npos) {                            // Anfrage
         AnfrageHandler ah(socket, pfad.substr(qpos+1));
         ah.process();
      }
      else {                                                     // Datei
         std::string dateiname = verzeichnis + pfad;
         if(pfad == "/" || pfad == "/favicon.ico") {
            dateiname = verzeichnis + "/index.html";
         }
         DateiHandler dh(socket, dateiname);
         dh.process();
      }
      socket.close();
   }
private:
   boost::asio::ip::tcp::acceptor& acceptor;
   boost::asio::ip::tcp::socket socket;
   std::string verzeichnis;
};
#endif

