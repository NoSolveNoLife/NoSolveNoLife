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