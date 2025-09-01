#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int a, b, c;
    cin >> a >> b >> c;

    int prevMinA = a, prevMinB = b, prevMinC = c;
    int prevMaxA = a, prevMaxB = b, prevMaxC = c;

    while (--N)
    {
        cin >> a >> b >> c;
        int MaxA = a + max(prevMaxA, prevMaxB);
        int MinA = a + min(prevMinA, prevMinB);

        int MaxB = b + max({prevMaxA, prevMaxB, prevMaxC});
        int MinB = b + min({prevMinA, prevMinB, prevMinC});

        int MaxC = c + max(prevMaxB, prevMaxC);
        int MinC = c + min(prevMinB, prevMinC);

        prevMaxA = MaxA;
        prevMaxB = MaxB;
        prevMaxC = MaxC;
        prevMinA = MinA;
        prevMinB = MinB;
        prevMinC = MinC;
    }

    cout << max({prevMaxA, prevMaxB, prevMaxC}) << " " << min({prevMinA, prevMinB, prevMinC});

    return 0;
}