t= int(input())  # 테스트 케이스 개수

for _ in range(t):
    x1, y1, x2, y2 = map(int, input().split())  # 출발점, 도착점
    n = int(input())  # 행성계 수
    count = 0

    for _ in range(n):
        cx, cy, r = map(int, input().split())
        
        # 출발점과 도착점이 원의 내부에 있는지 확인
        start_in = (x1 - cx) ** 2 + (y1 - cy) ** 2 < r ** 2
        end_in = (x2 - cx) ** 2 + (y2 - cy) ** 2 < r ** 2

        # 한 점만 내부에 있으면 횟수 +1
        if start_in != end_in:
            count += 1

    print(count)
