/**
* Tests the performance gain by using AVX.
* Use: avx_analysis <element_size> <operands>
* Author: Jose Canahui
* Date: 10/24/17
*/

#include <stdio.h>

void main(int argc, char **argv) {
  if (arfc < 3) {
    fprintf("Usage: avx_performance <element_size> <operands>");
    exit(0);
  }

  int type = argv[1];
  int iterations = argv[2];

  switch(type) {
    case 1:       // operations based on char

      break;
    case 2:       // operations based on short

      break;
    case 4:       //operations based on long

      break;
    case 8:       // operations based on double

    default:
      fprintf("<element_size> must be in [1, 2, 4, 8]")
  }

}
