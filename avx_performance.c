/**
* Tests the performance gain by using AVX.
* Use: avx_analysis <element_size> <operands>
* Author: Jose Canahui
* Date: 10/24/17
* // TODO: add same number to the packed vector
*/

#include <sys/time.h>
#include <stdio.h>

void calculate(void (*add)(void*, int, double), int iterations, int type, void*buf) {
  struct timeval start;
  struct timeval end;
  gettimeofday(&start, NULL);
  for(int i = 0; i < iterations; i++) {
    double addend = (start.tv_usec / 3600) % (i + 10);
    (*add)(buf, i % (32 / type), addend);
  }
  gettimeofday(&end, NULL);
  unsigned long long duration = 1000 * (end.tv_sec - start.tv_sec) +
                                (end.tv_usec - start.tv_usec) / 1000;
  printf("Finished in %llums\n", duration);
}

void addChar(void*buf, int index, double addend) {
  char * augend = buf;
  augend[index] = augend[index] + ((int)addend + '1');
};

void addInt(void*buf, int index, double addend) {
  int * augend = buf;
  augend[index] = augend[index] + (int)addend;
};

void addLong(void*buf, int index, double addend) {
  long * augend = buf;
  augend[index] = augend[index] + (long)addend;
};

void addDouble(void*buf, int index, double addend) {
  double * augend = buf;
  augend[index] = augend[index] + addend;
};

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
      char charBuf[32] = {3, 1, 7, 5, 2, 4, 6, 1, 3, 0, 6, 6, 8, 2, 1, 2,
                         4, 6, 1, 2, 8, 5, 2, 3, 5, 4, 5, 7, 8, 6, 5, 3};
      calculate(&addChar, iterations, type, &charBuf);
      break;
    case 2:       // operations based on int
      printf("You've chosen int type and %i iterations.\n", iterations);
      int intBuf[16] = {3, 1, 7, 5, 2, 4, 6, 1, 3, 0, 6, 6, 8, 2, 1, 2};
      calculate(&addInt, iterations, type, &intBuf);
      break;
    case 4:       //operations based on long
      printf("You've chosen long type and %i iterations.\n", iterations);
      long longBuf[8] = {3, 1, 7, 5, 2, 4, 6, 1};
      calculate(&addLong, iterations, type, &longBuf);
      break;
    case 8:       // operations based on double
      printf("You've chosen double type and %i iterations.\n", iterations);
      double doubleBuf[4] = {3, 1, 7, 5};
      calculate(&addDouble, iterations, type, &doubleBuf);
      break;
    default:
      printf("<element_size> must be in [1, 2, 4, 8]\nYou chose: %i\n", type);
  }

}
