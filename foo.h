/**************************************************************************************************
  foo.h
  Copyright 2024 Drew Gislason
  license: <https://mit-license.org>
**************************************************************************************************/
#ifndef FOO_H
#define FOO_H

// allows source to be compiled with C or C++ compilers
#ifdef __cplusplus
  extern "C" {
#endif

#define SZ_FOO_VER  "1.0"

#ifndef DEBUG
  #define DEBUG    0
#endif

#if DEBUG
  #define SZ_DEBUG "(debug) "
#else
  #define SZ_DEBUG ""
#endif

int foo_add(int a, int b);

#ifdef __cplusplus
  }
#endif

#endif // FOO_H
