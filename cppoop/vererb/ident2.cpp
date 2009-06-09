/* Die folgenden Code-Beispiele stammen aus dem Buch:
 *  Objektorientiertes Programmieren in C++
 *   Ein Tutorial für Ein- und Umsteiger
 * von Nicolai Josuttis, Addison-Wesley München, 2001
 *
 * (C) Copyright Nicolai Josuttis 2001.
 * Diese Software darf kopiert, verwendet, modifiziert und verteilt
 * werden, sofern diese Copyright-Angabe in allen Kopien vorhanden ist.
 * Diese Software wird "so wie sie ist" zur Verfügung gestellt.
 * Es gibt keine explizite oder implizite Garantie über ihren Nutzen.
 */
int main ()
{
    using std::cout;
    using std::endl;

    Bsp::Amph a;

    // Adresse von a
    cout << "&a: " << (void*)&a << "\n" << endl;

    // Adresse von a => als Auto, als Boot
    cout << "(Bsp::Auto*) &a: " << (void*)(Bsp::Auto*)&a << "\n";
    cout << "(Bsp::Boot*) &a: " << (void*)(Bsp::Boot*)&a << "\n\n";

    // Adresse von a => als Auto => als Fahrzeug
    cout << "(Bsp::Fahrzeug*) (Bsp::Auto*) &a: "
         << (void*)(Bsp::Fahrzeug*)(Bsp::Auto*)&a << endl;

    // Adresse von a => als Boot => als Fahrzeug
    cout << "(Bsp::Fahrzeug*) (Bsp::Boot*) &a: "
         << (void*)(Bsp::Fahrzeug*)(Bsp::Boot*)&a << '\n' << endl;
}
