#include <stdarg.h>
#include <stdio.h>

#include "cmathematics.h"

#ifndef VEC_H
#define VEC_H

typedef struct
{
  unsigned int dim;
  float *elements;
} vec;
/*
 This extern keyword in C is used to define variable or something whose
 definition actually lives in another module, e.g here we are using it but
 extern will let the compiler know that  VEC_UNDEFINED is defined somewher
 in our case it is defined in vec.c
 */
extern const vec VEC_UNDEFINED;
/*
 This is function to allocate the memory for the vector
  */
vec allocate (unsigned int dim);

/*
 *
 */
vec constructDefaultVector (unsigned int dim, float val);

/*
 *
 */
vec newVector (unsigned int numArgs, ...);
/*
 *
 */
vec constructEmptyVector (unsigned int dim);
/*
 *
 */
vec copyptr (vec *v);
/*
 *
 */
vec copy (vec v);
/*
 *
 */
void print (vec v);
/**
 *
 */
bool equals (vec v1, vec v2);
/*
 *
 */

#define vector(...) newVector (NUMARGS (float, __VA_ARGS__), ##__VA_ARGS__)
#endif
