import sys

input = sys.stdin.readline

m, n = map(int, input().split())

storage = []
ripen = []

for x in range(n):
    row = list(map(int, input().split()))
    for y in range(m):
        if row[y] == 1:
            ripen.append((x, y))
    storage.append(row)

if 0 not in sum(storage, []):
    print(0)
    exit()

day = 1
dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]

while True:
    ripe = []
    for p in ripen:
        for d in dirs:
            nx, ny = p[0] + d[0], p[1] + d[1]
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
            if storage[nx][ny] == 0:
                storage[nx][ny] = 1
                ripe.append((nx, ny))
    if not ripe:
        print(-1)
        break
    ripen = ripe
    if 0 not in sum(storage, []):
        print(day)
        break
    day += 1
