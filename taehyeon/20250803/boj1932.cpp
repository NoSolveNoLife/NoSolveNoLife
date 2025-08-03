
#include<iostream>
#include<algorithm>
using namespace std;

int n;
int tri[501][501];

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <=i ; j++)
		{
			cin >> tri[i][j];
		}
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			tri[i][j] = max(tri[i][j] + tri[i - 1][j], tri[i][j] + tri[i - 1][j - 1]);
		}
	}

	sort(tri[n] + 1, tri[n] + 1 + n, greater<int>());
	cout << tri[n][1];
}