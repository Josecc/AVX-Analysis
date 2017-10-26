/**
* Tests the performance gain by using AVX.
* Use: avx_analysis <element_size> <operands>
* Author: Jose Canahui
* Date: 10/24/17
*/

#include <stdio.h>

int main(int argc, char **argv) {
  if (argc < 3) {
    printf("Usage: avx_performance <element_size> <operands>\n");
    return 0;
  }

  int type;
  int iterations;
  sscanf(argv[1],"%d",&type);
  sscanf(argv[2],"%d",&iterations);

  switch(type) {
    case 1:       // operations based on char
      printf("You've chosen char type and %i iterations.\n", iterations);
      break;
    case 2:       // operations based on short
      printf("You've chosen short type and %i iterations.\n", iterations);
      break;
    case 4:       //operations based on long
      printf("You've chosen long type and %i iterations.\n", iterations);
      break;
    case 8:       // operations based on double
      printf("You've chosen double type and %i iterations.\n", iterations);
      break;
    default:
      printf("<element_size> must be in [1, 2, 4, 8]\nYou chose: %i\n", type);
  }

}
