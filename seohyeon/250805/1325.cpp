#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<int> cnt;
vector<bool> visited;

int dfs(int i)
{
    visited[i] = true;
    int count = 1;
    for (auto g : graph[i])
    {
        if (!visited[g])
            count += dfs(g);
    }
    return count;
}

int main()
{
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    cnt.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }

    int max = 0;
    for (int i = 1; i <= n; i++)
    {
        visited.assign(n + 1, false);
        cnt[i] = dfs(i);
        if (max < cnt[i])
            max = cnt[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (max == cnt[i])
            cout << i << " ";
    }
    return 0;
}