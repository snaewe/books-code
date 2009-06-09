/* cppbuch/k15/http/server/HttpResponse.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H
#include<string>
#include<iostream>

namespace {
   std::string i2string(int i) {  // wandelt \tt{int} in einen String um
      // Alternative: boost::lexical_cast  aus Abschnitt \ref{lexicalcast}
      std::string ergebnis;
      if(i == 0) {
         ergebnis = "0";
      }
      else {
         bool negativ = (i < 0);
         while(i != 0) {
            ergebnis.insert(ergebnis.begin(), abs(i % 10) + '0');
            i /= 10;
         }
         if(negativ) {
            ergebnis.insert(ergebnis.begin(), '-');
         }
      }
      return ergebnis;
   }
}

class HttpResponse {
public:
   HttpResponse(int st) 
      : status(st) {
      std::string zeile("HTTP/1.1 ");
      zeile += i2string(status);
      zeile += std::string(" ") + getStatusText() + "\r\n";
      header = zeile; 
   }
   void addToHeader(const std::string& key, const std::string& value) {
      header += key + ": " + value +  "\r\n";
   }
   void sendHeader(boost::asio::ip::tcp::socket& socket) {
      header +=  "\r\n";
      socket.write_some(boost::asio::buffer(header.c_str(), header.length()));
      std::cout << "GESENDETER HEADER:\n" << header;
   }
   std::string getHTMLMessage(const std::string& text ="") {
      std::string statusMsg(i2string(status) + " " + getStatusText());
      std::string msg("<html><head><title>");
      msg +=  statusMsg + "</title></head>"; 
      msg += "<body><h1>" + statusMsg + "</h1>" + text + "</body></html>";
      return msg;
   }
private:
   std::string getStatusText() {
      std::string txt;
      switch (status) {  // reduzierte Auswahl
      case 200:   txt = "OK";           break;
      case 400:   txt = "Bad Request";  break;
      case 404:   txt = "Not Found";    break;
      case 500:   txt = "Internal Server Error";   break;
      case 501:   txt = "Not Implemented";         break;
      default:    txt = "undefined";
      }
      return txt;
   }
   int status;
   std::string header;
};
#endif
