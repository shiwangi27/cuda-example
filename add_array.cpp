#include <iostream>
#include <math.h>

void add(int n, float *a, float *b) {
    for (int i=0; i < n; i++) {
        b[i] = a[i] + b[i]; 
    }
}

int main(void) {
    int N = 1 << 20;
    
    float *a = new float[N];
    float *b = new float[N];

    for (int i=0; i < N; i++){
        a[i] = 1.0f;
        b[i] = 2.0f;
    }

    add(N, a, b);

    float maxError = 0.0f;
    for (int i=0; i<N; i++) {
        maxError = fmax(maxError, fabs(b[i]-3.0f));
    }
    std::cout << "Max error: " << maxError << std::endl;

    delete [] a; 
    delete [] b;

    return 0; 
}

