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
#ifndef COUNTED_PTR_HPP
#define COUNTED_PTR_HPP

/* Klassentemplate für Smart-Pointer mit Referenz-Semantik
 * - zerstört das Objekt, auf das verwiesen wird, wenn der letzte CountedPtr
 *     der darauf verweist, zerstört wird
 */
template <class T>
class CountedPtr {
  private:
    T* ptr;        // Zeiger auf das eigentliche Objekt
    long* count;   // Verweis auf die Anzahl der darauf verweisenden Zeiger

  public:
    // mit herkömmlichem Zeiger initialisieren
    // - p muss ein von new zurückgelieferter Wert sein
    explicit CountedPtr (T* p=0)
     : ptr(p), count(new long(1)) {
    }

    // Copy-Konstruktor
    CountedPtr (const CountedPtr<T>& p) throw()
     : ptr(p.ptr), count(p.count) {  // Objekt und Zähler übernehmen
        ++*count;                    // Anzahl der Verweise inkrementieren
    }

    // Destruktor
    ~CountedPtr () throw() {
        freigabe();             // als letzter Verweis Objekt zerstören
    }

    // Zuweisung
    CountedPtr<T>& operator= (const CountedPtr<T>& p) throw() {
        if (this != &p) {       // falls keine Zuweisung an sich selbst
            freigabe();         // als letzten Verweis altes Objekt zerstören
            ptr = p.ptr;        // neues Objekt übernehmen
            count = p.count;    // Zähler vom neuen Objekt übernehmen
            ++*count;           // Anzahl der Verweise inkrementieren
        }
        return *this;
    }

    // Zugriff auf das Objekt
    T& operator*() const throw() {
        return *ptr;
    }

    // Zugriff auf eine Komponente des Objekts
    T* operator->() const throw() {
        return ptr;
    }

  private:
    void freigabe() {
        if (--*count == 0) {    // falls letzter Verweis
             delete count;      // Zähler zerstören
             delete ptr;        // Objekt zerstören
        }
    }
};

#endif /*COUNTED_PTR_HPP*/
