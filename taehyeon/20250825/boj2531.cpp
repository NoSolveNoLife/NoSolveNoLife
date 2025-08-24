#include<iostream>
#include<algorithm>

using namespace std;

int main() {

    int n, d, k, c;
    cin >> n >> d >> k >> c;

    vector<int> a(n * 2);           
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];            
    }

    vector<int> cnt(d + 1, 0);    
    int list = 0;

    for (int i = 0; i < k; ++i) {
        if (cnt[a[i]]++ == 0) ++list;
    }

    int res = list + (cnt[c] == 0 ? 1 : 0);

    for (int i = 1; i < n; ++i) {

        int left = a[i - 1];
        if (--cnt[left] == 0) --list;

        int right = a[i + k - 1];
        if (cnt[right]++ == 0) ++list;

        res = max(res, list + (cnt[c] == 0 ? 1 : 0));
    }

    cout << res;
}
