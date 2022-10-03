
# brute force approach:

arr = [20, 3, 4, 19, 40]
x = 19

for i in range(len(arr)):
 
    if arr[i] == x:
        print(i)
 
print('-1')



#Recursive Approach: 



def search(arr, p , x):
    if p == -1:
        return -1
    if arr[p] == x:
        return p
    return search(arr, p-1, x)

   