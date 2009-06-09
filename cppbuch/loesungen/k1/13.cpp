#include<iostream>
using namespace std;

int main() {
   cout << "Bitte eine Startzahl > 0 eingeben: ";
   long long zahl;
   cin >> zahl;
   int iterationen = 0;
   long long maxzahl=0;
   while(zahl > 1) {
      ++iterationen;
      if(zahl % 2 == 0) {            // Zahl ist gerade
         zahl /= 2;
      }
      else {
         zahl = 3 * zahl + 1;
      }
      cout << zahl << endl;
      if(maxzahl < zahl) {
         maxzahl = zahl;
         cout << " neues Maximum. Weiter mit ENTER" << endl;
         string dummy;
         getline(cin, dummy); // weiter mit Tastendruck
      }
   }
   cout << iterationen << " Iterationen. Maximale Zahl =" 
        << maxzahl << endl;
}

