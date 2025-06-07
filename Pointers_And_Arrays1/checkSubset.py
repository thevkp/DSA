t = int(input())
while t:
    n1 = int(input())
    A = set(map(int, input().split()))
    n2 = int(input())
    B = set(map(int, input().split()))
    
    
    if(A.issubset(B)):
        print("True")
    else:
        print("False")
    t -= 1
    
    
    
# 3
# 5
# 1 2 3 5 6
# 9
# 9 8 5 6 3 2 1 4 7
# 1
# 2
# 5
# 3 6 5 4 1
# 7
# 1 2 3 5 6 8 9
# 3
# 9 8 2