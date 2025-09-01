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