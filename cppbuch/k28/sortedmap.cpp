/* cppbuch/k28/sortedmap.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<map>
#include<string>
#include<iostream>
using namespace std;

// Zwei  typedefs zur Abkürzung
typedef map<string, long>   MapType; // Vergleichsobjekt: less<string>()
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

    /* Wegen der auf einer Baumstruktur basierenden Implementierung
      ist die Ausgabe nach Namen sortiert.
    */
    cout << "Ausgabe:\n";
    MapType::const_iterator iter = aMap.begin();
    while(iter != aMap.end()) {
       cout << (*iter).first  << ':'     // Name
            << (*iter).second << endl;   // Nummer
          ++iter;
    }

    cout << "Ausgabe der Nummer nach Eingabe des Namens\n"
         << "Name: ";
    string derName;
    cin >> derName;
    cout << "Suche mit Iterator: ";
    iter = aMap.find(derName);         // O(log N)
    if(iter != aMap.end()) {
       cout << (*iter).second  << endl;
    }
    else { 
       cout << "Nicht gefunden!" << endl;
    }

    /*
    cout << "Suche mit operator[]() (Element muss existieren,\n"
        "andernfalls wird eine undef. Nummer (0) für den Namen angelegt): ";
     cout << aMap[derName]  << endl;        // O(log N)                
    */
     // im neuen Standardentwurf C++0x:
    try {
       cout << "Suche mit at(): " << aMap.at(derName)  << endl;  // O(log N)
    } catch(const exception& e) {
       cout << "Nicht gefunden! Exception: " << e.what() << endl;
    }
}
