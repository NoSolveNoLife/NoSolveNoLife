# 전화번호 목록

import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    nums = [input().strip() for _ in range(n)]
    nums.sort()

    ok = True
    for a, b in zip(nums, nums[1:]):
        if b.startswith(a):
            ok = False
            break

    print("YES" if ok else "NO")
