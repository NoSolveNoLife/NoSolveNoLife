#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> p(N);
    for (int i = 0; i < N; i++)
    {
        cin >> p[i];
    }
    sort(p.begin(), p.end());

    int add = 0;    // 누적 대기 시간
    int result = 0; // 총 대기 시간
    for (int i = 0; i < N; i++)
    {
        add += p[i];
        result += add;
    }
    cout << result << endl;
    return 0;
}
