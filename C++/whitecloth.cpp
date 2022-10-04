//Link to the question -> https://codeforces.com/contest/1216/problem/C 

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define endl '\n'
#define ll long long

ll zero = 0;
struct Rect
{
    ll x1;
    ll y1;
    ll x2;
    ll y2;
};

ll intersection(Rect a, Rect b)
{
    return (max(min(a.x2, b.x2) - max(a.x1, b.x1), zero) * max(min(a.y2, b.y2) - max(a.y1, b.y1), zero));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Rect white;
    cin >> white.x1 >> white.y1 >> white.x2 >> white.y2;

    Rect black1;
    cin >> black1.x1 >> black1.y1 >> black1.x2 >> black1.y2;
    Rect black2;
    cin >> black2.x1 >> black2.y1 >> black2.x2 >> black2.y2;

    ll areaWhite = (white.x2 - white.x1) * (white.y2 - white.y1);

    //Common intersection of B1 B2 and white
    ll i = (max(min(min(black1.x2,white.x2), min(black2.x2,white.x2)) - max(max(black1.x1,white.x1), max(black2.x1,white.x1)), zero) * max(min(min(black1.y2,white.y2), min(black2.y2,white.y2)) - max(max(black1.y1,white.y1), max(black2.y1,white.y1)), zero));

    ll checkArea = intersection(black1, white) + intersection(black2, white) - i;

    if (checkArea == areaWhite){
        cout << "NO";
    }else{
        cout << "YES";
    }

    return 0;
}
