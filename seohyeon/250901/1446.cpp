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
