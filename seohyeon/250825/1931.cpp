#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> meetings(N);
    for (int i = 0; i < N; i++)
    { // first = 끝나는 시간, second = 시작 시간
        cin >> meetings[i].second >> meetings[i].first;
    }

    sort(meetings.begin(), meetings.end());

    int cnt = 0;      // 선택한 회의 개수
    int last_end = 0; // 마지막으로 선택한 회의 끝나는 시간

    for (auto [end, start] : meetings)
    {
        if (start >= last_end)
        {
            cnt++;
            last_end = end;
        }
    }

    cout << cnt;

    return 0;
}