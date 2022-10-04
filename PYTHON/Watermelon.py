Question: https://codeforces.com/contest/4/problem/A

a = int(input())
w = 0
if a%2 == 0:
    for i in range(a):
        if w==1:
            break
        for j in range(a):
            if i+j == a and i%2==0:
                w = 1
                break
            else:
                w = 0
        
if w==0:
    print("NO")
else:
    print("YES")