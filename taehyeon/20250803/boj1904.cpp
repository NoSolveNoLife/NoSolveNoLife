#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int s[1000001];


int res(int num) {
	if (num == 1) {
		s[num] = 1;
		return s[num];
	}
	if (num == 2) {
		s[num] = 2;
		return s[num];
	}
	if (s[num]) {
		return s[num];
	}

	return s[num] = (res(num - 1) + res(num - 2))%15746;
}

int main() {
	int n;
	cin >> n;
	cout << res(n);
}