#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]) {
    for (int i = 0; i < N; i++) {
        B[0] += (A[i]/N);
    }
    
    float sum = 0, standardDeviation = 0;
  for(int i = 0; i < N; i++) {
    sum += A[i];
 }
  
  for(int i = 0; i < N; i++) {
    standardDeviation += pow(A[i] - B[0], 2);
  }
    B[1] = sqrt(standardDeviation/N);
    
    float num = 1;
    for (int i = 0; i < N; i++) {
        num = num * A[i];
    }
    B[2] = pow(num,1.0/N);
    
    double sum2 = 0;
    for (int i = 0; i < N; i++)
        sum2 = sum2 + (1.0/A[i]);
    B[3] = N/sum2;
    
    float high = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] >= high) {
            high = A[i];
        }
    }
    B[4] = high;
    
    float low = B[4];
    for (int i = 0; i < N; i++) {
        if (A[i] < low) {
            low = A[i];
        }
    }
    B[5] = low;
    
}