/* cppbuch/k15/host/ihost.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
/*
HINWEISE für die Benutzung unter Windows:

1. Bei der Compilation in einem MSDOS-Eingabeaufforderungs-
   Fenster die Option -lwsock32 setzen, z.B.
   g++ ihost.cpp -ihost.exe -lwsock32
   (wird bei Aufruf von make automatisch erledigt)
2. Bei der Compilation mit einer IDE im Fenster Werkzeuge->
   Compiler-Optionen o.ä. ein Häkchen bei 
   "Diese Befehle zur Linker-Kommandozeile hinzufügen"
   machen und im Feld darunter
   -lwsock32
   eintragen.
*/
#ifdef WIN32
#include<winsock.h>
#else
#include<netdb.h>
#endif
#include<iostream>

using namespace std;

int main(int argc, char* argv[]) {
   hostent* host;
   if(argc == 1) {
      cout << "Gebrauch: ihost Rechnername\n";
   }
   else {
#ifdef WIN32
      WORD wVersionRequested  = MAKEWORD( 2, 2 );
      WSADATA wsaData;
      WSAStartup( wVersionRequested, &wsaData );
#endif
      host = gethostbyname(argv[1]);
      if(host) {
         int nr = 0;
         const char* adresskomponente = host->h_addr_list[0];
         while(adresskomponente) {
         for(int i = 0; i < 4; ++i) {
            cout  << (int)(unsigned char) adresskomponente[i];
            if(i < 3) {
               cout << '.';
            }
         }
         cout << endl;
         adresskomponente = host->h_addr_list[++nr];
         }
      }
      else {
         cout << argv[1] << " kann nicht ermittelt werden" << endl;
      }
   }
#ifdef WIN32
   WSACleanup();
#endif
}
