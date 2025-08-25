#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, d, k, c;
    cin >> N >> d >> k >> c;

    int sushi[30000];
    for (int i = 0; i < N; ++i)
        cin >> sushi[i];

    int cnt[3001] = {0}; // 초밥 개수
    int distinct = 0;    // 서로 다른 초밥 종류 수

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
    return 0;
}