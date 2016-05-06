#include <stdio.h>
#include <assert.h>
#include "fruits.h"

#define EF_First 1
#define EF_Apple 2
#define EF_Banana 3
#define EF_Last 4

static int numberOfFruits=0;

int getApple()
{
  numberOfFruits++;
  return EF_Apple;
}

int getBanana()
{
  numberOfFruits++;
  return EF_Banana;
}

void eatFruit(int aFruit)
{
  char * sFruit;


  assert( aFruit > EF_First && aFruit < EF_Last );

  switch( aFruit) {
    case EF_Apple:
      sFruit = "une pomme";
      break;
    case EF_Banana:
      sFruit = "une banane ";
      break;
    default:
      sFruit = "fruit pas connu";
    break;
  }

  printf(" mjam, je mange %s\n", sFruit);
  printf(" Il y a encore %d fruits\n", --numberOfFruits);
}

