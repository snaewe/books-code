Blitz-Library installieren

Die Blitz-Bibliothek wird nur für die vergleichende
Performance-Messung benötigt. Die Installation von Blitz unter Windows
ist nicht notwendig, weil Blitz bereits in das MinGW-Verzeichnis
integriert ist, wenn das Letztgenannte von der DVD installiert wurde.


Installation unter Linux:

Loggen Sie sich als Root ein, kopieren Sie die mit blitz- beginnenden
Dateien vom Verzeichnis linux/blitz der DVD nach /usr/local und geben
dort ein:

tar xvfz blitz-0.9.tar.gz

patch -p0 < blitz-gcc43.patch

cd blitz-0.9

./configure

make install

ldconfig


