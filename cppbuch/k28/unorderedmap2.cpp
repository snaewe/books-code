/* cppbuch/k28/unorderedmap2.cpp
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
typedef unordered_map<string, long>  MapType; 
typedef MapType::value_type ValuePair;

int main() {
    MapType aMap;
    aMap.insert(ValuePair("Meier, Thomas", 5192835));
    aMap.insert(ValuePair("Meier, Werner", 24439404));
    aMap.insert(ValuePair("Meier, Manfred", 535353));
    aMap.insert(ValuePair("Meier, Heiko",   635352723));
    aMap.insert(ValuePair("Meier, Andreas", 42536347));
    aMap.insert(ValuePair("Meier, Karin",   9273539));
    aMap.insert(ValuePair("Meier, Otto", 51923835));
    aMap.insert(ValuePair("Meier, Xaver", 244391404));
    aMap.insert(ValuePair("Meier, Manni", 5353053));
    aMap.insert(ValuePair("Meier, Jürgen",   635502723));
    aMap.insert(ValuePair("Meier, Annabell", 425363047));
    aMap.insert(ValuePair("Meier, Klaus",   92703539));
    aMap.insert(ValuePair("Müller, Thomas", 519235));
    aMap.insert(ValuePair("Müller, Werner", 2443404));
    aMap.insert(ValuePair("Müller, Manfred", 535053));
    aMap.insert(ValuePair("Müller, Heiko",   63532723));
    aMap.insert(ValuePair("Müller, Andreas", 425306347));
    aMap.insert(ValuePair("Müller, Karin",   92735039));
    aMap.insert(ValuePair("Müller, Otto", 5192835));
    aMap.insert(ValuePair("Müller, Xaver", 24491404));
    aMap.insert(ValuePair("Müller, Manni", 53573053));
    aMap.insert(ValuePair("Müller, Jürgen",   65502723));
    aMap.insert(ValuePair("Müller, Annabell", 45363047));
    aMap.insert(ValuePair("Müller, Klaus",   9203539));

    // Wegen der internen Hash-Struktur ist die Ausgabe unsortiert.
    cout << "Ausgabe:\n";
    MapType::const_iterator iter = aMap.begin();
    while(iter != aMap.end()) {
       cout << (*iter).first << ':'     // Name
            << (*iter).second      // Nummer
            << endl;
          ++iter;
    }

    cout << "Belegungsfaktor = " << aMap.load_factor() << endl;
    cout << "Anzahl der Buckets = " << aMap.bucket_count() << endl;

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
