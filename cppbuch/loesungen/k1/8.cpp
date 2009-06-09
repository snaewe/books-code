/* cppbuch/loesungen/k1/8.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>

using namespace std;

int main() {
   int n1, n2;
   bool ungueltig;
   do {
      cout << "Natürliche Zahlen n1 und n2 eingeben (n1 <= n2):";
      cin >> n1  >> n2;
      ungueltig = n1 < 0 || n2 < 0 || n1 > n2;
      if(ungueltig) {
         cout << "Eingabefehler!" << endl;
      }
   } while(ungueltig);

   /* Berechne die Summe beider Zahlen */
   int summe = 0;
   cout << "a) Summe mit for-Schleife berechnet: ";
   for(int i = n1; i <= n2; ++i) {
      summe += i;
   }
   cout << summe << endl;

   cout << "b) Summe mit while-Schleife berechnet: ";
   summe = 0;
   int i = n1;
   while(i <= n2) {
      summe += i++;
   }
   cout << summe << endl;

   cout << "c) Summe mit do while-Schleife berechnet: ";
   summe = 0;
   i = n1;
   do {
      summe += i++;
   } while(i <= n2);
   cout << summe << endl;

   cout << "d) Summe ohne Schleife berechnet: ";
   summe = n2*(n2+1)/2 - (n1-1)*n1/2 ;
   cout << summe << endl;

   return 0;
}
