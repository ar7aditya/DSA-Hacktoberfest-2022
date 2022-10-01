/* 
Program in C++ to calculate the square root of a number.
This code is divided into two parts. In first part, 
we find the integral part of the required number 
using  binary search algorithm and then we add 
the decimal digits by adding factor(discussed in the code below)
to the number till we find our solution.
*/

#include<iostream>
#define ll long long 
using namespace std;

double morePrecise(int n,int precision,int tempSol){ // adds decimal digits to the number
    double fact = 1;
    double ans = tempSol;
    for(int i = 0;i<precision;i++){ // iteration runs depending upon how precise the output is required
        fact/=10;// dividing the factor by 10 per iteration
        for(double j = ans;(j*j)<=n;j+=fact){
            ans = j;
        }
    }
    return ans;
}

ll int sqrtInt(ll int n){ // binary search function 
    ll int s = 0;
    ll int e = n;
    ll int mid = s + (e-s)/2;
    ll int ans = -1;
    while(s<=e){
        ll int sq = (mid*mid);
        if(sq == n){
            return mid;
        }
        else if(sq<n){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

//Driver code
int main(){
    int n;
    cout<<"Enter any number : \n";
    cin>>n;
    int tempsol = sqrtInt(n);
    cout<<"Answer is : "<<morePrecise(n,4,tempsol)<<endl; // by default the precision is set to 4.
    return 0;
}