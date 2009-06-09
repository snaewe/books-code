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
void f ()
{
    std::new_handler alterNewHandler;  // Zeiger auf New-Handler

    // neuen New-Handler installieren und alten merken
    alterNewHandler = std::set_new_handler(&eigenerNewHandler);
    //...
      // Operation mit new aufrufen
    //...
    // alten New-Handler wieder installieren
    std::set_new_handler(alterNewHandler);
}
