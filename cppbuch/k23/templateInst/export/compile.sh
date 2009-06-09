#! /bin/sh
rm *.ti
rm *.tii
rm *.et
rm *.o
rm a.out
icpc -export -c -Wcheck -Wall func01.cpp
icpc -export -c -Wcheck -Wall func02.cpp
icpc -export -c -Wcheck -Wall main.cpp
icpc -export -c -Wcheck -Wall meintypImpl.cpp
icpc -export -Wcheck -Wall *.o

