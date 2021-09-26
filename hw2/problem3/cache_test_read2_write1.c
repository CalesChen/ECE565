#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>

const int stride = 16;
int num_elements;
int num_traversals;
uint64_t *array;

double calc_time(struct timespec start, struct timespec end) { 
  double start_sec = (double)start.tv_sec*1000000000.0 + (double)start.tv_nsec; 
  double end_sec = (double)end.tv_sec*1000000000.0 + (double)end.tv_nsec; 
  if (end_sec < start_sec) {  
    return 0;   
  } else {   
    return end_sec - start_sec;
  } 
}

void init_array(){
  int i, j;
  uint64_t tmp;
  for(int i = 0 ; i < num_elements ; ++i){
    array[i] = 0;
  }
}

int main(int argc, char** argv){
  if(argc != 2){
    printf("Please input 1 number for traversal number");
    return 1;
  }
  int i;
  uint64_t index = 0;
  struct timespec start_time, end_time;

  num_elements = 2820000;
  num_traversals = atoi(argv[1]);
  array = (uint64_t*)malloc(num_elements * sizeof(uint64_t));

  init_array();
  int temp;
  index = num_traversals;
  clock_gettime(CLOCK_MONOTONIC, &start_time);
  for(;index > 0 ; --index){
    for (i=0; i < num_elements; i++) {
      temp = array[i];
      array[i] = 1;
      temp = array[i];
    }
  }
  
  clock_gettime(CLOCK_MONOTONIC, &end_time);

  double elapsed_ns = calc_time(start_time, end_time);
  printf("Time = %f\n", elapsed_ns);
  printf("Bandwidth for write = %f GB/s \n ", (((uint64_t)num_elements * (uint64_t)num_traversals * 8* 3) / (elapsed_ns)));

  free(array);
  
  return 0;
}