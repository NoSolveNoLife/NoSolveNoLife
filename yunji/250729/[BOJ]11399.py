n = int(input())

times = list(map(int, input().split()))

# 오름차순 정렬 (인출 시간이 짧은 사람부터)
times.sort()

# 누적합
answer = 0
c = 0
for time in times:
    c += time
    answer += c

print(answer)
