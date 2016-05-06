#include <stdio.h>
#include <assert.h>
#include "persons.h"
#include "fruits.h"

#define EP_First 1
#define EP_Bob 2
#define EP_Anne 3
#define EP_Last 4

int getBob()
{
  return EP_Bob;
}

int getAnne()
{
  return EP_Anne;
}

void personEat(int aPerson, int aFruit)
{
  char * sPerson;

  assert( aPerson > EP_First && aPerson < EP_Last );

  switch( aPerson)
  {
    case EP_Bob:
      sPerson = "Hi, c'est Bob !\n";
      break;
    case EP_Anne:
      sPerson = "Hallihallo, Anne parle:\n";
      break;
   default:
     sPerson = "une personne inconnue parle:\n";
     break;
  }

  printf("%s", sPerson);
  eatFruit( aFruit );
  printf("\n");
}

