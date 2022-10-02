"""
Multiplication of 2 - matrices

Sample I/O:

"""

r1,c1 = map(int,input("Enter the dimensions of Matrix 1(separated by a space): ").split())
print("Enter the elements of Matrix 1")
m1 = [list(map(int,input().split())) for i in range(r1)]
r2,c2 = map(int,input("Enter the dimensions of Matrix 2(separated by a space): ").split())
print("Enter the elements of Matrix 2")
m2 = [list(map(int,input().split())) for i in range(r2)]

# Creating new matrix for final matrix
m3 = [([0]*c2) for i in range(r1)]

# Checking whether matrix m1 can be multiplied with matrix m2
if c1 != r1:
    print("Matrices cannot be multiplied")
else:
    # Multiplication process
    # iterating by row of Matrix m1
    for i in range(r1):
        # iterating by column of Matrix m2
        for j in range(c2):
            # iterating by row of Matrix m2
            for k in range(r2):
                m3[i][j] += m1[i][k] * m2[k][j]
            

# printing the resultant matrix
print("Multiplication of Matrix 1 and Matrix 2 is: ")
for row in m3:
    print(*row)