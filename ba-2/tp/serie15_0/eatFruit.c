#include <stdlib.h>
#include <stdio.h>

#include "fruits.h"
#include "persons.h"


int main()
{
  int bob, anne;
  int fruit1, fruit2;

  bob = getBob();
  getApple(); 
  getApple(); 
  fruit1 = getApple();
  fruit2 = getBanana();

  personEat( bob, fruit1 );

  anne = getAnne();
  personEat( anne, fruit2 );

  return EXIT_SUCCESS;
}
