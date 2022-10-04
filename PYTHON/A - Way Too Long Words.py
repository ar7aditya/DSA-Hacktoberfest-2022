Question : https://codeforces.com/contest/71/problem/A


n = int(input())
for i in range(n):
    a = input()
    if len(a)>10:
        print(a[0],len(a)-2,a[len(a)-1],sep="")
    else:
        print(a)