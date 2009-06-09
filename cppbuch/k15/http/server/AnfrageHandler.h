/* cppbuch/k15/http/server/AnfrageHandler.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef ANFRAGEHANDLER_H
#define ANFRAGEHANDLER_H
#include<ctime>
#include<cstring>
#include<string>
#include<boost/asio.hpp>
#include"HttpResponse.h"

class AnfrageHandler {
public:
   AnfrageHandler(boost::asio::ip::tcp::socket& s, const std::string& a)
      : socket(s), anfrage(a) {
      std::cout << "ANFRAGE=:" << a << std::endl;
   }
   void process() {
      // in diesem einfachen Programm wird nur ein Schlüssel-Wert-Paar angenommen.
      // Tatsächlich können es mehr sein.
      size_t pos = anfrage.find('=');
      std::string key = anfrage.substr(0, pos);
      std::string val = anfrage.substr(pos+1);
      std::cout << "KEY=" << key << " VAL=" << val << std::endl;
      if(key == "zeitabfrage" && val == "Datum") {
         time_t jetzt = time(NULL);
         std::string zeitstring(ctime(&jetzt));
         HttpResponse httpResponse(200);
         httpResponse.addToHeader("Content-Type", "text/html");
         std::string msg = 
            "<html><head><title>C++ MiniWebServer</title></head><body>"
            "<img src=\"bild.png\" width=\"80%\"<br><hr><p>";
         msg += zeitstring + "</body></html>";
         httpResponse.addToHeader("Content-Length", i2string(msg.length()));
         httpResponse.sendHeader(socket);
         socket.write_some(boost::asio::buffer(msg.c_str(), msg.length()));
      }
      else if(key == "begruessung") {
         HttpResponse httpResponse(200);
         httpResponse.addToHeader("Content-Type", "text/html");
         std::string msg = 
            "<html><head><title>C++ MiniWebServer</title></head><body>"
            "<img src=\"bild.png\" width=\"80%\"<br><hr><p><h1>Guten Tag, ";
         msg += val + "!<h1></body></html>";
         httpResponse.addToHeader("Content-Length", i2string(msg.length()));
         httpResponse.sendHeader(socket);
         socket.write_some(boost::asio::buffer(msg.c_str(), msg.length()));
      }
      else {
         HttpResponse httpResponse(400);
         httpResponse.addToHeader("Content-Type", "text/html");
         std::string msg = httpResponse.getHTMLMessage("unbekannte Abfrage!");
         httpResponse.addToHeader("Content-Length", i2string(msg.length()));
         httpResponse.sendHeader(socket);
         socket.write_some(boost::asio::buffer(msg.c_str(), msg.length()));
      }
   }
private:
   boost::asio::ip::tcp::socket& socket;
   std::string anfrage;
};
#endif
