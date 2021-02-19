#include <iostream>
#include <math.h>

__global__
void add(int n, float *a, float *b) {
    index = blockIdx.x * blockDim.x + threadIdx.x;
    stride = blockDim.x * gridDim.x;

    for (int i = index; i < n; i += stride) {
        b[i] = a[i] + b[i]; 
    }
}

int main(void) {
    int N = 1 << 20;
    
    float *a, *b;
    cudaMallocManaged(&a, N * sizeof(float));
    cudaMallocManaged(&b, N * sizeof(float));

    float *a = new float[N];
    float *b = new float[N];

    for (int i=0; i < N; i++){
        a[i] = 1.0f;
        b[i] = 2.0f;
    }

    add<<<1, 256>>>(N, a, b);

    cudaDeviceSynchronize();

    float maxError = 0.0f;
    for (int i=0; i<N; i++) {
        maxError = fmax(maxError, fabs(b[i]-3.0f));
    }
    std::cout << "Max error: " << maxError << std::endl;

    cudaFree(a); 
    cudaFree(b);

    return 0;
}

