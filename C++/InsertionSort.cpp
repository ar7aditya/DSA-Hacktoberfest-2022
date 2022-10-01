#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<int> L;

    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        L.push_back(x);
    }

    for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            if(L[j]<L[j-1]){
                int temp = L[j-1];
                L[j-1] = L[j];
                L[j] = temp;
            }
            else{
                break;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout << L[i] << " ";
    }
    cout << endl;

}