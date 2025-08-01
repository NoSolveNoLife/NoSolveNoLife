
# 문제풀이
## ATM

https://www.acmicpc.net/problem/11399
 ```c++
#include<iostream>
#include<algorithm>

using namespace std;
int n;
vector<int> arr;
int temp;
int res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++){
        res += (n - i) * arr[i];
    }

    cout << res;
}
 ```
정렬문제로 가장 대기 시간이 적은 사람을 앞으로 배치했을 떄 전체 대기시간이 최소가 됩니다.


## 두 수의 합
https://www.acmicpc.net/problem/3273
```c++
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> arr;
int cal;
int x;
int res;
int temp;

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> temp;
        arr.push_back(temp);
    } 

    cin >> x;

    sort(arr.begin(), arr.end());

    int start = 0;
    int end = n -1;

    while(start != end){

        if(start >= n || end <= 0) break;
        cal = arr[start] + arr[end];

        if( cal> x){
            end --;
            continue;
        }

        if(cal< x){
            start ++;
            continue;

        }

        if(cal== x){
            res++;
            ++start;
        }
    }

    cout << res;

}
```
투 포인터 문제로 정렬한 후 합이 클 경우 포인터를 감소 시키고 합이 작을 경우 포인터를 증가 시키는 방식으로 해결합니다.



## 어린 왕자


https://www.acmicpc.net/problem/2841
```c++
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int t;
int n;
pair<int, int> s;
pair<int, int> e;
int cx, cy, r;
int diffsx, diffsy, diffex, diffey;
int rad;
bool sins ,eins;
int res;

int main(){
    cin >> t;

    while(t--){
        res = 0;
        cin >> s.first;
        cin >> s.second;
        cin >> e.first;
        cin >> e.second;

        cin >> n;

        for (int i = 0 ; i < n; i++){
            cin >> cx >> cy >> r;
            rad = r*r;
            diffsx = abs(s.first - cx);
            diffsy = abs(s.second - cy);
            
            diffex = abs(e.first - cx);
            diffey = abs(e.second - cy);

            sins = (diffsx * diffsx +  diffsy * diffsy) < rad ? true : false;
            eins = (diffex * diffex +  diffey * diffey) < rad ? true : false;
            
            if(sins && eins){  // 시작점과 도착점이 모두 원 안에 있을 경우
                continue;      // 카운트 하지 않는다.
            }

            if(sins) ++ res;
            if(eins) ++ res;
        }

        cout << res << "\n";
    }

}


```
시작 점과 끝 점이 한 원안에 있을 때는 카운트 하지 않는게 중요했던 것 같습니다. 개인적으로는 난이도에 비해 어려울 수 있는 문제인 것 같습니다.

##  DFS와 BFS

https://www.acmicpc.net/problem/1260
```c++
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, m, v;
vector<int> vec[1001];
int visit[1001];
queue<pair<int, int>> q;


void dfs(int x) {
	visit[x] = true;

	sort(vec[x].begin(), vec[x].end());
	cout << x<<" ";
	for (int i = 0; i < vec[x].size(); i++) {
		if (!visit[vec[x][i]]) {
			visit[vec[x][i]] = true;
			dfs(vec[x][i]);
		}
	}

}

void bfs(int x) {
	visit[x] = true;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int xx = q.front();
		q.pop();
		cout << xx << " ";
		for (int i = 0; i < vec[xx].size(); i++) {
			if (!visit[vec[xx][i]]) {
				visit[vec[xx][i]] = true;
				q.push(vec[xx][i]);
			}
		}
	}

}

int main() {
	cin >> n >> m >> v;
	int num1, num2;

	for (int i = 0; i < m; i++) {
		cin >> num1 >> num2;
		vec[num1].push_back(num2);
		vec[num2].push_back(num1);
	}
	
	dfs(v);

	memset(visit, NULL,sizeof(visit));
	cout << endl;
	bfs(v);
}
```
오랜만에 DFS와 BFS 개념을 만날 수 있어 좋았습니다 :D


