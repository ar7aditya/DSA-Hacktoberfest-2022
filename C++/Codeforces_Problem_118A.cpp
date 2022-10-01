// Question : https://codeforces.com/contest/118/problem/A
#include <bits/stdc++.h>
#define str string
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define len(s) s.length()
using namespace std;
string lowercase(string &s){ // creating a function to convert all uppercase to lowercase
    ll l=s.size();
    for(ll i=0;i<l;i++){
        for(ll c=65;c<=90;c++){ // capital
            if(s[i] == c){
                int z=(int)s[i]+32;
                s[i]=(char)z;
            }
        }
    }
    return s;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    str in;
    cin>>in;
    in=lowercase(in); // converts the input string to lowercase
    // vowels={'a','e','i','o','u','y'};
    vector<pair<char,char>>vp; // creating a vector of pair of characters
    for(ll i=0;i<len(in);i++){
            if(in[i]!='a' && in[i]!='e' && in[i]!='i' && in[i]!='o' && in[i]!='u' && in[i]!='y'){ // the if condition stores all non vowels to the container (which is equivalent of deleting all the vowels)
                vp.pb(mp('.',in[i])); // now all characters are consonants, and so we need to store it paired with a '.' character in a vector conatiner
            }
    }
    // now the vector container has our required string stored in the form of pairs
    for(auto it=vp.begin();it!=vp.end();it++){
        cout<<(*it).F<<(*it).S; // printing the string
    }
    return 0;
}