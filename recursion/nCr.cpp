#include <iostream>

using namespace std;

int factorial(int n){

    if(n==0){
        return 1;
    }

    return n*factorial(n-1);
}

// Combination of 'r' objects out of total 'n' objects
// nCr = n! / ((n-r)!r!) 
int nCr(int n, int r){

    int numerator = factorial(n);
    int denominator = factorial(n-r)*factorial(r);

    return numerator/denominator;
}

int main(){

    int n,r;
    cin>>n>>r;

    cout<<nCr(n,r)<<endl;

    return 0;
}