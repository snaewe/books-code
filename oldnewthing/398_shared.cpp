#include <stdio.h>
#include <windows.h>

// These directives place the g_iShared variable inside a shared
// memory section.
#pragma comment(linker, "/SECTION:.shared,RWS")
#pragma data_seg(".shared")
int g_iShared = 0;
#pragma data_seg()

void printit()
{
  char sz[5];
  sprintf(sz, "%d", g_iShared);
  puts(sz);
}

int __cdecl main(int argc, char **argv)
{
 while (true) {
  printit();
  // ignore the race condition; thats not the point here
  int iNew = g_iShared + 1;
  if (iNew == 10) iNew = 0;
  g_iShared = iNew;
  Sleep(1000);
 }
}

