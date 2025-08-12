#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

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