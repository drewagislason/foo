/**************************************************************************************************
  foo.c - A simple math program to demonstrate features of flymake and flydoc
  Copyright 2024 Drew Gislason
  license: <https://mit-license.org>
**************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "foo.h"
#include "bar.h"
#include "baz.h"

#ifndef DEBUG
  #define DEBUG 0
#endif
#if DEBUG
  #define SZ_FOO_ADD      "  debug: foo_add(a,b)"
  #define SZ_BAR_MULTIPLY "  debug: bar_multiply(a,b)"
  #define SZ_BAZ_SQUARE   "  debug: baz_square(a)"
#else
  #define SZ_FOO_ADD      ""
  #define SZ_BAR_MULTIPLY ""
  #define SZ_BAZ_SQUARE   ""
#endif 

/*!------------------------------------------------------------------------------------------------
  @defgroup foo A simple math program to demonstrate features of flymake and flydoc

  Branch  | Ver | Description
  ------- | --- | -----------
  main    | 1.0 | function foo_add(), no dependencies
  main    | 1.1 | adds dependency bar for bar_multiply()
  main    | 1.2 | adds dependency baz for baz_square()
  main    | 1.4 | latest, uses baz v1.1 so baz_square() uses dependency quz_power()
  new_api | 2.0 | function foo_add() uses an array of strings. Incompatible with 1.x

  usage = foo [n1 n2] - show simple math on two numbers
*///-----------------------------------------------------------------------------------------------

/*!------------------------------------------------------------------------------------------------
  sum two numbers

  @param    a   first addend number
  @param    b   second addend number
  @return   sum of a + b
*///-----------------------------------------------------------------------------------------------
int foo_add(int a, int b)
{
  return a + b;
}

int main(int argc, char *argv[])
{
  int a = 3;
  int b = 2;

  if(argc > 1 && ((strcmp(argv[1], "--help") == 0) || (strcmp(argv[1], "--version") == 0)))
    printf("foo v%s [n1 n2] - simple math on two numbers\n", SZ_FOO_VER);
  else
  {
    if(argc >= 2)
      a = atoi(argv[1]);
    if(argc >= 3)
      b = atoi(argv[2]);

    printf("add     : %d + %d = %d%s\n", a, b, foo_add(a,b), SZ_FOO_ADD);
    printf("multiply: %d * %d = %d%s\n", a, b, bar_multiply(a,b), SZ_BAR_MULTIPLY);
    printf("square  : %d ^ 2 = %d%s\n", a, baz_square(a), SZ_BAZ_SQUARE);
  }

  return 0;
}
