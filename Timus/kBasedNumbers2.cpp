n = int(input())
k = int(input())
curZero = 0
curNoZero = k - 1

for i in range(1, n):
    copyCurZero = curZero
    curZero = curNoZero
    curNoZero = (k - 1) * curNoZero + (k - 1) * copyCurZero

print(curNoZero + curZero)
