# 회의실 배정

N = int(input())

meetings = []

end = 0
max_m = 0

for _ in range(N):
    meetings.append(list(map(int, input().split())))

meetings.sort(key=lambda x: (x[1], x[0]))

for new_start, new_end in meetings:
    if end <= new_start:
        max_m += 1
        end = new_end

print(max_m)