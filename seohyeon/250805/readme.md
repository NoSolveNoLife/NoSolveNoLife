# 문제 풀이

## 백준 1325번: 효율적인 해킹

[문제 링크](https://www.acmicpc.net/problem/1325)

```c++
vector<vector<int>> graph;
vector<int> cnt;
vector<bool> visited;

int dfs(int i)
{
    visited[i] = true;
    int count = 1;
    for (auto g : graph[i])
    {
        if (!visited[g])
            count += dfs(g);
    }
    return count;
}

int main()
{
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    cnt.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }

    int max = 0;
    for (int i = 1; i <= n; i++)
    {
        visited.assign(n + 1, false);
        cnt[i] = dfs(i);
        if (max < cnt[i])
            max = cnt[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (max == cnt[i])
            cout << i << " ";
    }
    return 0;
}
```

처음에는 dfs/bfs 문제인 줄 모르고 헤매다가 저번주에 푼 문제와 비슷한 문제라는 것을 깨닫고 dfs/bfs 중 dfs를 선택하여 구현했습니다.

---

## 백준 1932번: 정수 삼각형

[문제 링크](https://www.acmicpc.net/problem/1932)

```c++
int main()
{
    int n;
    cin >> n;

    vector<vector<int>> lines(n);
    for (int i = 0; i < n; i++)
    {
        lines[i].resize(i + 1);
        for (int j = 0; j <= i; j++)
        {
            cin >> lines[i][j];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < i + 1; j++)
        {
            lines[i][j] += max(lines[i + 1][j], lines[i + 1][j + 1]);
        }
    }

    cout << lines[0][0];

    return 0;
}
```

처음에는 삼각형의 맨 위부터 시작해서 아래로 내려가면서 max를 구했는데, 이 방식은 중복 계산이 많아 시간 초과가 발생했습니다. 그래서 삼각형의 맨 아래 줄부터 갚을 덮어쓰는 방식으로 풀이를 바꿔서 풀었습니다.

---

## 백준 1011번: Fly me to the Alpha Centauri

[문제 링크](https://www.acmicpc.net/problem/1011)

### 첫 번쨰 풀이

```c++
long long dis = y - x;
long long cnt = 0, add = 0, n = 1;
bool first = true;
while (add < dis)
{
    if (first)
    {
        add += n;
        first = false;
    }
    else
    {
        add += n;
        first = true;
        n++;
    }
    cnt++;
}
cout << cnt << endl;
```

### 두 번쨰 풀이

```c++
long long x, y;
cin >> x >> y;
long long dis = y - x;
long long n = sqrt(dis);
if (dis == n * n)
    cout << 2 * n - 1 << endl;
else if (dis <= n * (n + 1))
    cout << 2 * n << endl;
else
    cout << 2 * n + 1 << endl;
```

처음에는 하나씩 누적하여 더하는 방식으로 풀었습니다. 시간초과가 날 줄 알았는데 나지 않아서 당황했지만 효율적인 풀이가 있을 것 같아 다른 풀이를 참고하여 수학적인 방법으로 다시 풀어봤습니다. 실제로 백준에 제출했을 때 첫 번째 풀이는 4ms가 나오고 두 번째 풀이는 0ms가 나왔습니다.

---

## 백준 1904번: 01타일

[문제 링크](https://www.acmicpc.net/problem/1904)

```c++
if (n == 1)
{
    cout << 1;
    return 0;
}
else if (n == 2)
{
    cout << 2;
    return 0;
}

int prev2 = 1, prev1 = 2;
int cur;
for (int i = 3; i <= n; i++)
{
    cur = (prev2 + prev1) % 15746;
    prev2 = prev1;
    prev1 = cur;
}
cout << cur;
```

처음에는 수를 다 더한 뒤에 나머지연산을 적용했는데, 이 방법은 값이 범위를 초과해 오답이 발생했습니다. 피보나치 수열은 값이 지수적으로 커진다는 사실을 깨닫고 계산 과정 중에 나머지 연산을 하는 방식으로 수정했습니다. 문제에 주어진 조건은 괜히 있는 것이 아니라, 모두 풀이 과정에서 중요한 역할을 한다는 것을 알게 되었습니다.