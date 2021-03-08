#ifndef STIVA_H_INCLUDED
#define STIVA_H_INCLUDED

#include "data.h"
#include <stdbool.h>

//----------------------------------
// Proprietatile TDA
//
struct elem {
 DATA info;
 struct elem *urm;
};
typedef struct elem Stiva, *STIVA;
//
//----------------------------------
// Metodele (operatiile) TDA
//
STIVA news(void);
STIVA push(STIVA s, DATA x);
STIVA pop(STIVA s);
STIVA cauta(STIVA s, DATA x);
DATA primul(STIVA s);
bool isEmptys(STIVA s);
bool isFull(STIVA s);
char *toString(STIVA s,char *sir);
// ...
void destroys(STIVA s);

#endif // STIVA_H_INCLUDED
