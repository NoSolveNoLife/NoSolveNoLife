# 문제 풀이

## 백준 7576번: 토마토

[문제 링크](https://www.acmicpc.net/problem/7576)

```c++
int box[1000][1000];

int main()
{
    int m, n;
    cin >> m >> n;

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> box[i][j];
            if (box[i][j] == 1)
                q.push({i, j});
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (box[nx][ny] == 0)
            {
                box[nx][ny] = box[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    int days = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (box[i][j] == 0)
            {
                cout << -1;
                return 0;
            }
            days = max(days, box[i][j]);
        }
    }
    cout << days - 1;

    return 0;
}
```

이 문제는 bfs를 이용하여 풀었습니다. 처음부터 익어 있는 토마토의 좌표를 큐에 모두 넣고, 상하좌우로 인접한 안 익은 토마토(0)를 발견하면 현재 날짜 + 1로 갱신하여 큐에 추가했습니다. 스택이 빌 때까지 반복한 후, 안 익은 토마토가 있으면 -1을 출력하고, 모든 토마토가 익었다면 최댓값 - 1을 출력했습니다.
처음에 box[1000][1000]를 main 함수 내부에 두어 스택 오버플로우가 나서 출력이 안 됐고, 전역으로 옮기니 정상적으로 동작했습니다.

---

## 백준 2470번: 두 용액

[문제 링크](https://www.acmicpc.net/problem/2470)

```c++
int n;
cin >> n;
vector<long long> s(n);
for (int i = 0; i < n; i++)
{
    cin >> s[i];
}
sort(s.begin(), s.end());

int left = 0, right = n - 1;
long long min = s[left] + s[right];
int l = left, r = right;
while (left < right)
{
    long long add = s[left] + s[right];
    if (abs(add) < abs(min))
    {
        min = add;
        l = left;
        r = right;
    }
    if (add > 0)
    {
        right--;
    }
    else if (add < 0)
    {
        left++;
    }
    else{
        cout << s[left] << ' ' << s[right];
        return 0;
    }
}
cout << s[l] << ' ' << s[r];
```

투 포인트를 사용하여 합이 양수면 right을 줄이고, 음수면 left를 늘려서 구했습니다. 0에 가까운 수를 구하기 위해 abs를 사용했고 합이 0이 되면 바로 출력하고 종료하도록 했습니다.

---

## 백준 2225번: 합분해

[문제 링크](https://www.acmicpc.net/problem/2225)

```c++
int n, k;
cin >> n >> k;

long long dp[201][201] = {0}; // dp[k][n]
for (int i = 1; i <= k; i++)
{
    dp[i][1] = i; // i개로 1 만드는 경우의 수 = i
}
for (int j = 0; j <= n; j++)
{
    dp[1][j] = 1; // 1개로 j 만드는 경우의 수 = 1
}

for (int i = 2; i <= k; i++)
{
    for (int j = 2; j <= n; j++)
    {
        dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
    }
}
cout << dp[k][n];
```

dp[k][n]를 0부터 n까지의 정수를 k개 더해 n을 만드는 경우의 수로 정의하였고, 구할 때마다 10^9으로 나머지 연산을 적용했습니다.

---

## 백준 14502번: 연구소

[문제 링크](https://www.acmicpc.net/problem/14502)

```c++

```
