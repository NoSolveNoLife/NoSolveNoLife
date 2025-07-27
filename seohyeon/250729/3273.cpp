#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, x, cnt = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> x;

    sort(arr.begin(), arr.end());

    int left = 0, right = n - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == x)
        {
            cnt++;
            left++;
            right--;
        }
        else if (sum < x)
            left++;
        else
            right--;
    }

    cout << cnt << endl;
    return 0;
}
