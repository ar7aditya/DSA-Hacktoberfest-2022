Question : https://codeforces.com/contest/112/problem/A

a = input()
b = input()
if a.lower()<b.lower():
    print(-1)
elif a.lower()==b.lower():
    print(0)
else:
    print(1)