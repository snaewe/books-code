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
char f1 (const std::string s, int idx)
{
    std::string tmp = s;  // lokales Objekt, das bei einer Ausnahme
    //...                     //  automatisch zerstört wird
    char c = s.at(idx);   // könnte Ausnahme auslösen
    //...
    return c;
}

void foo()
{
    try {
        std::string s("hallo");  // wird bei einer Ausnahme zerstört
        f1(s,11);    // löst eine Ausnahme aus
        f2();        // wird bei einer Ausnahme in f1() nicht aufgerufen
    }
    catch (...) {
        std::cerr << "Exception, wir machen aber weiter" << std::endl;
    }

    // hier geht es nach der Ausnahme in f1() weiter
    //...
}
