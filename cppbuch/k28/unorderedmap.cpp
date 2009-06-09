/* cppbuch/k28/unorderedmap.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<string>
#if  __GNUC__*10+__GNUC_MINOR__ < 44 
#include<tr1/unordered_map>
using namespace std::tr1;
#else
#include<unordered_map>
#endif
using namespace std;

// Zwei  typedefs zur Abkürzung
typedef unordered_map<string, long>   MapType; 
typedef MapType::value_type ValuePair;

int main() {
    MapType aMap;
    aMap.insert(ValuePair("Thomas", 5192835));
    aMap.insert(ValuePair("Werner", 24439404));
    aMap.insert(ValuePair("Manfred", 535353));
    aMap.insert(ValuePair("Heiko",   635352723));
    aMap.insert(ValuePair("Andreas", 42536347));
    aMap.insert(ValuePair("Karin",   9273539));
    // 2. Einfügen von Heiko mit einer anderen (Tel.Nummer wird 
    // NICHT ausgeführt, weil der Schlüssel schon existiert.
    aMap.insert(ValuePair("Heiko",   1000000));

    // Wegen der internen Hash-Struktur ist die Ausgabe unsortiert.
    cout << "Ausgabe:\n";
    MapType::const_iterator iter = aMap.begin();
    while(iter != aMap.end()) {
       cout << (*iter).first  << ':'    // Name
            << (*iter).second << endl;  // Nummer
          ++iter;
    }
    cout << "Ausgabe der Nummer nach Eingabe des Namens\n"
         << "Name: ";
    string derName;
    cin >> derName;
    cout << "Suche mit Iterator: ";
    iter = aMap.find(derName);         // O(1)
    if(iter != aMap.end()) {
       cout << (*iter).second  << endl;             
    }
    else { 
       cout << "Nicht gefunden!" << endl;
    }
    cout << "Belegungsfaktor = " << aMap.load_factor() << endl;
    cout << "Anzahl der Buckets = " << aMap.bucket_count() 
         << ". Belegt sind:" << endl;
    for(size_t i=0; i < aMap.bucket_count(); ++i) {
       if(aMap.bucket_size(i) > 0) {
          cout << "Bucket " << i << " : " ;
          MapType::const_local_iterator locIter = aMap.begin(i);
          while(locIter !=  aMap.end(i)) {
             cout << (*locIter).first  << ' ' 
                  << (*locIter).second << "    ";
             ++locIter;
          }
          cout << endl;
       }
    }
}
