/* 처음 풀이 */
// #include <iostream>
// using namespace std;

// int main()
// {
//     int T;
//     cin >> T;
//     while (T--)
//     {
//         long long x, y;
//         cin >> x >> y;

//         long long dis = y - x;
//         long long cnt = 0, add = 0, n = 1;
//         bool first = true;
//         while (add < dis)
//         {
//             if (first)
//             {
//                 add += n;
//                 first = false;
//             }
//             else
//             {
//                 add += n;
//                 first = true;
//                 n++;
//             }
//             cnt++;
//         }
//         cout << cnt << endl;
//     }
//     return 0;
// }

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long x, y;
        cin >> x >> y;
        long long dis = y - x;
        long long n = sqrt(dis);
        if (dis == n * n)
            cout << 2 * n - 1 << endl;
        else if (dis <= n * (n + 1))
            cout << 2 * n << endl;
        else
            cout << 2 * n + 1 << endl;
    }
    return 0;
}
