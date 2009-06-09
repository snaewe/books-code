/* cppbuch/k15/http/get/AntwortAuswerter.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef ANTWORTAUSWERTER_H
#define ANTWORTAUSWERTER_H
#include<string>
#include<cstring>
#include<cstdlib>
#include<boost/asio.hpp>
#include<fstream>
#include"ClientAnfrage.h"

class AntwortAuswerter {
public:
   AntwortAuswerter(ClientAnfrage& r) 
      : clientAnfrage(r), socket(r.getSocket()), dateiname(r.getDateiname()),
        header("noch undefiniert"), status(-1) {
   }
   void receive() {
      if(!clientAnfrage.istGesendet()) {
         clientAnfrage.send();
      }
      std::ofstream ausgabe;  // zur Speicherung des Content
      ausgabe.open(dateiname.c_str(), std::ios::binary | std::ios::out);
      size_t anzahl;
      const size_t SIZE = 4096;
      char buf[SIZE];
      do {
         boost::system::error_code error;
         anzahl = socket.read_some(boost::asio::buffer(buf, SIZE), error);
         if(error ==  boost::asio::error::eof) {
            break;             // kein Fehler, normales Ende
         }
         else {  // Puffer auswerten          
            if(status == -1) { 
               std::string tmp(buf, anzahl); 
               size_t headerEnde = tmp.find("\r\n\r\n");
               header = tmp.substr(0, headerEnde);
               int startInhalt = headerEnde + 4;  // CRLF überspringen
               // restliche Bytes wegschreiben
               int rest = (int)anzahl - startInhalt;
               if(rest > 0) {
                 ausgabe.write(buf + startInhalt, rest);
               }
               status = atoi(buf + header.find(' ') + 1);
            }
            else {
                 ausgabe.write(buf, anzahl);               
            }
         }
      } while(anzahl > 0);
      ausgabe.close();
   }
   int getStatus() {
      return status;
   }
   const std::string& getHeader() {
      return header;
   }
private:
   ClientAnfrage& clientAnfrage;
   boost::asio::ip::tcp::socket& socket;
   const std::string& dateiname;
   std::string header;
   int status;
};

#endif
