/*
	BOJ11052
	<카드 구매하기>
	문제
	길어서 링크로 대신
	https://www.acmicpc.net/problem/11052
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;
	vector <int> v(n+1);
	for (int i = 1; i <= n; ++i) 
		cin >> v[i];

	vector <int> dp(n+1);
	dp[0] = 0; v[0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			dp[i] = max(dp[i], dp[i - j] + v[j]);
		}
	}

	cout << dp[n];
	return 0;
}
