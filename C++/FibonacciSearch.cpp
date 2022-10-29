#include<iostream>
using namespace std;
void FibonacciSearch(int *a, int start, int end, int *fib, int index, int item) {
   int i, mid;
   mid = start+fib[index-2];
   if(item == a[mid]) {
      cout<<"
 item found at "<<mid<<" index.";
      return;
   } else if(item == a[start]) {
      cout<<"
 item found at "<<start<<" index.";
      return;
   } else if(item == a[end]) {
      cout<<"
 item found at "<<end<<" index.";
      return;
   } else if(mid == start || mid == end) {
      cout<<"
Element not found";
      return;
   } else if(item > a[mid])
         FibonacciSearch(a, mid, end, fib, index-1, item);
      else
         FibonacciSearch(a, start, mid, fib, index-2, item);
   }
   main() {
      int n, i, fib[20], a[10]={3, 7, 55, 86, 7, 15, 26, 30, 46, 95};
      char ch;
      fib[0] = 0;
      fib[1] = 1;
      i = 1;
      while(fib[i] < 10) {
         i++;
         fib[i] = fib[i-1] + fib[i-2];
      }
      up:
         cout<<"Enter the Element to be searched: ";
         cin>>n;
         FibonacciSearch(a, 0, 9, fib, i, n);
         cout<<"\tDo you want to search more...enter choice(y/n)?";
         cin>>ch;
         if(ch == 'y' || ch == 'Y')
            goto up;
         return 0;
   }
}
