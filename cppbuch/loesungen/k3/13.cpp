/* Dieses Programm listet sich selbst */
#include <string>
#include <iostream>
using namespace std;
char AS = 34;         // Anführungsstriche
char BS = 92;         // Backslash
char NZ = 10;         // neue Zeile
void c(const string& t) {
  cout << t << AS;
  unsigned int i = 0;
  while (i < t.length()) {
     if (t[i] == NZ) cout << BS << 'n'<<AS<< t[i] << AS;
     else cout << t[i];
     ++i;
  }
  cout<<AS<<')'<<';'<<'c'<<'('<<'s'<<')'<<';'<<'}'<<NZ;
}
int main(){ string s("/* Dieses Programm listet sich selbst */\n"
"#include <string>\n"
"#include <iostream>\n"
"using namespace std;\n"
"char AS = 34;         // Anführungsstriche\n"
"char BS = 92;         // Backslash\n"
"char NZ = 10;         // neue Zeile\n"
"void c(const string& t) {\n"
"  cout << t << AS;\n"
"  unsigned int i = 0;\n"
"  while (i < t.length()) {\n"
"     if (t[i] == NZ) cout << BS << 'n'<<AS<< t[i] << AS;\n"
"     else cout << t[i];\n"
"     ++i;\n"
"  }\n"
"  cout<<AS<<')'<<';'<<'c'<<'('<<'s'<<')'<<';'<<'}'<<NZ;\n"
"}\n"
"int main(){ string s(");c(s);}
