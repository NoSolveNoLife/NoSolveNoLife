n = int(input())
arr = list(map(int, input().split()))
x = int(input())

arr.sort()
count = 0
l, r = 0, n - 1

while l < r:
    current_sum = arr[l] + arr[r]
    if current_sum == x:
        count += 1
        l += 1
        r -= 1
    elif current_sum < x:
        l += 1
    else:
        r -= 1

print(count)
