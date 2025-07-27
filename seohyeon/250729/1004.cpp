#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int T; // 테스트 케이스 개수
    cin >> T;

    while (T--)
    {
        int x1, y1, x2, y2; // 출발점, 도착점
        cin >> x1 >> y1 >> x2 >> y2;

        int n; // 행성계의 개수
        cin >> n;

        int start = 0; // 출발점만 포함하는 행성의 개수
        int end = 0;   // 도착점만 포함하는 행성의 개수

        for (int i = 0; i < n; i++)
        {
            int cx, cy, r;
            cin >> cx >> cy >> r;

            double d1; // 출발점-행성의 중점과의 거리
            double d2; // 도착점-행성의 중점과의 거리
            d1 = sqrt(pow(x1 - cx, 2) + pow(y1 - cy, 2));
            d2 = sqrt(pow(x2 - cx, 2) + pow(y2 - cy, 2));

            if (d1 < r && d2 > r) // 행성 안에 출발점만 포함되는 경우
                start++;
            if (d1 > r && d2 < r) // 행성 안에 도착점만 포함되는 경우
                end++;
        }
        cout << start + end << endl;
    }

    return 0;
}