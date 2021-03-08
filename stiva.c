#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stiva.h"

// Initializeaza o lista vida
//
STIVA news()
{
 return NULL;
}
//
// ----------------------------------------------------
// Distruge o lista vida
//
void destroys(STIVA s)
{ STIVA p;
 for(;!isEmptys(s); s=p) {
 p=s->urm;
 free(s->info);
 free(s);
 }
}
//
// ----------------------------------------------------
// Insereaza un element in fata listei
//
STIVA push(STIVA s, DATA x)
{
 STIVA t;
 if((t = (STIVA)malloc(sizeof(Stiva)))==NULL) {
 printf("\n\a EROARE la alocarea memoriei");
 return s;
 }
 // alocare reusita
 t->info = malloc(500 *sizeof(char));
 strcpy(t->info, x);
 t->urm = s;
 return t;
}
// sterge primul element din lista
STIVA pop(STIVA s)
{
   if(!isEmptys(s))
   {
       STIVA p = s->urm; // se retine adresa catre al 2lea element, care va deveni ulterior primul element
       free(s); //se dealoca spatiul asociat primului element
       free(s->info);//se dealoca spatiul asociat sirului de caractere stocat in primul element
       return (p); // se returneaza adresa noului cap al stivei <=> se actualizeaza pointerul catre primul element
   }
    return s; // daca stiva este goala (s==NULL), se returneaza pointerul s (nu se sterge nimic)
}
//
// -----------------------------------------------------
//
// Cauta o cheie in lista si intoarce adresa elementului
//
STIVA cauta(STIVA s,DATA x)
{
 for( ;!isEmptys(s) ;s=s->urm)
    if(strcmp(s->info,x) == 0)
        return s;
 return NULL;

}
//
// ----------------------------------------------------
//
// Returneaza cheia primului element al listei
// sau ABSENT daca nu este in lista
//
DATA primul(STIVA s)
{
 return isEmptys(s) ? ABSENT:s->info ;
}
//
// ----------------------------------------------------
// Verifica daca lista este vida
//
bool isEmptys(STIVA s)
{
 return s==NULL;
}
//
// ----------------------------------------------------
// Verifica daca lista este plina
//
bool isFull(STIVA s)
{
 return false;
}
//
// ----------------------------------------------------


void parcurgere_stiva_recursiv(STIVA s,char *zona, char *sir)
{
    if(!isEmptys(s->urm))
        parcurgere_stiva_recursiv(s->urm, zona, sir);
    sprintf(zona, FORMAT, primul(s));
    strcat(sir,zona);
}


// Conversie stiva in sir de caractere
//
char *toString(STIVA s,char *sir)
{
 char zona[2000];
 strcpy(sir,"\0");
 if(!isEmptys(s))
{
     parcurgere_stiva_recursiv(s,zona,sir);
}
 return sir;
}


