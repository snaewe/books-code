/* cppbuch/k25/binaer/IOException.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#ifndef IOEXCEPTION_H
#define IOEXCEPTION_H
#include<string>
#include<cstring>
#include<exception>

namespace {  // anonymer Namespace - nur in dieser Datei gültig
   char msg[100] =  "Datei kann nicht geöffnet werden: ";
   size_t msglen = 0;
}

class IOException : public std::exception {
 public:
   IOException(const std::string& filename) {
      if(msglen == 0) {  // nur einmal berechnen
         msglen = strlen(msg);
      }
      size_t maxRestlaenge = sizeof(msg) - msglen -1;
      if(maxRestlaenge > 0) {
         strncpy(msg+msglen, filename.c_str(), maxRestlaenge);  // Puffer um Kontext ergänzen
      }
   }
   const char* what() const throw() {
      return msg;
   }
};

#endif
