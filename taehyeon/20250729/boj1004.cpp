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

