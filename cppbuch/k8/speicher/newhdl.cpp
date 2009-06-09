/* cppbuch/k8/speicher/newhdl.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<new>
using namespace std;

const size_t BLOCKGROESSE = 64000,
             MAXBLOECKE   = 50000;

int* reserveSpeicher = 0;

void Speicherfehler()  throw (bad_alloc) {
    cerr <<"Memory erschöpft! Speicherfehler() aufgerufen!\n";
    if(reserveSpeicher) {
       cerr << "Einmal Platz schaffen!\n";
       delete [] reserveSpeicher;
       reserveSpeicher = 0;
    }
    else {
       cerr << "Exeption auslösen!\n";
       throw bad_alloc();
    }
}

int main() {

    set_new_handler(Speicherfehler);

    reserveSpeicher = new int[10*BLOCKGROESSE];// Speicher belegen
    int* ip[MAXBLOECKE] = {0};
    size_t blockNr = 0;

    try {
       while (blockNr < MAXBLOECKE)  { // Speicher fressen
            ip[blockNr] = new int[BLOCKGROESSE];
            cout << "Block " << blockNr << " beschafft" << endl;
            ++blockNr;
       }
       if (blockNr == MAXBLOECKE-1) {
            cout << "Block-Array erschöpft" << endl;
       }
    }

    catch(const bad_alloc& exc)   {
       cerr << ++blockNr << " Blöcke beschafft\n"
            << "bad_alloc ausgeworfen! Grund: "
            << exc.what() << endl;
    }
    catch(...) {  
       cerr << "unbekannte Exception!\n";
    }
}
