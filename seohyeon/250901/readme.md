# 문제 풀이

## 백준 2096번: 내려가기

[문제 링크](https://www.acmicpc.net/problem/2096)

```c++
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int a, b, c;
    cin >> a >> b >> c;

    int prevMinA = a, prevMinB = b, prevMinC = c;
    int prevMaxA = a, prevMaxB = b, prevMaxC = c;

    while (--N)
    {
        cin >> a >> b >> c;
        int MaxA = a + max(prevMaxA, prevMaxB);
        int MinA = a + min(prevMinA, prevMinB);

        int MaxB = b + max({prevMaxA, prevMaxB, prevMaxC});
        int MinB = b + min({prevMinA, prevMinB, prevMinC});

        int MaxC = c + max(prevMaxB, prevMaxC);
        int MinC = c + min(prevMinB, prevMinC);

        prevMaxA = MaxA;
        prevMaxB = MaxB;
        prevMaxC = MaxC;
        prevMinA = MinA;
        prevMinB = MinB;
        prevMinC = MinC;
    }

    cout << max({prevMaxA, prevMaxB, prevMaxC}) << " " << min({prevMinA, prevMinB, prevMinC});

    return 0;
}
```

각 줄의 a, b, c 위치에서 만들 수 있는 최소/최대 합으로 정의하고, 첫 줄은 입력값 그대로 초기화했습니다.  
다음 줄부터는 a는 이전 줄 a·b, b는 a·b·c, c는 b·c 값을 참고해 최소/최대를 갱신했습니다. 모든 줄을 처리한 뒤 마지막 줄의 a, b, c 중 최댓값과 최솟값을 출력했습니다.

---

## 백준 1446번: 지름길

[문제 링크](https://www.acmicpc.net/problem/1446)

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ShortCut
{
    int start;
    int end;
    int distance;
};

int main()
{
    int N, D;
    cin >> N >> D;

    vector<ShortCut> s(N);

    for (int i = 0; i < N; i++)
    {
        cin >> s[i].start >> s[i].end >> s[i].distance;
    }

    sort(s.begin(), s.end(), [](const ShortCut &a, const ShortCut &b)
         {
        if(a.start == b.start)
            return a.end < b.end;
        return a.start < b.start; });

    vector<int> dp(D + 1, 0);
    for (int i = 0; i <= D; i++)
        dp[i] = i;

    int idx = 0;
    for (int i = 0; i <= D; i++)
    {
        if (i > 0)
            dp[i] = min(dp[i], dp[i - 1] + 1);
        while (idx < N && s[idx].start == i)
        {
            if (s[idx].end <= D)
            {
                dp[s[idx].end] = min(dp[i] + s[idx].distance, dp[s[idx].end]);
            }
            idx++;
        }
    }

    cout << dp[D];
    return 0;
}

```

dp[i]를 0에서 i까지 오는 최소 거리로 정의하고, i로 초기화했습니다. 0부터 D까지 순차적으로 진행하면서 한 칸 전진(dp[i-1]+1)과 i에서 시작하는 지름길을 모두 고려해 최소값을 갱신했습니다.

---

## 백준 14501번: 퇴사

[문제 링크](https://www.acmicpc.net/problem/14501)

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> tp(N);
    vector<int> dp(N + 1, 0);
    for (int i = 0; i < N; i++)
        cin >> tp[i].first >> tp[i].second;

    for (int i = N - 1; i >= 0; i--)
    {
        if (tp[i].first + i > N)
            dp[i] = dp[i + 1];
        else
            dp[i] = max(tp[i].second + dp[i + tp[i].first], dp[i + 1]);
    }

    cout << dp[0];
    return 0;
}
```

i번째 날부터 마지막 날까지 얻을 수 있는 최대 이익으로 dp를 정의하여 풀었습니다. 뒤에서 거꾸로 탐색하면서 상담을 하는 경우(보수 + 이후 이익)와 하지 않는 경우(내일부터의 이익)을 비교하여 더 큰 수를 dp에 넣었습니다.

---

## 백준 11047번: 동전 0

[문제 링크](https://www.acmicpc.net/problem/11047)

```c++
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    int min = 0;
    for (int i = N - 1; i >= 0;)
    {
        if (a[i] > K)
        {
            i--;
            continue;
        }
        K -= a[i];
        min++;
    }
    cout << min;
    return 0;
}
```

동전이 오름차순으로 주어지므로 뒤에서부터 동전이 K보다 크면 건너뛰고, 작거나 같으면 K에서 빼고 개수를 증가시켰습니다.
