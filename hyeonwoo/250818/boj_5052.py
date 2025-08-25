# 전화번호 목록

t = int(input())

results = []

for _ in range(t):
    n = int(input())

    numbers = []
    for _ in range(n):
        numbers.append(input())
    numbers.sort()

    for i in range(n-1):
        if numbers[i] == numbers[i+1][:len(numbers[i])]:
            results.append("NO")
            break
    else:
        results.append("YES")

for result in results:
    print(result)