#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

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

    return 0;
}