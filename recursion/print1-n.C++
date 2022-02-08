#include<iostream>
using namespace std;

void print(int n)
{
   if(n ==1) {       // base condition
       cout<<n<<endl;
       return ;
   }
   print(n-1);    // induction 
   cout<<n<<endl; //hypothesis
}

int main()
{
  int n;
  cin>>n;
  print(n);
}