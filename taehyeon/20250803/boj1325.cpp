#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;

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

