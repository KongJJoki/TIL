nN = int(input())
num = list(map(int,input().split()))
num.sort()
print(num[0], num[nN-1])