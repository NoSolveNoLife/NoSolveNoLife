# 문제 풀이

## 백준 11399번: ATM

[문제 링크](https://www.acmicpc.net/problem/11399)

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> p(N);
    for (int i = 0; i < N; i++)
    {
        cin >> p[i];
    }
    sort(p.begin(), p.end());

    int add = 0;    // 누적 대기 시간
    int result = 0; // 총 대기 시간
    for (int i = 0; i < N; i++)
    {
        add += p[i];
        result += add;
    }
    cout << result << endl;
    return 0;
}

```

algorithm 헤더를 추가하여 sort 함수로 입력받은 값을 오름차순으로 정렬했습니다. 작은 수부터 하나씩 누적시킨 값을 더해야 하기 때문에 add 변수를 두어 result에 순차적으로 더했습니다.

---

## 백준 1004번: 어린왕자

[문제 링크](https://www.acmicpc.net/problem/1004)

```c++
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int T; // 테스트 케이스 개수
    cin >> T;

    while (T--)
    {
        int x1, y1, x2, y2; // 출발점, 도착점
        cin >> x1 >> y1 >> x2 >> y2;

        int n; // 행성계의 개수
        cin >> n;

        int start = 0; // 출발점만 포함하는 행성의 개수
        int end = 0;   // 도착점만 포함하는 행성의 개수

        for (int i = 0; i < n; i++)
        {
            int cx, cy, r;
            cin >> cx >> cy >> r;

            double d1; // 출발점-행성의 중점과의 거리
            double d2; // 도착점-행성의 중점과의 거리
            d1 = sqrt(pow(x1 - cx, 2) + pow(y1 - cy, 2));
            d2 = sqrt(pow(x2 - cx, 2) + pow(y2 - cy, 2));

            if (d1 < r && d2 > r) // 행성 안에 출발점만 포함되는 경우
                start++;
            if (d1 > r && d2 < r) // 행성 안에 도착점만 포함되는 경우
                end++;
        }
        cout << start + end << endl;
    }

    return 0;
}
```

출발점만 포함하는 행성의 개수 + 도착점만 포함하는 행성의 개수가 행성계 진입/이탈 횟수의 최솟값임을 먼저 파악했습니다. 출발점/도착점이 각각의 행성 안에 포함되는지의 여부를 판단하기 위해서 출발점/도착점-원의 중점과의 거리를 구하고 행성의 반지름과 비교했습니다. 이때 점과 점 사이의 거리를 구하기 위해 cmath 헤더를 추가하여 sqrt, pow를 사용했습니다.

---

## 백준 1260번: DFS와 BFS

[문제 링크](https://www.acmicpc.net/problem/1260)

처음에 DFS와 BFS를 직접 구현하는 데 어려움이 있어서 다른 풀이를 참고해서 풀었습니다.

```c++
int N, M, V;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> dfsOrder, bfsOrder;

int main()
{
    cin >> N >> M >> V;

    graph.resize(N + 1);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
        sort(graph[i].begin(), graph[i].end());

    visited.assign(N + 1, false);
    dfs(V);

    visited.assign(N + 1, false);
    bfs(V);

    for (auto d : dfsOrder)
        cout << d << ' ';
    cout << endl;
    for (auto b : bfsOrder)
        cout << b << ' ';
    return 0;
}
```

정점 번호가 1부터 시작하므로 graph의 크기를 N + 1로 했고, 인접 리스트 형태로 구성했습니다. 정점 번호가 작은 것을 먼저 방문해야 하기 때문에 sort 함수로 오름차순으로 정렬했습니다. visited 배열은 탐색 전에 모두 false로 초기화했습니다.

### DFS(깊이 우선 탐색)

```c++
void dfs(int v)
{
    visited[v] = true;
    dfsOrder.push_back(v);

    for (auto g : graph[v])
    {
        if (!visited[g])
            dfs(g);
    }
}
```

재귀를 이용하여 방문하지 않은 정점이면 함수를 다시 호출하는 방식으로 구현했습니다.

### BFS(너비 우선 탐색)

```c++
void bfs(int v)
{
    queue<int> q;
    visited[v] = true;
    q.push(v);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        bfsOrder.push_back(cur);

        for (auto g : graph[cur])
        {
            if (!visited[g])
            {
                visited[g] = true;
                q.push(g);
            }
        }
    }
}
```

시작 정점을 큐에 넣고 시작 정점과 연결된 모든 정점들을 방문한 후에, 큐에서 하나씩 다시 꺼내면서 큐가 공백이 될 때까지 반복하는 방식으로 구현했습니다.

---

## 백준 3273번: 두 수의 합

[문제 링크](https://www.acmicpc.net/problem/3273)

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, x, cnt = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> x;

    sort(arr.begin(), arr.end());

    int left = 0, right = n - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == x)
        {
            cnt++;
            left++;
            right--;
        }
        else if (sum < x)
            left++;
        else
            right--;
    }

    cout << cnt << endl;
    return 0;
}
```

algorithm 헤더를 추가하여 sort 함수를 통해 입력받은 수를 오름차순으로 정렬했습니다. 그리고 가장 작은 수를 left로, 가장 큰 수를 right로 놓고, 두 수의 합이 x보다 작으면 left를 증가시키고, x보다 크면 right를 감소시켰습니다. x와 같은 값일 경우 cnt를 1 증가시키고, left와 right를 한 칸씩 이동시켰습니다. 이 과정을 left가 right보다 작을 때까지만 반복했습니다.
