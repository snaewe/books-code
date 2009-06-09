/* cppbuch/loesungen/k24/1/Codeformatter.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"Codeformatter.h"
#include<iostream>

void Codeformatter::einrueckung() {
   size_t levtmp = level;
   while (levtmp-- > 0) {
      std::cout.write("   ", 3);                
   }
}

void Codeformatter::read() {
   calt = c;
   is.get(c);
}

void Codeformatter::eatblanks() {
   do {  // nächstes Zeichen lesen, ggf. Leerzeichen schlucken
      read();
   } while(is.good() && warEOL && (c == ' ' || c == '\t'));
}

void Codeformatter::run() {
   while(is.good()) {
      eatblanks();
      if(is.good()) {
         // Strings "" bearbeiten
         if(calt != '\'' && calt != '\\' && c == '\"') {
            do {
               std::cout.put(c);
               read();
            } while((calt == '\\' || c != '\"') && is.good());
            std::cout.put(c);
            continue; // an den Anfang der while-Schleife springen
         }

         // // Kommentar bearbeiten
         if(calt == '/' && c == '/') {
            do {
               std::cout.put(c);
               read();
            } while(c != '\n' && is.good());
            std::cout.put(c);
            warEOL = true;
            continue; // an den Anfang der while-Schleife springen
         }

         // /* */ Kommentar bearbeiten
         if(calt == '/' && c == '*') {
            do {
               std::cout.put(c);
               warEOL = (c == '\n');
               if(warEOL) {
                  eatblanks();
                  einrueckung();
               }
               else {
                  read();
               }
            } while(!(calt == '*' && c == '/') && is.good());
            std::cout.put(c);
            continue; // an den Anfang der while-Schleife springen
         }

         // normaler Code
         if (c == '}' && calt != '\'')
            --level;           
         if (warEOL) {
            einrueckung();
         }
         std::cout.put(c);
         warEOL = (c == '\n');
         if (c == '{' && calt != '\'')
            ++level;
      }
   }
}
