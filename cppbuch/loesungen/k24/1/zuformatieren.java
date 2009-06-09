   import java.io.*;
/* Testdatei für formatcode.cpp
* Re-Formatierung entsprechend der Blockstruktur, die durch
          * geschweifte Klammern definiert wird. Aufruf:
         * - Das Programm soll die Zeilenstruktur erhalten, d.h. ein gelesenes
*   Zeilenende führt stets zu einer neuen Zeile der Aufgabe.
        */
// Beispielcode zum Testen  

// Die  geschweifte Klammer der folgende Zeile erzeugt keine neue
       // Zeile (Zeilenstruktur erhalten)
public class Threadtest extends Thread {   private Object lock;

public Threadtest(Object l, String id) {
super(id);
lock = l;
}
         // Ist diese Zeile bündig?
   public synchronized void doit() {
      char c1 = '{';
      char c1 = '"';
                                  System.out.println(getName() + " doit()");

                                  // bleiben Leerzeilen erhalten?
   }

                                                    public void run() {
synchronized(lock) {
                           System.out.println(getName() +" String \
über zwei Zeilen }}}");
                           /**  ein schlecht
            * formatierter Kommentar
        */
                                  try {
      sleep(5000);
                   } catch(InterruptedException e) {
                           }
                                System.out.println(getName() + "String mit { und \" nach sleep");
      }
   }

                                      public static void main(String[] args ) {
 Object lock = new Object();
Threadtest t1= new Threadtest(lock, "Thread1");
 Threadtest t2= new Threadtest(lock, "Thread2");
t1.start();     
 t2.start();
try {
         sleep(1000);
                 } catch(InterruptedException e) { }
 t1.doit();   
                t2.doit();
   }
}