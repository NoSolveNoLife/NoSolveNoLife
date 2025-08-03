#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
