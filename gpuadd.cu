#include <stdio.h>
#include <stdlib.h>

__global__ void add(int *d_a, int *d_b, int *d_c){
  int index = threadIdx.x + blockIdx.x * blockDim.x;
  d_c[index] = d_a[index] + d_b[index];
}

int main(int argc, char ** argv){
  int N = 12;
  int size = N * sizeof(int);
  int a[N], b[N], c[N];
  int *d_a, *d_b, *d_c;


  //Alloc space for device
  cudaMalloc((void **) &d_a, size);
  cudaMalloc((void **) &d_b, size);
  cudaMalloc((void **) &d_c, size);

  for (int i = 0; i< N; i++){
    a[i] = i;
    b[i] = 2*i;
  }

  cudaMemcpy(d_a, a, size, cudaMemcpyHostToDevice);
  cudaMemcpy(d_b, b, size, cudaMemcpyHostToDevice);

  add<<<N,1>>>(d_a, d_b, d_c);

  cudaMemcpy(c, d_c, size, cudaMemcpyDeviceToHost);

  for(int i = 0; i < N; i++){
    printf("%i", c[i]);
    printf("\n");
  }

  cudaFree(d_a);
  cudaFree(d_b);
  cudaFree(d_c);

  return 0;
}