MOD = 15746
N = int(input())

if N == 1:
    print(1)
elif N == 2:
    print(2)
else:
    dp1 = 1
    dp2 = 2 
    
    for _ in range(3, N + 1):
        dp3 = (dp1 + dp2) % MOD 
        dp1 = dp2 
        dp2 = dp3

    print(dp2) 
