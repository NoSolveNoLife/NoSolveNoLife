#include <iostream>
using namespace std;

int main()
{
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

    return 0;
}
