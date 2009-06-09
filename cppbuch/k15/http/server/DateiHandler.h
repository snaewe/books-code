/* cppbuch/k15/http/server/DateiHandler.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef DATEIHANDLER_H
#define DATEIHANDLER_H
#include<fstream>
#include<string>
#include<boost/asio.hpp>
#include<boost/filesystem/operations.hpp>
#include"HttpResponse.h"

class DateiHandler {
public:
   DateiHandler(boost::asio::ip::tcp::socket& s, const std::string& d) 
      : socket(s), dateiname(d) {
   }
   void process() {
      std::ifstream quelle(dateiname.c_str(), std::ios::in | std::ios::binary);
      if(quelle) {
         sendeDatei(quelle);
      }
      else {  // Datei nicht vorhanden
         HttpResponse httpResponse(404);
         httpResponse.addToHeader("Content-Type", "text/html");
         std::string msg = httpResponse.getHTMLMessage("Datei nicht gefunden!");
         httpResponse.addToHeader("Content-Length", i2string(msg.length()));
         httpResponse.sendHeader(socket);
         socket.write_some(boost::asio::buffer(msg.c_str(), msg.length()));
      }
   }
private:
   boost::asio::ip::tcp::socket& socket;
   std::string dateiname;

   std::string getContentType() {
      std::string typ("application/octet-stream");
      size_t punkt = dateiname.rfind('.');
      if(punkt < std::string::npos) {
         std::string extension = dateiname.substr(punkt+1);
         for(size_t i = 0; i < extension.length(); ++i) {
            extension[i] = toupper(extension[i]);
         }
         // unvollständige Auswahl aus http://de.selfhtml.org/diverses/mimetypen.htm :
         if(extension == "HTML") typ = "text/html";
         else if(extension == "TXT") typ = "text/plain; charset=iso-8859-1";
         else if(extension == "JPG") typ = "image/jpeg";
         else if(extension == "PNG") typ = "image/png";
         else if(extension == "PDF") typ = "application/pdf/";
      }
      return typ;
   }
   void sendeDatei(std::ifstream& quelle) {
      boost::filesystem::path p(dateiname);
      size_t bufsize = boost::filesystem::file_size(p);
      HttpResponse httpResponse(200);
      httpResponse.addToHeader("Content-Type", getContentType());
      httpResponse.addToHeader("Content-Length", i2string(bufsize));
      httpResponse.sendHeader(socket);
      char* const buf = new char[bufsize];
      size_t pos = 0;
      while(quelle.get(buf[pos++])); // Datei lesen und in buf abspeichern
      socket.write_some(boost::asio::buffer(buf, bufsize));
      delete [] buf;
   }
};
#endif
