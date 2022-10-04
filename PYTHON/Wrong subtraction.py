Question: https://codeforces.com/contest/977/problem/A

q = input()
w = q.split()
a = int(w[0])
k = int(w[1])
for i in range(k):
    if a%10 == 0:
        a = a/10
    else:
        a = a - 1
print(int(a))