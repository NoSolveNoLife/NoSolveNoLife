#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    int min = 0;
    for (int i = N - 1; i >= 0;)
    {
        if (a[i] > K)
        {
            i--;
            continue;
        }
        K -= a[i];
        min++;
    }
    cout << min;
    return 0;
}