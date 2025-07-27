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