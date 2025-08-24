#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int t;
int n;
string str;
bool flag;

int main(){
    cin >> t;

    while(t--){
        flag = false;
        vector<string> arr;
        cin >> n;

        for(int i = 0; i < n; i++){
            cin >> str;
            arr.push_back(str);
        }

        sort(arr.begin(), arr.end());

        for(int i = 0; i < n-1; i++){     

            if(arr[i].size() > arr[i+1].size()) continue;
            if(arr[i + 1].substr(0, arr[i].size()) == arr[i]){
                flag = true;
                break;
            }
        }
        if(flag) cout << "NO\n"; else cout <<"YES\n";
    }

}