/**************************************************************************************************
  foo.c - A simple math program to demonstrate features of flymake and flydoc
  Copyright 2024 Drew Gislason
  license: <https://mit-license.org>
**************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "foo.h"

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
    printf("foo v%s [n1 n2] - add two numbers\n", SZ_FOO_VER);
  else
  {
    if(argc >= 2)
      a = atoi(argv[1]);
    if(argc >= 3)
      b = atoi(argv[2]);
    printf("add     : %d + %d = %d\n", a, b, foo_add(a,b));
  }

  return 0;
}
