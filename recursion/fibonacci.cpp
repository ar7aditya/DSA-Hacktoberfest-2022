#include <iostream>

using namespace std;

// 1. iterative approach | Time Complexity: O(N)
int fibo1(int n){

    int a=0, b=1, c;

    for(int i=2; i<=n; i++){
        c = a+b;
        a=b;
        b=c;
    }

    return c;
}

// 2. recursive approach | Time Complexity: O(2**N)
int fibo2(int n){

    if(n<=1){
        return n;
    }

    return fibo2(n-1)+fibo2(n-2);
}

// 3. recursive approach with memoization (Dynamic Programming) | Time Complexity: O(N)
int F[1000];// global array to store each function calls
int fibo3(int n){

    if(n<=1){
        F[n]=n;
        return F[n];
    }

    if(F[n-2]==-1){
        F[n-2] = fibo3(n-2);
    }
    if(F[n-1]==-1){
        F[n-1] = fibo3(n-1);
    }

    return F[n-1]+F[n-2];
}


int main(){

    // enter nth fibonnaci number
    int n;
    cin>>n;

    cout<<fibo1(n)<<endl;
    cout<<fibo2(n)<<endl;
    cout<<fibo3(n)<<endl;
    return 0;
}