#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void within(int * list , int * lower, int * upper, int * ret ,int *length,int *range);

int bound(int value, int lower, int upper);

#define _RR
#ifdef _RR
#include <R.h>
#include <R_ext/Rdynload.h>
#include <Rinternals.h>

static R_NativePrimitiveArgType within_t[]={INTSXP,INTSXP,INTSXP,INTSXP,INTSXP,INTSXP};

static R_CMethodDef cMethods[]={
  {"within",(DL_FUNC) &within,6, within_t},
  {NULL,NULL,0}
};

void R_init_myLib(DllInfo *info);
#endif

