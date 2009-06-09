/* cppbuch/k24/folgen/all_any_none.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
//#include<algorithm>
#include<vector>
#include<iostream>
#include<showSequence.h>
using namespace std;

/// Sobald Ihr Compiler all-of, none_of und any_of unterstützt,
// alle Zeilen bis /// Ende // löschen und #include<algorithm>
// einbinden.
template<class Iterator, class Predicate>
bool all_of(Iterator first, Iterator last, Predicate pred) {
   bool result = true;
   while(first != last) {
      if(!pred(*first)) {
         result = false;
         break;
      }
      ++first;
   }
   return result;
}

template<class Iterator, class Predicate>
bool none_of(Iterator first, Iterator last, Predicate pred) {
   bool result = true;
   while(first != last) {
      if(pred(*first)) {
         result = false;
         break;
      }
      ++first;
   }
   return result;
}

template<class Iterator, class Predicate>
bool any_of(Iterator first, Iterator last, Predicate pred) {
   return !none_of(first, last, pred);
}
///////////////////  Ende //////////////////////////////


struct istPositiv {
   bool operator()(int x) {
      return x >= 0;
   }
};

int main() {
   vector<int> folge(12);
   for(size_t i = 0; i < folge.size(); ++i) {
      folge[i] = -i-1; // ggf. verändern
   }
   cout << "Folge = ";
   showSequence(folge);
   if(all_of(folge.begin(), folge.end(), istPositiv())) {
      cout << "Bedingung >=0 gilt für alle Elemente" << endl;
   }
   else {
      cout << "Bedingung >=0 gilt nicht für alle Elemente" << endl;
   }
   if(none_of(folge.begin(), folge.end(), istPositiv())) {
      cout << "Bedingung >= 0 gilt für kein Element" << endl;
   }
   else {
      cout << "Bedingung  >=0 gilt für mindestens ein Element" << endl;
   }
   if(any_of(folge.begin(), folge.end(), istPositiv())) {
      cout << "Bedingung >= 0 gilt für wenigstens ein Element" << endl;
   }
   else {
      cout << "Bedingung >=0 gilt für kein Element" << endl;
   }
}
