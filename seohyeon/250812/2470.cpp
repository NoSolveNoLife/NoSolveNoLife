#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    sort(s.begin(), s.end());

    int left = 0, right = n - 1;
    long long min = s[left] + s[right];
    int l = left, r = right;
    while (left < right)
    {
        long long add = s[left] + s[right];
        if (abs(add) < abs(min))
        {
            min = add;
            l = left;
            r = right;
        }
        if (add > 0)
        {
            right--;
        }
        else if (add < 0)
        {
            left++;
        }
        else
        {
            cout << s[left] << ' ' << s[right];
            return 0;
        }
    }
    cout << s[l] << ' ' << s[r];

    return 0;
}