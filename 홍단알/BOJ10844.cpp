/*
	BOJ10844
	<쉬운 계단 수>
	문제
	45656이란 수를 보자.

이 수는 인접한 모든 자리의 차이가 1이다. 이런 수를 계단 수라고 한다.

N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구해보자. 0으로 시작하는 수는 계단수가 아니다.
*/

#include <iostream>
using namespace std;

#define mod 1000000000
int d[101][10];
int n;
long long ans=0;

void dp() {
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j <= 9; ++j) {
			if (j == 0)
				d[i][j] = d[i - 1][j + 1]%mod;
			else if (j == 9)
				d[i][j] = d[i - 1][j - 1] % mod;
			else
				d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % mod;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= 9; ++i) d[1][i] = 1;
	dp();
	for (int i = 0; i <= 9; ++i)
		ans += d[n][i];

	cout << ans % mod;
	return 0;
}
