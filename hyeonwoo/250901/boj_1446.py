# 지름길

N, D = map(int, input().split())

shortcuts = []
for _ in range(N):
    shortcuts.append(tuple(map(int, input().split())))

dis = [i for i in range(D+1)]

for i in range(D+1):
    if i > 0:
        dis[i] = min(dis[i], dis[i-1]+1)
    for start, end, d in shortcuts:
        if i == start and end <= D and dis[i] + d < dis[end]:
            dis[end] = dis[i] + d

print(dis[D])