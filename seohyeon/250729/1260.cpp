#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> dfsOrder, bfsOrder;

void dfs(int v)
{
    visited[v] = true;
    dfsOrder.push_back(v);

    for (auto g : graph[v])
    {
        if (!visited[g])
            dfs(g);
    }
}

void bfs(int v)
{
    queue<int> q;
    visited[v] = true;
    q.push(v);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        bfsOrder.push_back(cur);

        for (auto g : graph[cur])
        {
            if (!visited[g])
            {
                visited[g] = true;
                q.push(g);
            }
        }
    }
}

int main()
{
    cin >> N >> M >> V;

    graph.resize(N + 1);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
        sort(graph[i].begin(), graph[i].end());

    visited.assign(N + 1, false);
    dfs(V);

    visited.assign(N + 1, false);
    bfs(V);

    for (auto d : dfsOrder)
        cout << d << ' ';
    cout << endl;
    for (auto b : bfsOrder)
        cout << b << ' ';
    return 0;
}