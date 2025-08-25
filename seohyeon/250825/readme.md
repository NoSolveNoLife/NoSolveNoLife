# 문제 풀이

## 백준 7576번: 회전 초밥

[문제 링크](https://www.acmicpc.net/problem/2531)

```c++
int cnt[3001] = {0}; // 현재 k개 중에서 초밥 개수
int distinct = 0;    // 현재 k개 중에서 서로 다른 초밥 종류 수

for (int i = 0; i < k; ++i)
{
    if (cnt[sushi[i]]++ == 0)
        distinct++;
}

int answer = distinct + (cnt[c] == 0 ? 1 : 0);

for (int i = 1; i < N; i++)
{
    int out = sushi[(i - 1) % N];
    if (--cnt[out] == 0)
        distinct--;

    int in = sushi[(i + k - 1) % N];
    if (cnt[in]++ == 0)
        distinct++;

    answer = max(answer, distinct + (cnt[c] == 0 ? 1 : 0));
}

cout << answer;
```

연속된 k개 구간을 한 칸씩 옮기면서, 각 구간에서 서로 다른 초밥의 개수를 갱신했습니다. 이때 쿠폰 번호 c가 포함되지 않았다면 1을 더해 가능한 최대 종류 수를 기록했습니다. 벨트가 원형이므로 인덱스를 옮길 때는 나머지 연산을 사용해 끝에서 다시 앞으로 이어지도록 처리했습니다.

---

## 백준 14500번: 테트로미노

[문제 링크](https://www.acmicpc.net/problem/14500)

```c++

```

---

## 백준 1931번: 회의실 배정

[문제 링크](https://www.acmicpc.net/problem/1931)

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> meetings(N);
    for (int i = 0; i < N; i++)
    { // first = 끝나는 시간, second = 시작 시간
        cin >> meetings[i].second >> meetings[i].first;
    }

    sort(meetings.begin(), meetings.end());

    int cnt = 0;      // 선택한 회의 개수
    int last_end = 0; // 마지막으로 선택한 회의 끝나는 시간

    for (auto [end, start] : meetings)
    {
        if (start >= last_end)
        {
            cnt++;
            last_end = end;
        }
    }

    cout << cnt;

    return 0;
}
```

sort 함수가 first -> second 순으로 오름차순 정렬하기 때문에, 끝나는 시간을 first, 시작 시간을 second로 두었습니다. 정렬 후에는 순서대로 확인하면서 이전 회의가 끝난 이후에 시작하는 회의만 선택했습니다.

---

## 백준 5052번: 전화번호 목록

[문제 링크](https://www.acmicpc.net/problem/5052)

```c++
while (t--)
{
    int n;
    cin >> n;

    vector<string> phone(n);
    for (int i = 0; i < n; i++)
    {
        cin >> phone[i];
    }
    sort(phone.begin(), phone.end());

    bool same = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (phone[i + 1].find(phone[i]) == 0)
        {
            same = true;
            break;
        }
    }
    cout << (same ? "NO\n" : "YES\n");
}
```

전화번호를 문자열로 입력받아 사전순으로 정렬했습니다.
정렬하면 접두어 관계가 있으면 반드시 인접한 두 문자열에서만 나타나므로, 앞뒤만 비교했습니다. 어떤 번호가 다음 번호의 접두어라면 NO, 그렇지 않으면 YES를 출력했습니다.
