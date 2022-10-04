//Link to the question -> http://www.usaco.org/index.php?page=viewproblem2&cpid=783

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define endl '\n'
#define ll long long

int main() {

  freopen("billboard.in", "r", stdin);
  freopen("billboard.out", "w", stdout);  
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;

  int p1,q1,p2,q2;
  cin>>p1>>q1>>p2>>q2;

  int m1,n1,m2,n2;
  cin>>m1>>n1>>m2>>n2;

  int totalAreab1 = (x2-x1)*(y2-y1);
  int totalAreab2 = (p2-p1)*(q2-q1);

  int intersectionb1 = max(min(x2,m2)-max(x1,m1),0) * max(min(y2,n2)-max(y1,n1),0);
  int intersectionb2 = max(min(p2,m2)-max(p1,m1),0) * max(min(q2,n2)-max(q1,n1),0);

  int areaVisible = (totalAreab1 - intersectionb1) + (totalAreab2 - intersectionb2);

  cout<<areaVisible<<endl;

  return 0;
}
