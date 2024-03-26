# Project foo

Version 1.4

A program that does simple math: add, multiply, square numbers.

This version uses dependencies `bar` (multiply), `baz` (square) and `qux` (exponents)

## History

Branch  | Ver | Description
------- | --- | -----------
main    | 1.0 | function foo_add(), no dependencies
main    | 1.1 | adds dependency bar for bar_multiply()
main    | 1.2 | adds dependency baz for baz_square()
main    | 1.4 | uses baz v1.1 so baz_square() uses dependency quz_power()

## Functions

```
int foo_add(int a, int b)
```
