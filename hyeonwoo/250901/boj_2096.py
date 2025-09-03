# 내려가기

N = int(input())

max_arr = [0] * 3
min_arr = [0] * 3

max_tmp = [0] * 3
min_tmp = [0] * 3

for i in range(N):
    a, b, c = map(int, input().split())

    min_tmp[0] = min(min_arr[0], min_arr[1]) + a
    max_tmp[0] = max(max_arr[0], max_arr[1]) + a

    min_tmp[1] = min(min_arr[0], min_arr[1], min_arr[2]) + b
    max_tmp[1] = max(max_arr[0], max_arr[1], max_arr[2]) + b

    min_tmp[2] = min(min_arr[1], min_arr[2]) + c
    max_tmp[2] = max(max_arr[1], max_arr[2]) + c

    for j in range(3):
        max_arr[j] = max_tmp[j]
        min_arr[j] = min_tmp[j]

print(max(max_arr), min(min_arr))