/* cppbuch/k5/cdecl.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
/* 
 * Code from Chapter 3 - Unscrambling Declarations in C (p. 88-91) of
 * "Expert C Programming: Deep C Secrets" by Peter van der Linden
 *
 * "The Piece of Code that Understandeth All Parsing"
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXTOKENS 100
#define MAXTOKENLEN 64

enum type_tag { IDENTIFIER, QUALIFIER, TYPE };

struct token { 
  char type;
  char string[MAXTOKENLEN]; 
}; 


/* ---------- token stack ---------- */

/* holds tokens we read before reaching first identifier */ 
struct token stack[MAXTOKENS];

/* top of token-stack */
int top =-1;

/* holds the token just read */ 
struct token curr;

char * pop()
{
  return stack[top--].string;
}

void push(struct token s)
{
  stack[++top] = s;
}

/* ---------- utility routines ---------- */

enum type_tag classify_string(void)
     /*    look at the current token and 
      * return a value of "type" "qualifier" or "identifier" in curr.type 
      */
{
  char *s = curr.string;

  if (!strcmp(s,"const")) {
    strcpy(s,"read-only");
    return QUALIFIER;
  }
  if (!strcmp(s,"volatile")) return TYPE;
  if (!strcmp(s,"void")) return TYPE;
  if (!strcmp(s,"char")) return TYPE;
  if (!strcmp(s,"signed")) return TYPE;
  if (!strcmp(s,"unsigned")) return TYPE;
  if (!strcmp(s,"short")) return TYPE;
  if (!strcmp(s,"int")) return TYPE;
  if (!strcmp(s,"long")) return TYPE;
  if (!strcmp(s,"float")) return TYPE;
  if (!strcmp(s,"double")) return TYPE;
  if (!strcmp(s,"struct")) return TYPE;
  if (!strcmp(s,"union")) return TYPE;
  if (!strcmp(s,"enum")) return TYPE;

  /* If we get here, we've tried everything else, so... */
  return IDENTIFIER;
}

void gettoken(void)
     /* read the next token into curr.string 
      * if it is alphanumeric, classify_string 
      * else it must be a single character token 
      * curr.type = the token itself; terminate curr.string with a nul. 
      */
{
  char *p = curr.string;

  /* read past any spaces */
  while ((*p = getchar()) == ' ')
    ; /* Empty loop body */

  if (isalnum(*p)) {
    /* it starts with A-Z, 0-9, so read in identifier */
    while ( isalnum(*++p=getchar()) )
      ; /* Empty loop body */
    ungetc(*p,stdin);
    *p = '\0';
    curr.type = classify_string();
    return;
  }
  if (*p == '*') {
    strcpy(curr.string,"pointer to");
    curr.type = '*';
    return;
  }
  curr.string[1] = '\0';
  curr.type = *p;
  return;
}

void read_to_first_identifier (void)
     /* gettoken and push it onto the stack until the first identifier is read. 
      * Print "identifier is", curr.string 
      * gettoken
      */
{
  gettoken();
  while( curr.type != IDENTIFIER ) {
    push(curr);
    gettoken();
  }
  printf("%s is ", curr.string);
  gettoken();
}


/* ---------- parsing routines ---------- */

void deal_with_arrays (void)
     /*    while you've got "[size]" print it out and read past it 
      */
{
  while(curr.type == '[') {
    printf("array ");
    gettoken(); /* a number or ']' */
    if (isdigit(curr.string[0])) {
      printf("0..%d ", atoi(curr.string)-1);
      gettoken();
    }
    gettoken(); /* read next past the ']' */
    printf("of ");
  }
}

void deal_with_function_args(void)
     /*  read past closing ')' print out "function returning" 
      */
{
  while(curr.type != ')') {
    gettoken();
  }
  gettoken();
  printf("function that returns ");
}

void deal_with_pointers(void)
     /* while you've got "*" on the stack print "pointer to" and pop it 
      */
{
  while( stack[top].type == '*' ) {
    printf("%s ", pop());
  }
}

void deal_with_declarator(void)
     /* if curr.type is '[' deal_with_arrays 
      * if curr.type is '(' deal_with_function_args 
      * deal_with_any_pointers 
      * while there's stuff on the stack 
      *   if it's a '(' 
      *     pop it and gettoken; it should be the closing ')' 
      *     deal_with_declarator 
      *   else pop it and print it
      */
{
  switch(curr.type) {
  case '[' : deal_with_arrays(); break;
  case '(' : deal_with_function_args(); break;
  }

  deal_with_pointers();

  /* process tokens that we stacked while reading to identifier */
  while(top >= 0) {
    if (stack[top].type == '(') {
      pop();
      gettoken(); /* read past ')' */
      deal_with_declarator();
    }
    else {
      printf("%s ",pop());
    }
  }
}



/* ---------- main routine ---------- */
int main ()
{
  /* put tokens on stack until we reach identifier */
  read_to_first_identifier(); 
  deal_with_declarator();
  printf("\n");
  return 0;
}



/* Precedence rule for understanding C declarations
 * ("Syntax only a compiler could love")
 *
 * Start by finding the name of the thing being declared (the declarator)
 * Then the precedence is:
 *   1. parenthesis that group things to the declarator
 *   2. postfix operators for functions "()" and arrays "[]"
 *   3. prefix operator for pointer-to "*"
 *
 * Also, if a const/volatile type-specifier is beside a type, 
 *       it applies to that type; otherwise the const/volatile specifier
 *       applies to the asterisk to its immediate left
 */
