
# 문제풀이
##  Fly me to the Alpha Centauri

https://www.acmicpc.net/problem/1011
 ```c++
#include <iostream>
#include <cmath>

using namespace std;

int t;

int main() {
    cin >> t;

    while(t--){
        int start, end;
        cin >> start >> end;

        int dist = end - start;  
        int max_ = (int)sqrt(dist);  

        if (max_ == sqrt(dist)) {
            cout << max_ * 2 - 1 << "\n";
        }
        else if (dist <= max_ * max_ + max_) {
            cout << max_ * 2 << "\n";
        }
        else {
            cout << max_ * 2 + 1 << "\n";
        }
    }
}
 ```
어떻게 푸는지 몰라서 16까지 적어봤는데 패턴이 보여서 풀 수 있었습니다.


##  효율적인 해킹
https://www.acmicpc.net/problem/1325
```c++
vector<int> trust[10001];
int res[10002];
bool chk[10002];
int n, m;
int num1, num2;
int max_;

void cal(int num){
    queue<int> q;
    q.push(num);
    chk[num] = true;
    ++res[num];

    while(!q.empty()){
        int temp = q.front(); q.pop();
        int size = trust[temp].size();
        
            for(int i = 0; i < size; i++){  
            int cur = trust[temp][i];

            if(!chk[cur]){
                q.push(cur);
                chk[cur] = true;
                ++res[num];
                max_ = max(max_, res[num]);
            }
        }
    }
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        cin >> num1 >> num2;
        trust[num2].push_back(num1);
    }

    for(int i = 1 ;i <= n ;i++){
        cal(i);
        memset(chk, false, (n+1) * sizeof(bool));
    }

    for(int i = 1; i <= n ; i ++){
        if(res[i] == max_) cout << i << " ";
    }
}
```
A B이면 A가 B를 신뢰하는 거여서 B가 A를 해킹할 수 있는게 헷갈렸습니다.



## 01타일


https://www.acmicpc.net/problem/1904
```c++
int s[1000001];


int res(int num) {
	if (num == 1) {
		s[num] = 1;
		return s[num];
	}
	if (num == 2) {
		s[num] = 2;
		return s[num];
	}
	if (s[num]) {
		return s[num];
	}

	return s[num] = (res(num - 1) + res(num - 2))%15746;
}

int main() {
	int n;
	cin >> n;
	cout << res(n);
}

```
결국 피보나치처럼 되는 문제였습니다.

##  정수 삼각형

https://www.acmicpc.net/problem/1932
```c++
int n;
int tri[501][501];

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <=i ; j++)
		{
			cin >> tri[i][j];
		}
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			tri[i][j] = max(tri[i][j] + tri[i - 1][j], tri[i][j] + tri[i - 1][j - 1]);
		}
	}

	sort(tri[n] + 1, tri[n] + 1 + n, greater<int>());
	cout << tri[n][1];
}
```
삼각형이라고 생각할땐 어려웠는데 문제 테스트케이스에 힌트가 있었던 것 같습니다.
```
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
```


