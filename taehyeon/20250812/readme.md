
# 문제풀이
##  토마토

https://www.acmicpc.net/problem/7576
 ```c++
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<set>
using namespace std;

int map[1001][1001];
int visit[1001][1001];
int date[1001][1001];
int N, M;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int temp = 0;
queue <pair<int, int>>q;
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		visit[x][y] = true;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx > 0 && xx <= N && yy>0 && yy <= M && map[xx][yy] == 0 &&!visit[xx][yy]) {
				q.push({ xx,yy });
				visit[xx][yy]=true;
				date[xx][yy] = date[x][y] + 1;
				}

			}
		}


	}


int rescal() {
	int res = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (!visit[i][j]) return -1;
			res = max(res, date[i][j]);
		}
	}
	return res;
}

int main() {
	cin >> M >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == -1) {
				visit[i][j] = true;
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (map[i][j] == 1) {
				q.push({ i,j });
			}
		}
	}
	bfs();
	cout << rescal();
}
 ```
BFS로 색칠하는 느낌으로 풀었습니다. 색칠하는데 가장 오래 걸린 칸을 return

##  두 용액
https://www.acmicpc.net/problem/2225
```c++
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0x7f7f7f7f;
using namespace std;

pair<int,int> res;
int n;

int main() {
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end()); 

    int start = 0; 
    int end = n - 1; 
    int min = INF; 
    while (start < end) {
        int sum = arr[start] + arr[end];

        if (min > abs(sum)) {
            min = abs(sum);
            res.first = arr[start];
            res.second = arr[end]; 

            if (sum == 0)
                break;
        }

        if (sum < 0) 
            start++;
        else 
            end--;
    }

    cout << res.first << " " << res.second;
}
```
절댓값의 크기로 비교하여 가장 가까운 값을 찾았습니다.



## 합분해


https://www.acmicpc.net/problem/2225
```c++
┌─────┬───────┬───────┬───────┬───────┐
│     │ K = 1 │ K = 2 │ K = 3 │ K = 4 │
├─────┼───────┼───────┼───────┼───────┤
│ N=1 │   1   │   2   │   3   │   4   │
│ N=2 │   1   │   3   │   6   │  10   │
│ N=3 │   1   │   4   │  10   │  20   │
│ N=4 │   1   │   5   │  15   │  35   │
└─────┴───────┴───────┴───────┴───────┘



┌─────┬───────┬───────┬───────┬───────┐
│     │ K = 1 │ K = 2 │ K = 3 │ K = 4 │
├─────┼───────┼───────┼───────┼───────┤
│ N=1 │   1   │   2   │   3   │   4   │
│     │       │   ↓   │   ↓   │   ↓   │
│ N=2 │  1 →  │  3 →  │  6 →  │  10   │
│     │       │   ↓   │   ↓   │   ↓   │
│ N=3 │  1 →  │  4 →  │ 10 →  │  20   │
│     │       │   ↓   │   ↓   │   ↓   │
│ N=4 │  1 →  │  5 →  │ 15 →  │  35   │
└─────┴───────┴───────┴───────┴───────┘
```
n과 k는 **(n-1, k)일 때의 방법과 (n, k-1)일 때의 방법의 합**

##  정수 삼각형

https://www.acmicpc.net/problem/14502
```c++
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
int N, M;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int map[9][9];
int save[9][9];
int res = 0;
int cnt = 0;
void bfs() {
	cnt = 0;
	queue<pair<int, int>> q;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (save[i][j] == 2) {
				q.push({ i,j });
			}
		}
	}
	while (!q.empty()) {		
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx > 0 && yy > 0 && xx <= N && yy <= M && !save[xx][yy]) {
				q.push({ xx,yy });
				save[xx][yy] = 2;
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (!save[i][j]) {
				cnt++;
			}
		}
	}
	res = max(res, cnt);
}

void makewall(int w) {
	if (w == 3) {
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				save[i][j] = map[i][j];
			}
		}
		bfs();
		return ;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (!map[i][j]) {
				map[i][j] = 1;
				makewall(w + 1);
				map[i][j] = 0;
			}

		}
	}
}


int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
		}
	}
	makewall(0);

	cout << res;

}
```
3개의 벽을 만드는 모든 경우의 수를 계산 + BFS로 풀 수 있었습니다.

