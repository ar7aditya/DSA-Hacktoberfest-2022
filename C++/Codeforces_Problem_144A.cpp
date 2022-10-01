// Question : https://codeforces.com/problemset/problem/144/A

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll height[n]; // creating an array containing heights of the soldiers
    for(ll i = 0; i < n; ++i){
        cin >> height[i];
    }
    ll min = height[0], max = height[0], min_left_index = 0, min_right_index = 0, max_left_index = 0,max_right_index = 0;
    for(ll i = 0; i < n; ++i){
        if(height[i] > max){ // for maximum height
            max_left_index = max_right_index = i;
            max = height[i];
        }
        else if(height[i] == max){ // updating the index if more than one occurence of max height
            max_right_index = i;
        }

        if(height[i] < min){ // for minimum height
            min_left_index = min_right_index = i;
            min = height[i];
        }
        else if(height[i] == min){ // updating the index if more than one occurence of min height
            min_right_index = i;
        }
    }
    // cout<<max<<" "<<max_left_index<<'\n';
    // cout<<min<<" "<<min_right_index<<'\n';
    if(max_left_index > min_right_index){
        cout << ( (n - 1) - min_right_index + max_left_index ) - 1 << '\n'; // the two soldiers cross each other, hence there
                                                                            // is need to subtract the one swap
    }
    else if(max_left_index == min_right_index){ // for the case when height of all soldiers is the same
        cout << 0 << '\n';
    }
    else{
        cout << ( (n - 1) - min_right_index + max_left_index ) << '\n';
    }
    return 0;
}